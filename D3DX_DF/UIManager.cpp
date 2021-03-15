#include "UIManager.h"
#include "UIAnimation.h"
#include "GameManager.h"
#include "InputManager.h"

//생성자
UIManager::UIManager()
{

}

//소멸자
UIManager::~UIManager()
{

}

//UI초기화
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

	//플레이어 승패 여부 Texture(Red, Blue)
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
	//탄생이 완료 되면
	if (BirthComplate)
	{
		curTime += _fETime;
	}

	if (curTime > 1.0f)
	{
		if (StartCount == 0)
		{
			//카운트가 완료되면 FightStart를 true로 만든다.
			GameManager::get_Instance()->ChangeFightStart();
			curTime = 0.0f;
		}
		else
		{
			curTime = 0.0f;
			StartCount--;
		}
	}

	//게임이 끝나지 않았다면
	if (!GameManager::get_Instance()->get_IsFightEnd())
	{
		//둘중 하나라도 피가 0이하 라면..
		if (Player_Health <= 0.0f || Enemy_Health <= 0.0f)
		{
			//죽음 상태를 true로 바꾼다.
			GameManager::get_Instance()->set_IsDie(true);

			//플레이어의 HP가 0이하라면
			if (Player_Health <= 0.0f)
			{
				GameManager::get_Instance()->set_IsPlayerDie(true);
			}
			//Enemy의 HP가 0이하라면
			else if (Enemy_Health <= 0.0f)
			{
				GameManager::get_Instance()->set_IsEnemyDie(true);
			}
		}
	}
}

//UI 그리기
void UIManager::UI_Render()
{
	if (GameManager::get_Instance()->get_IsDie())
	{
		//애니메이션을 그린다.
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

		//게임 승패 그리기
		if (GameManager::get_Instance()->get_RedBlue() == WINLOSE_RED) //플레이가 이겼다면
		{
			DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tPlayerWin, 600, 350);
		}
		else if (GameManager::get_Instance()->get_RedBlue() == WINLOSE_BLUE) //Enemy가 이겻다면
		{
			DoEngine::GraphicsManager::get_Instance()->TextureRender(m_tEnemyWin, 600, 350);
		}

		//카운트 다운 그리기
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

//데미지 삽입
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

//Attack 되돌리기
void UIManager::Return_IsAttack()
{
	isAttack = true;
}

//UI 삭제
void UIManager::UI_Release()
{
	isAttack = true;
	StartCount = 3;
	curTime = 0.0f;
	Player_Health = 1.3f;
	Enemy_Health = 1.3f;
}

//캐릭터 탄생 여부
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

//캐릭터 탄생 여부 리턴
bool UIManager::get_isBirth()
{
	return BirthComplate;
}

//플레이어 생성완료
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