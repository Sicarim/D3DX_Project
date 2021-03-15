#include "XionWork.h"
#include "AnimationMaker.h"

//������
XionWork::XionWork()
{
}

//�Ҹ���
XionWork::~XionWork()
{
}
//Init�Լ�(override)
void XionWork::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Dash\\", 8);
}

//Update�Լ�(override)
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

//Draw�Լ�
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

//���� ���·� ��ȯ(override)
void XionWork::Enter()
{
	Delay = 200.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void XionWork::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool XionWork::Exit()
{
	Delay = 0.0f;
	return true;
}