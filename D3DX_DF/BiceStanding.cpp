#include "BiceStanding.h"
#include "AnimationMaker.h"

//생성자
BiceStanding::BiceStanding()
{

}

//소멸자
BiceStanding::~BiceStanding()
{

}

//Init함수(override)
void BiceStanding::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Stand\\", 10);
}

//Update함수(override)
void BiceStanding::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 30, 120, 180);
}

//다음 상태로 전환(override)
void BiceStanding::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void BiceStanding::Excute()
{
	
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceStanding::Exit()
{
	Delay = 0.0f;
	return true;
}
