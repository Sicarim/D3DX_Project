#include "BiceBirth.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//������
BiceBirth::BiceBirth()
{
}

//�Ҹ���
BiceBirth::~BiceBirth()
{
}
//Init�Լ�(override)
void BiceBirth::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Birth\\", 16);
}

//Update�Լ�(override)
void BiceBirth::Update(string _tag, float _posx, float _posy, bool _direction)
{
	Tag = _tag;
}

//���� ���·� ��ȯ(override)
void BiceBirth::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceBirth::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceBirth::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	UIManager::get_Instance()->set_isBirth(Tag, true);
	Delay = 0.0f;
	return true;
}