#include "UIManager.h"
#include "UIAnimation.h"
#include "GameManager.h"
#include "InputManager.h"

//������
UIManager::UIManager()
{

}

//�Ҹ���
UIManager::~UIManager()
{

}

//UI�ʱ�ȭ
void UIManager::UI_Init()
{
	isAttack		= true;
	StartCount		= 3;
	curTime			= 0.0f;
	Player_Health	= MAX_HP;
	Enemy_Health	= MAX_HP;

	PlayerBirth = false;
	EnemyBirth = false;
	BirthComplate = true;

	LPDIRECT3DTEXTURE9	tmp_Texture;

	//Player Health
	m_tPlayer_HealthBar = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\UI\\HelthBarTLE.png");
	m_tPlayer_Health = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\UI\\HelthBar.png");

	//Enemy Health
	m_tEnemy_HealthBar = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\UI\\HelthBarTLE.png");
	m_tEnemy_Health = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\UI\\HelthBar.png");

	//�÷��̾� ���� ���� Texture(Red, Blue)
	m_tPlayerWin = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\UI\\WinLose\\RedWin.png");
	m_tEnemyWin = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\UI\\WinLose\\BlueWin.png");

	//Count Number
	for (int i = 0; i < 4; i++)
	{
		wsprintf(buf, "Resource\\UI\\Number\\Num%d.png", i);
		tmp_Texture = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		m_tNumber.push_back(tmp_Texture);
	}

	//End UI
	m_UIAni = new UIAnimation;
	m_UIAni->Init();
}

//UI Update
void UIManager::UI_Update(float _fETime)
{
	//ź���� �Ϸ� �Ǹ�
	if (BirthComplate)
	{
		curTime += _fETime;
	}

	if (curTime > 1.0f)
	{
		if (StartCount == 0)
		{
			//ī��Ʈ�� �Ϸ�Ǹ� FightStart�� true�� �����.
			GameManager::get_Instance()->ChangeFightStart();
			curTime = 0.0f;
		}
		else
		{
			curTime = 0.0f;
			StartCount--;
		}
	}

	//������ ������ �ʾҴٸ�
	if (!GameManager::get_Instance()->get_IsFightEnd())
	{
		//���� �ϳ��� �ǰ� 0���� ���..
		if (Player_Health <= 0.0f || Enemy_Health <= 0.0f)
		{
			//���� ���¸� true�� �ٲ۴�.
			GameManager::get_Instance()->set_IsDie(true);

			//�÷��̾��� HP�� 0���϶��
			if (Player_Health <= 0.0f)
			{
				GameManager::get_Instance()->set_IsPlayerDie(true);
			}
			//Enemy�� HP�� 0���϶��
			else if (Enemy_Health <= 0.0f)
			{
				GameManager::get_Instance()->set_IsEnemyDie(true);
			}
		}
	}
}

//UI �׸���
void UIManager::UI_Render()
{
	if (GameManager::get_Instance()->get_IsDie())
	{
		//�ִϸ��̼��� �׸���.
		m_UIAni->Play_Animation(100.0f);
		m_UIAni->Render(0, 0, true, 0.0f, 2.0f, 2.0f);
	}
	else
	{
		//Player
		DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tPlayer_HealthBar, PLAYER_HELTH_POSX, PLAYER_HELTH_POSY, true, 1.3f, 1.6f);
		if (Player_Health >= 0.0f)
		{
			DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tPlayer_Health, PLAYER_HELTH_POSX + 50, PLAYER_HELTH_POSY, true, Player_Health, 1.6f);
		}

		//Enemy
		DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tEnemy_HealthBar, ENEMY_HELTH_POSX, ENEMY_HELTH_POSY, false, 1.3f, 1.6f);
		if (Enemy_Health >= 0.0f)
		{
			DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tEnemy_Health, ENEMY_HELTH_POSX - 50, ENEMY_HELTH_POSY, false, Enemy_Health, 1.6f);
		}

		//���� ���� �׸���
		if (GameManager::get_Instance()->get_RedBlue() == WINLOSE_RED) //�÷��̰� �̰�ٸ�
		{
			DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tPlayerWin, 600, 350);
		}
		else if (GameManager::get_Instance()->get_RedBlue() == WINLOSE_BLUE) //Enemy�� �̰�ٸ�
		{
			DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tEnemyWin, 600, 350);
		}

		//ī��Ʈ �ٿ� �׸���
		if (BirthComplate && !GameManager::get_Instance()->get_IsFightStart())
		{
			//Start Texture
			if (StartCount == 0)
			{
				DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tNumber[StartCount], 670, 350, true, 0.8f, 0.8f);
			}
			//Number Textrue
			else
			{
				DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tNumber[StartCount], 850, 350, true, 0.6f, 0.6f);
			}
		}
	}
}

//������ ����
void UIManager::set_Damege(string _Mytag, float _num)
{
	if (isAttack)
	{
		if (_Mytag == "Player")
		{
			Player_Health -= _num;
		}
		else if (_Mytag == "Enemy")
		{
			Enemy_Health -= _num;
		}
	}
	isAttack = false;
}

//Attack �ǵ�����
void UIManager::Return_IsAttack()
{
	isAttack = true;
}

//UI ����
void UIManager::UI_Release()
{
	isAttack = true;
	StartCount = 3;
	curTime = 0.0f;
	Player_Health = 1.3f;
	Enemy_Health = 1.3f;
}

//ĳ���� ź�� ����
void UIManager::set_isBirth(string _tag, bool _isBirth)
{
	if (_tag == "Player")
	{
		PlayerBirth = true;
	}
	else if (_tag == "Enemy")
	{
		EnemyBirth = true;
	}

	if (PlayerBirth && EnemyBirth)
	{
		BirthComplate = true;
	}
}

//ĳ���� ź�� ���� ����
bool UIManager::get_isBirth()
{
	return BirthComplate;
}

//�÷��̾� �����Ϸ�
bool UIManager::get_IsCharBirth(string _tag)
{
	if (_tag == "Player")
	{
		return PlayerBirth;
	}
	else if (_tag == "Enemy")
	{
		return EnemyBirth;
	}
}