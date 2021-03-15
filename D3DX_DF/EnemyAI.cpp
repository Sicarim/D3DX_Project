#include "EnemyAI.h"
#include "UIManager.h"

//생성자
EnemyAI::EnemyAI()
{

}

//소멸자
EnemyAI::~EnemyAI()
{

}

void EnemyAI::Init(string _Tag, float _x, float _y, bool _direction)
{
	//캐릭터 초기 정보 삽입
	Tag			= _Tag;
	m_Pos.x		= _x;
	m_Pos.y		= _y;
	Direction	= _direction;
	Degree		= 0;

	//적 체력
	Enemy_HP	= MAX_HP;

	//플레이어의 캐릭터 생성
	Enemy_Charecter = GameManager::get_Instance()->get_AISelect();
	//캐릭터 정보 초기화
	Enemy_Charecter->Init(Tag, m_Pos.x, m_Pos.y, Direction);
}

bool EnemyAI::Input(int _state)
{
	//시작시, 가장 먼저 캐릭터 탄생 모션 실행
	if (!UIManager::get_Instance()->get_IsCharBirth(Tag))
	{
		Enemy_Charecter->Input(STATE_BIRTH);
	}
	else
	{
		Enemy_Charecter->Input(STAND);
	}
	return false;
}

void EnemyAI::Update(float _fETime)
{
	Enemy_Charecter->Update(_fETime, m_Pos.x, m_Pos.y, Direction);
	//죽음 상태 확인
	isDie = GameManager::get_Instance()->get_IsEnemyDie();

	//캐릭터의 HP가 0이라면
	if (isDie)
	{
		Enemy_Charecter->Input(BICE_DIE);
	}
	//이동 위치를 삽입
	//posX = GameManager::get_Instance()->get_AIposX();
	//posY = GameManager::get_Instance()->get_AIposY();
	//콜라이더 범위 입력
	//m_triggerColl.Init_Collision("Enemy", posX - 50, posY - 50, 50, 100, 230, 80);
	
	//AI행동을 실행
	//AI_FSM();

	//m_AI->Update(_fETime);
}

void EnemyAI::Render()
{
	Enemy_Charecter->Render();
	//isCollision = m_triggerColl.Draw_Collision("Player");
}

void EnemyAI::Release()
{

}

DoEngine::Object* EnemyAI::ReturnObject()
{
	return Enemy_Charecter;
}

////AI의 행동들을 정의
//void EnemyAI::AI_FSM()
//{
//	/*if (GameManager::get_Instance()->get_HitCount() >= 2)
//	{
//		if (!Dash)
//		{
//			m_AI->Input(BICE_DASH);
//			Dash = true;
//		}
//	}*/
//	if (isCollision)
//	{
//		m_AI->Input(ATTACK);
//	}
//	else
//	{
//		m_AI->Input(LEFT);
//	}
//}