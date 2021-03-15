#include "BiceHit.h"
#include "AnimationMaker.h"

//생성자
BiceHit::BiceHit()
{
}

//소멸자
BiceHit::~BiceHit()
{

}

//Init함수(override)
void BiceHit::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Hit\\", 4);
}

//Update함수(override)
void BiceHit::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//다음 상태로 전환(override)
void BiceHit::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void BiceHit::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceHit::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}