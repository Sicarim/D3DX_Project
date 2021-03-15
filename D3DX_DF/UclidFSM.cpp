#include "UclidFSM.h"
#include "GameManager.h"
#include "CollisionManager.h"
#include "UIManager.h"
#include "UclidStanding.h"
#include "UclidFirstAttack.h"
#include "UclidSecondAttack.h"
#include "UclidThirdAttack.h"
#include "UclidHit.h"
#include "UclidBirth.h"
#include "UclidDie.h"

//생성자
UclidFSM::UclidFSM()
{

}

//소멸자
UclidFSM::~UclidFSM()
{

}

//초기화
void UclidFSM::Init(int _posx, int _posy)
{
	AttackCount = 0;

	DoEngine::State* tmp_State;

	tmp_State = new UclidStanding();
	m_State.push_back(tmp_State);
	tmp_State = new UclidFirstAttack();
	m_State.push_back(tmp_State);
	tmp_State = new UclidSecondAttack();
	m_State.push_back(tmp_State);
	tmp_State = new UclidThirdAttack();
	m_State.push_back(tmp_State);
	tmp_State = new UclidHit();
	m_State.push_back(tmp_State);
	tmp_State = new UclidBirth();
	m_State.push_back(tmp_State);
	tmp_State = new UclidDie();
	m_State.push_back(tmp_State);

	hit = 0.0f;
	for (int i = 0; i < m_State.size(); i++)
	{
		m_State[i]->Init();
	}

	ChangeState(m_State[UCLID_STAND]); //첫 State를 Stand로 지정
}

//FSM Input(override)
void UclidFSM::Input(int _curState)
{
	curState = _curState;
}

//FSM Update(override)
void UclidFSM::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll = m_pCurrentState->get_Coll();

	//유클리드 Die모션
	if (curState == UCLID_DIE)
	{
		ChangeState(m_State[UCLID_DIE]);
	}

	if (curState == UCLID_BIRTH)
	{
		ChangeState(m_State[UCLID_BIRTH]);
	}

	if (!isHit(_tag))
	{
		if (curState == UCLID_STAND)
		{
			ChangeState(m_State[UCLID_STAND]);
		}

		else if (curState == UCLID_ATTACK)
		{
			AttackCount++;

			if (AttackCount == 1)
			{
				ChangeState(m_State[UCLID_ATTACK_FIRST]);
			}
			else if (AttackCount == 2)
			{
				ChangeState(m_State[UCLID_ATTACK_THIRD]);
			}
			else if (AttackCount == 3)
			{
				ChangeState(m_State[UCLID_ATTACK_SECOND]);
				AttackCount = 0;
			}
		}
	}
	m_pCurrentState->Update(_tag, _posx + hit, _posy, _direction);
	m_pCurrentState->Play_Animation(GameManager::get_Instance()->get_MotionDelay());
}

//FSM UpdateTime(override)
void UclidFSM::UpdateTime(float _fETime)
{

}

//FSM Draw(override)
void UclidFSM::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	m_pCurrentState->Render(_posx + hit, _posy, _direction, _degree, _sizex, _sizey);

	string tmp = to_string(m_pCurrentState->get_curFrame());
	DoEngine::GraphicsManager::get_Instance()->Draw_Text(tmp, 400, 100, D3DCOLOR_XRGB(255, 255, 255));
}

bool UclidFSM::isHit(string _tag)
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
		ChangeState(m_State[UCLID_HIT]);
		hit += 0.1f;
		UIManager::get_Instance()->set_Damege(_tag, 0.013f);
		return true;
	}
	if (m_Coll.isCollision(EnemyTag + "Attack2"))
	{
		ChangeState(m_State[UCLID_HIT]);
		hit += 0.1f;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	if (m_Coll.isCollision(EnemyTag + "Attack3"))
	{
		ChangeState(m_State[UCLID_HIT]);
		hit += 0.1f;
		UIManager::get_Instance()->set_Damege(_tag, 0.13f);
		return true;
	}
	return false;
}