#include "XionWork.h"
#include "AnimationMaker.h"

//생성자
XionWork::XionWork()
{
}

//소멸자
XionWork::~XionWork()
{
}
//Init함수(override)
void XionWork::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Dash\\", 8);
}

//Update함수(override)
void XionWork::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -80.0f;
		DirColly = -10.0f;
	}
	else
	{
		DirCollx = -45.0f;
		DirColly = -10.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 120, 150);
}

//Draw함수
void XionWork::Render(float _posx, float _posy, bool _direction, float _degree, int _sizex, int _sizey)
{
	if (_direction)
	{
		DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx - 70, _posy + 10, _direction, _degree, _sizex, _sizey);
	}
	else
	{
		DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx + 30, _posy + 10, _direction, _degree, _sizex, _sizey);
	}
	
	m_Coll.Draw_Collision();
}

//다음 상태로 전환(override)
void XionWork::Enter()
{
	Delay = 200.0f;
}

//현재 상황에서 할 행동(override)
void XionWork::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool XionWork::Exit()
{
	Delay = 0.0f;
	return true;
}