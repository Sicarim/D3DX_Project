#include "XionFSM.h"
#include "GameManager.h"
#include "CollisionManager.h"
#include "UIManager.h"
#include "XionStanding.h"
#include "XionWork.h"
#include "XionHit.h"
#include "XionFirstAttack.h"
#include "XionSecondAttack.h"
#include "XionDie.h"
//#include "XionThirdAttack.h"

//생성자
XionFSM::XionFSM()
{

}

//소멸자
XionFSM::~XionFSM()
{

}

//초기화
void XionFSM::Init(int _posx, int _posy)
{
	AttackCount = 0;

	DoEngine::State* tmp_State;

	tmp_State = new XionStanding();
	m_State.push_back(tmp_State);
	tmp_State = new XionWork();
	m_State.push_back(tmp_State);
	tmp_State = new XionFirstAttack();
	m_State.push_back(tmp_State);
	tmp_State = new XionSecondAttack();
	m_State.push_back(tmp_State);
	tmp_State = new XionHit();
	m_State.push_back(tmp_State);
	tmp_State = new XionDie();
	m_State.push_back(tmp_State);
	//tmp_State = new XionThirdAttack();
	//m_State.push_back(tmp_State);

	hit = 0.0f;
	for (int i = 0; i < m_State.size(); i++)
	{
		m_State[i]->Init();
	}

	ChangeState(m_State[XION_STAND]); //첫 State를 Stand로 지정
}

//FSM Input(override)
void XionFSM::Input(int _curState)
{
	curState = _curState;
}

//FSM Update(override)
void XionFSM::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll = m_pCurrentState->get_Coll();

	//엑시온 Die모션
	if (curState == XION_DIE)
	{
		ChangeState(m_State[XION_DIE]);
	}

	//엑시온 탄생
	/*if (curState == BICE_BIRTH)
	{
		ChangeState(m_State[XION_BIRTH]);
	}*/

	if (!isHit(_tag))
	{
		if (curState == XION_STAND)
		{
			ChangeState(m_State[XION_STAND]);
		}

		else if (curState == XION_WORK)
		{
			ChangeState(m_State[XION_WORK]);
		}

		else if (curState == XION_ATTACK)
		{
			AttackCount++;

			if (AttackCount == 1)
			{
				ChangeState(m_State[XION_ATTACK_FIRST]);
			}
			else if (AttackCount == 2)
			{
				ChangeState(m_State[XION_ATTACK_SECOND]);
				AttackCount = 0;
			}
		}
	}

	m_pCurrentState->Update(_tag, _posx + hit, _posy, _direction);
	m_pCurrentState->Play_Animation(GameManager::get_Instance()->get_MotionDelay());
}

//FSM UpdateTime(override)
void XionFSM::UpdateTime(float _fETime)
{

}

//FSM Draw(override)
void XionFSM::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	m_pCurrentState->Render(_posx + hit, _posy, _direction, _degree, _sizex, _sizey);

	string tmp = to_string(m_pCurrentState->get_curFrame());
	DoEngine::GraphicsManager::get_Instance()->Draw_Text(tmp, 400, 100, D3DCOLOR_XRGB(255, 255, 255));
}

bool XionFSM::isHit(string _tag)
{
	if (_tag == "Player")
	{
		EnemyTag = "Enemy";
	}
	else
	{
		EnemyTag = "Player";
	}

	if (m_Coll.isCollision(EnemyTag + "Attack1"))
	{
		ChangeState(m_State[XION_HIT]);
		hit += 0.1f;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	if (m_Coll.isCollision(EnemyTag + "Attack2"))
	{
		ChangeState(m_State[XION_HIT]);
		hit += 0.1f;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	if (m_Coll.isCollision(EnemyTag + "Attack3"))
	{
		ChangeState(m_State[XION_HIT]);
		hit += 0.1f;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	return false;
}