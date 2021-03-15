#include "BiceSkillAttack.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//������
BiceSkillAttack::BiceSkillAttack()
{
}

//�Ҹ���
BiceSkillAttack::~BiceSkillAttack()
{
}

//Init�Լ�(override)
void BiceSkillAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\SkillAttack\\", 2);
}

//Update�Լ�(override)
void BiceSkillAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void BiceSkillAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceSkillAttack::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceSkillAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}