#include "EnemyAI.h"
#include "UIManager.h"

//������
EnemyAI::EnemyAI()
{

}

//�Ҹ���
EnemyAI::~EnemyAI()
{

}

void EnemyAI::Init(string _Tag, float _x, float _y, bool _direction)
{
	//ĳ���� �ʱ� ���� ����
	Tag			= _Tag;
	m_Pos.x		= _x;
	m_Pos.y		= _y;
	Direction	= _direction;
	Degree		= 0;

	//�� ü��
	Enemy_HP	= MAX_HP;

	//�÷��̾��� ĳ���� ����
	Enemy_Charecter = GameManager::get_Instance()->get_AISelect();
	//ĳ���� ���� �ʱ�ȭ
	Enemy_Charecter->Init(Tag, m_Pos.x, m_Pos.y, Direction);
}

bool EnemyAI::Input(int _state)
{
	//���۽�, ���� ���� ĳ���� ź�� ��� ����
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
	//���� ���� Ȯ��
	isDie = GameManager::get_Instance()->get_IsEnemyDie();

	//ĳ������ HP�� 0�̶��
	if (isDie)
	{
		Enemy_Charecter->Input(BICE_DIE);
	}
	//�̵� ��ġ�� ����
	//posX = GameManager::get_Instance()->get_AIposX();
	//posY = GameManager::get_Instance()->get_AIposY();
	//�ݶ��̴� ���� �Է�
	//m_triggerColl.Init_Collision("Enemy", posX - 50, posY - 50, 50, 100, 230, 80);
	
	//AI�ൿ�� ����
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

////AI�� �ൿ���� ����
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