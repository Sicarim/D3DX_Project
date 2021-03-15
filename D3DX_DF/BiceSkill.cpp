#include "BiceSkill.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//������
BiceSkill::BiceSkill()
{
}

//�Ҹ���
BiceSkill::~BiceSkill()
{
}

//Init�Լ�(override)
void BiceSkill::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\Attack4\\", 9);
}

//Update�Լ�(override)
void BiceSkill::Update(string _tag, float _posx, float _posy, bool _direction)
{
	
}

//���� ���·� ��ȯ(override)
void BiceSkill::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceSkill::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceSkill::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}