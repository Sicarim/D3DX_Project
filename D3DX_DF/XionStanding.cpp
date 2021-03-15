#include "XionStanding.h"
#include "AnimationMaker.h"

//생성자
XionStanding::XionStanding()
{

}

//소멸자
XionStanding::~XionStanding()
{

}

//Init함수(override)
void XionStanding::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Stand\\", 6);
}

//Update함수(override)
void XionStanding::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -30.0f;
		DirColly = -10.0f;
	}
	else
	{
		DirCollx = -45.0f;
		DirColly = -10.0f;
	}
	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 120, 150);
}

//다음 상태로 전환(override)
void XionStanding::Enter()
{
	Delay = 200.0f;
	DirCollx = 0.0f;
	DirColly = 0.0f;
}

//현재 상황에서 할 행동(override)
void XionStanding::Excute()
{

}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool XionStanding::Exit()
{
	Delay = 0.0f;
	return true;
}
