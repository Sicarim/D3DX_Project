#include "UclidHit.h"
#include "AnimationMaker.h"

//생성자
UclidHit::UclidHit()
{

}

//소멸자
UclidHit::~UclidHit()
{

}

//Init함수(override)
void UclidHit::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Hit\\", 11);
}

//Update함수(override)
void UclidHit::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 10, 120, 180);

	if (Ani_Now == 5)
	{
		Delay = 10.0f;
	}
}

//다음 상태로 전환(override)
void UclidHit::Enter()
{
	Ani_Now = 0;
	Delay = 100.0f;
}

//현재 상황에서 할 행동(override)
void UclidHit::Excute()
{

}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UclidHit::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}
