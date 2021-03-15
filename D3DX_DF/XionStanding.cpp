#include "XionStanding.h"
#include "AnimationMaker.h"

//������
XionStanding::XionStanding()
{

}

//�Ҹ���
XionStanding::~XionStanding()
{

}

//Init�Լ�(override)
void XionStanding::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Stand\\", 6);
}

//Update�Լ�(override)
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

//���� ���·� ��ȯ(override)
void XionStanding::Enter()
{
	Delay = 200.0f;
	DirCollx = 0.0f;
	DirColly = 0.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void XionStanding::Excute()
{

}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool XionStanding::Exit()
{
	Delay = 0.0f;
	return true;
}
