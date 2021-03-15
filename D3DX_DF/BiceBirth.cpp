#include "BiceBirth.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//생성자
BiceBirth::BiceBirth()
{
}

//소멸자
BiceBirth::~BiceBirth()
{
}
//Init함수(override)
void BiceBirth::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Birth\\", 16);
}

//Update함수(override)
void BiceBirth::Update(string _tag, float _posx, float _posy, bool _direction)
{
	Tag = _tag;
}

//다음 상태로 전환(override)
void BiceBirth::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void BiceBirth::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
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