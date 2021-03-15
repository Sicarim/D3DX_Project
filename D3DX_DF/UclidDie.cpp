#include "UclidDie.h"
#include "AnimationMaker.h"

//������
UclidDie::UclidDie()
{
	isDie = false;
}

//�Ҹ���
UclidDie::~UclidDie()
{
}
//Init�Լ�(override)
void UclidDie::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Die\\", 11);
}

//Update�Լ�(override)
void UclidDie::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void UclidDie::Enter()
{
	Delay = 70.0f;

	if (isDie)
	{
		Ani_Now = curAni.size() - 2;
	}
}

//���� ��Ȳ���� �� �ൿ(override)
void UclidDie::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool UclidDie::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	isDie = true;
	Delay = 0.0f;
	return true;
}