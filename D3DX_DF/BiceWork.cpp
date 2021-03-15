#include "BiceWork.h"
#include "AnimationMaker.h"

//생성자
BiceWork::BiceWork()
{
}

//소멸자
BiceWork::~BiceWork()
{
}
//Init함수(override)
void BiceWork::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Run\\", 10);
}

//Update함수(override)
void BiceWork::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 30, 120, 180);
}

//다음 상태로 전환(override)
void BiceWork::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void BiceWork::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceWork::Exit()
{
	Delay = 0.0f;
	return true;
}