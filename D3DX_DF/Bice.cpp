#include "Bice.h"
#include "GraphicsManager.h"
#include "GameManager.h"
#include "AnimationMaker.h"

Bice::Bice()
{
}


Bice::~Bice()
{
}

//초기화(시작 위치 초기화 가능)
void Bice::Init(string _Tag, float _x, float _y, bool _direction)
{
	m_FSM		= new BiceFSM();
	m_Combo		= new BiceComboSystem();
	curTime		= 0.0f;
	BiceSkiil	= 0;
	curState	= 0;

	Direction	= _direction;
	m_Pos.x		= _x;
	m_Pos.y		= _y;
	Char_Tag	= _Tag;


	m_FSM->Init(m_Pos.x, m_Pos.y);
	m_Combo->Init();
}

bool Bice::Input(int _state)
{	
	curState = _state;
	BiceSkiil = m_Combo->CheckCommand();

	if (_state != STAND)
	{
		m_Combo->InputCommand(_state);
	}

	if (curState == STATE_BIRTH)
	{
		m_FSM->Input(BICE_BIRTH);
	}
		
	//}
	else
	{
		//걷기 동작이면 걷는 모션을 실행한다.
		if (curState == LEFT || curState == RIGHT)
		{
			m_FSM->Input(BICE_WORK);
		}

		if (curState == ATTACK)
		{
			m_FSM->Input(BICE_ATTACK);
		}

		else if (curState == STAND)
		{
			m_FSM->Input(BICE_STAND);
		}
		
		//대쉬 입력
		if (curState == BICE_DASH)
		{
			m_FSM->Input(BICE_DASH);
			if (Direction)
			{
				//m_Pos += vec * 250;
			}
			else
			{
				//m_Pos -= vec * 250;
			}
		}

		//스킬 입력
		if (BiceSkiil == BICE_ATTACK_SKILL)
		{
			m_FSM->Input(BICE_ATTACK_SKILL);
		}
	}

	//Enemy라면 AI위치 삽입
	if (Char_Tag == "Enemy")
	{
		GameManager::get_Instance()->set_AIposX(m_Pos.x);
		GameManager::get_Instance()->set_AIposY(m_Pos.y);
	}
	
	return false;
}

//Update함수
void Bice::Update(float _fETime, float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	//실시간 정보 최신화
	m_Pos.x = _posx;
	m_Pos.y = _posy;
	Direction = _direction;
	Degree = _degree;
	sizeX = _sizex;
	sizeY = _sizey;


	m_FSM->Update(Char_Tag, m_Pos.x, m_Pos.y, Direction);
	m_FSM->UpdateTime(_fETime);
	m_Combo->ComboUpdate(_fETime);

}

//Draw 함수(overloding)
void Bice::Render()
{
	m_FSM->Render(m_Pos.x, m_Pos.y, Direction, 0.0f, 2.0f, 2.0f);
}