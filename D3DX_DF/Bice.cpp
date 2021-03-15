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

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)
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
		//�ȱ� �����̸� �ȴ� ����� �����Ѵ�.
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
		
		//�뽬 �Է�
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

		//��ų �Է�
		if (BiceSkiil == BICE_ATTACK_SKILL)
		{
			m_FSM->Input(BICE_ATTACK_SKILL);
		}
	}

	//Enemy��� AI��ġ ����
	if (Char_Tag == "Enemy")
	{
		GameManager::get_Instance()->set_AIposX(m_Pos.x);
		GameManager::get_Instance()->set_AIposY(m_Pos.y);
	}
	
	return false;
}

//Update�Լ�
void Bice::Update(float _fETime, float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	//�ǽð� ���� �ֽ�ȭ
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

//Draw �Լ�(overloding)
void Bice::Render()
{
	m_FSM->Render(m_Pos.x, m_Pos.y, Direction, 0.0f, 2.0f, 2.0f);
}