#include "Xion.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "AnimationMaker.h"

Xion::Xion()
{
}


Xion::~Xion()
{
}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)
void Xion::Init(string _Tag, float _x, float _y, bool _direction)
{
	m_FSM = new XionFSM();
	Direction = _direction;
	m_Pos.x = _x;
	m_Pos.y = _y;
	Char_Tag = _Tag;
	curTime = 0.0f;

	m_FSM->Init(m_Pos.x, m_Pos.y);
}

bool Xion::Input(int _state)
{
	if (_state == STAND)
	{
		m_FSM->Input(XION_STAND);
	}
	else if (_state == RIGHT)
	{
		Direction = true;
		m_FSM->Input(XION_WORK);
		// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos += vec * 6;
	}

	else if (_state == LEFT)
	{
		Direction = false;
		m_FSM->Input(XION_WORK);
		// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos -= vec * 6;
	}
	else if (_state == ATTACK)
	{
		m_FSM->Input(XION_ATTACK);
	}

	return false;
}

//Update�Լ�
void Xion::Update(float _fETime, float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	m_FSM->Update(Char_Tag, m_Pos.x, m_Pos.y, Direction);

	if (Char_Tag == "Player")
	{
		isDie = GameManager::get_Instance()->get_IsPlayerDie();
	}
	else if (Char_Tag == "Enemy")
	{
		isDie = GameManager::get_Instance()->get_IsEnemyDie();
	}

	//ĳ������ HP�� 0�̶��
	if (isDie)
	{
		m_FSM->Input(XION_DIE);
	}
}

//Draw �Լ�(overloding)
void Xion::Render()
{
	m_FSM->Render(m_Pos.x, m_Pos.y, Direction, 0.0f, 2.0f, 2.0f);
}