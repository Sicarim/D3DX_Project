#include "XionHit.h"
#include "AnimationMaker.h"

//생성자
XionHit::XionHit()
{

}

//소멸자
XionHit::~XionHit()
{

}

//Init함수(override)
void XionHit::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Hit\\", 3);
}

//Update함수(override)
void XionHit::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 10, 120, 180);

	if (Ani_Now == 5)
	{
		Delay = 10.0f;
	}
}

//다음 상태로 전환(override)
void XionHit::Enter()
{
	Ani_Now = 0;
	Delay = 100.0f;
}

//현재 상황에서 할 행동(override)
void XionHit::Excute()
{

}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool XionHit::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}
