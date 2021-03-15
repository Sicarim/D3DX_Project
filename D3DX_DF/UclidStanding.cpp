#include "UclidStanding.h"
#include "AnimationMaker.h"

//생성자
UclidStanding::UclidStanding()
{

}

//소멸자
UclidStanding::~UclidStanding()
{

}

//Init함수(override)
void UclidStanding::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Stand\\", 8);
}

//Update함수(override)
void UclidStanding::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 50, _posy - 10, 60, 180);
}

//다음 상태로 전환(override)
void UclidStanding::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void UclidStanding::Excute()
{

}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UclidStanding::Exit()
{
	Delay = 0.0f;
	return true;
}
