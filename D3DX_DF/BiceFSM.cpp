#include "BiceFSM.h"
#include "UIManager.h"
#include "GameManager.h"
#include "BiceStanding.h"
#include "BiceWork.h"
#include "BiceFirstAttack.h"
#include "BiceSecondAttack.h"
#include "BiceThirdAttack.h"
#include "BiceSkill.h"
#include "BiceBirth.h"
#include "BiceHit.h"
#include "BiceDie.h"
#include "BiceDash.h"

//생성자
BiceFSM::BiceFSM()
{

}

//소멸자
BiceFSM::~BiceFSM()
{

}

//초기화
void BiceFSM::Init(int _posx, int _posy)
{
	Pos_x		= _posx;
	Pos_y		= _posy;
	AttackCount = 0;
	HitCount	= 0;
	curTime		= 0.0f;
	BeforeTime	= 0.0f;
	hit			= 0.0f;

	DoEngine::State* tmp_State;

	tmp_State = new BiceStanding();
	m_State.push_back(tmp_State);
	tmp_State = new BiceWork();
	m_State.push_back(tmp_State);
	tmp_State = new BiceFirstAttack();
	m_State.push_back(tmp_State);
	tmp_State = new BiceSecondAttack();
	m_State.push_back(tmp_State);
	tmp_State = new BiceThirdAttack();
	m_State.push_back(tmp_State);
	tmp_State = new BiceSkill();
	m_State.push_back(tmp_State);
	tmp_State = new BiceHit();
	m_State.push_back(tmp_State);
	tmp_State = new BiceBirth();
	m_State.push_back(tmp_State);
	tmp_State = new BiceDie();
	m_State.push_back(tmp_State);
	tmp_State = new BiceDash();
	m_State.push_back(tmp_State);

	for (int i = 0; i < m_State.size(); i++)
	{
		m_State[i]->Init();
	}

	ChangeState(m_State[BICE_STAND]); //첫 State를 Stand로 지정

	//AI INFO//
	HitTime = 0.0f;
}

//FSM Input(override)
void BiceFSM::Input(int _curState)
{
	curState = _curState;
}

//FSM Update(override)
void BiceFSM::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll = m_pCurrentState->get_Coll();

	//바이스 Die모션
	if (curState == BICE_DIE)
	{
		ChangeState(m_State[BICE_DIE]);
	}

	//바이스 탄생
	if (curState == BICE_BIRTH)
	{
		ChangeState(m_State[BICE_BIRTH]);
	}

	if (!isHit(_tag))
	{
		//바이스 기본 자세
		if (curState == BICE_STAND)
		{
			ChangeState(m_State[BICE_STAND]);
		}

		else if (curState == BICE_WORK)
		{
			ChangeState(m_State[BICE_WORK]);
		}

		//바이스 공격
		else if (curState == BICE_ATTACK)
		{
			if (AttackCount == 0)
			{
				AttackCount++;
				BeforeTime = curTime;
			}
			else
			{
				//이전 입력시간과의 차이가 1초 미만이라면
				if (curTime - BeforeTime < 0.8f)
				{
					AttackCount++;
				}
				else
				{
					AttackCount = 1;
				}
				BeforeTime = curTime;
			}
			
			if (AttackCount == 1)
			{
				ChangeState(m_State[BICE_ATTACK_FIRST]);
			}
			else if (AttackCount == 2)
			{
				ChangeState(m_State[BICE_ATTACK_SECOND]);
			}
			else if (AttackCount == 3)
			{
				ChangeState(m_State[BICE_ATTACK_THIRD]);
				AttackCount = 0;
			}
		}
	}

	//Bice Skill 발동
	if (curState == BICE_ATTACK_SKILL)
	{
		ChangeState(m_State[BICE_ATTACK_SKILL], true);
	}

	m_pCurrentState->Update(_tag, _posx, _posy, _direction);
	m_pCurrentState->Play_Animation(GameManager::get_Instance()->get_MotionDelay());
}

//FSM UpdateTime(override)
void BiceFSM::UpdateTime(float _fETime)
{
	curTime += _fETime;

	//일정 시간동안 Hit되지 않았다면, HitCount를 0으로 만든다.
	if (HitCount > 0)
	{
		HitTime += _fETime;
		if (HitTime > 20.0f)
		{
			HitCount = 0;
		}
	}
}

//FSM Draw(override)
void BiceFSM::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	m_pCurrentState->Render(_posx, _posy, _direction, _degree, _sizex, _sizey);
	
	

	string tmp = to_string(m_pCurrentState->get_curFrame());
	DoEngine::GraphicsManager::get_Instance()->Draw_Text(tmp, 400, 100, D3DCOLOR_XRGB(255, 255, 255));
}

bool BiceFSM::isHit(string _tag)
{
	if (_tag == "Player")
	{
		EnemyTag = "Enemy";
	}
	else
	{
		EnemyTag = "Player";
		GameManager::get_Instance()->set_HitCount(HitCount);
	}

	if (m_Coll.isCollision(EnemyTag + "Attack1"))
	{
		ChangeState(m_State[BICE_HIT]);
		hit += 0.1f;
		HitCount++;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	if (m_Coll.isCollision(EnemyTag + "Attack2"))
	{
		ChangeState(m_State[BICE_HIT]);
		hit += 0.1f;
		HitCount++;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	if (m_Coll.isCollision(EnemyTag + "Attack3"))
	{
		ChangeState(m_State[BICE_HIT]);
		hit += 0.1f;
		HitCount++;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	return false;
}