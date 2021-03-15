#include "UclidBirth.h"
#include "AnimationMaker.h"
#include "GameManager.h"

//������
UclidBirth::UclidBirth()
{
}

//�Ҹ���
UclidBirth::~UclidBirth()
{
}
//Init�Լ�(override)
void UclidBirth::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Birth\\", 11);
}

//Update�Լ�(override)
void UclidBirth::Update(string _tag, float _posx, float _posy, bool _direction)
{
	Tag = _tag;
}

//���� ���·� ��ȯ(override)
void UclidBirth::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void UclidBirth::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool UclidBirth::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}