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

//초기화(시작 위치 초기화 가능)
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
		// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos += vec * 6;
	}

	else if (_state == LEFT)
	{
		Direction = false;
		m_FSM->Input(XION_WORK);
		// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
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

//Update함수
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

	//캐릭터의 HP가 0이라면
	if (isDie)
	{
		m_FSM->Input(XION_DIE);
	}
}

//Draw 함수(overloding)
void Xion::Render()
{
	m_FSM->Render(m_Pos.x, m_Pos.y, Direction, 0.0f, 2.0f, 2.0f);
}