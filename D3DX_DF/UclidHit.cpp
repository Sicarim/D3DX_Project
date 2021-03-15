#include "UclidHit.h"
#include "AnimationMaker.h"

//������
UclidHit::UclidHit()
{

}

//�Ҹ���
UclidHit::~UclidHit()
{

}

//Init�Լ�(override)
void UclidHit::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Hit\\", 11);
}

//Update�Լ�(override)
void UclidHit::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 10, 120, 180);

	if (Ani_Now == 5)
	{
		Delay = 10.0f;
	}
}

//���� ���·� ��ȯ(override)
void UclidHit::Enter()
{
	Ani_Now = 0;
	Delay = 100.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void UclidHit::Excute()
{

}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool UclidHit::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}
