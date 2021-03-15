#include "BiceDie.h"
#include "AnimationMaker.h"

//������
BiceDie::BiceDie()
{
	isDie = false;
}

//�Ҹ���
BiceDie::~BiceDie()
{
}
//Init�Լ�(override)
void BiceDie::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Die\\", 12);
}

//Update�Լ�(override)
void BiceDie::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void BiceDie::Enter()
{
	Delay = 70.0f;

	if (isDie)
	{
		Ani_Now = curAni.size() - 2;
	}
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceDie::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceDie::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	isDie = true;
	Delay = 0.0f;
	return true;
}