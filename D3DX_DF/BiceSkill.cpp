#include "BiceSkill.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//생성자
BiceSkill::BiceSkill()
{
}

//소멸자
BiceSkill::~BiceSkill()
{
}

//Init함수(override)
void BiceSkill::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\Attack4\\", 9);
}

//Update함수(override)
void BiceSkill::Update(string _tag, float _posx, float _posy, bool _direction)
{
	
}

//다음 상태로 전환(override)
void BiceSkill::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//현재 상황에서 할 행동(override)
void BiceSkill::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceSkill::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}