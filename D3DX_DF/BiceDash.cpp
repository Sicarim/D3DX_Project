#include "BiceDash.h"
#include "AnimationMaker.h"

//������
BiceDash::BiceDash()
{
}

//�Ҹ���
BiceDash::~BiceDash()
{
}
//Init�Լ�(override)
void BiceDash::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Dash\\", 5);
}

//Update�Լ�(override)
void BiceDash::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void BiceDash::Enter()
{
	Ani_Now = 0;
	Delay = 50.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceDash::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceDash::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}