#include "BiceHit.h"
#include "AnimationMaker.h"

//������
BiceHit::BiceHit()
{
}

//�Ҹ���
BiceHit::~BiceHit()
{

}

//Init�Լ�(override)
void BiceHit::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Hit\\", 4);
}

//Update�Լ�(override)
void BiceHit::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void BiceHit::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceHit::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceHit::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}