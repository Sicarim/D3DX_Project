#include "BiceSkillAttack.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//생성자
BiceSkillAttack::BiceSkillAttack()
{
}

//소멸자
BiceSkillAttack::~BiceSkillAttack()
{
}

//Init함수(override)
void BiceSkillAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\SkillAttack\\", 2);
}

//Update함수(override)
void BiceSkillAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//다음 상태로 전환(override)
void BiceSkillAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//현재 상황에서 할 행동(override)
void BiceSkillAttack::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceSkillAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}