#include "Player.h"
#include "UIManager.h"

//������
Player::Player()
{

}

//�Ҹ���
Player::~Player()
{

}

void Player::Init(string _Tag, float _x, float _y, bool _direction)
{
	//ĳ���� �ʱ� ���� ����
	Tag			= _Tag;
	m_Pos.x		= _x;
	m_Pos.y		= _y;
	Direction	= _direction;
	Degree		= 0;

	//�÷��̾� ü��
	Player_HP = MAX_HP;

	//�÷��̾� ü��

	//�÷��̾��� ĳ���� ����
	Player_Charecter = GameManager::get_Instance()->get_PlayerSelect();
	//ĳ���� ���� �ʱ�ȭ
	Player_Charecter->Init(Tag, m_Pos.x, m_Pos.y, Direction);
}

bool Player::Input(int _state)
{
	// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
	D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));

	//���۽�, ���� ���� ĳ���� ź�� ��� ����
	if (!UIManager::get_Instance()->get_IsCharBirth(Tag))
	{
		Player_Charecter->Input(STATE_BIRTH);
	}
	else
	{
		//������
		if (_state == RIGHT)
		{
			Direction = true;
			D3DXVec2Normalize(&vec, &vec);
			m_Pos += vec * 6;
		}
		//����
		else if (_state == LEFT)
		{
			Direction = false;
			D3DXVec2Normalize(&vec, &vec);
			m_Pos -= vec * 6;
		}

		//���� ���¸� Object�� �Է�
		Player_Charecter->Input(_state);
	}

	return false;
}

void Player::Update(float _fETime)
{
	Player_Charecter->Update(_fETime, m_Pos.x, m_Pos.y, Direction);
	//���� ���� Ȯ��
	isDie = GameManager::get_Instance()->get_IsPlayerDie();

	//ĳ������ HP�� 0�̶��
	if (isDie)
	{
		Player_Charecter->Input(BICE_DIE);
	}
}

void Player::Render()
{
	Player_Charecter->Render();
}

void Player::Release()
{

}

DoEngine::Object* Player::ReturnObject()
{
	return Player_Charecter;
}