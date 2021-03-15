#include "XionHit.h"
#include "AnimationMaker.h"

//������
XionHit::XionHit()
{

}

//�Ҹ���
XionHit::~XionHit()
{

}

//Init�Լ�(override)
void XionHit::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Hit\\", 3);
}

//Update�Լ�(override)
void XionHit::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 10, 120, 180);

	if (Ani_Now == 5)
	{
		Delay = 10.0f;
	}
}

//���� ���·� ��ȯ(override)
void XionHit::Enter()
{
	Ani_Now = 0;
	Delay = 100.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void XionHit::Excute()
{

}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool XionHit::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}
