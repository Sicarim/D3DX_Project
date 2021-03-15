#include "BiceStanding.h"
#include "AnimationMaker.h"

//������
BiceStanding::BiceStanding()
{

}

//�Ҹ���
BiceStanding::~BiceStanding()
{

}

//Init�Լ�(override)
void BiceStanding::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Stand\\", 10);
}

//Update�Լ�(override)
void BiceStanding::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 30, 120, 180);
}

//���� ���·� ��ȯ(override)
void BiceStanding::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceStanding::Excute()
{
	
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceStanding::Exit()
{
	Delay = 0.0f;
	return true;
}
