#include "UclidStanding.h"
#include "AnimationMaker.h"

//������
UclidStanding::UclidStanding()
{

}

//�Ҹ���
UclidStanding::~UclidStanding()
{

}

//Init�Լ�(override)
void UclidStanding::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Stand\\", 8);
}

//Update�Լ�(override)
void UclidStanding::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 50, _posy - 10, 60, 180);
}

//���� ���·� ��ȯ(override)
void UclidStanding::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void UclidStanding::Excute()
{

}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool UclidStanding::Exit()
{
	Delay = 0.0f;
	return true;
}
