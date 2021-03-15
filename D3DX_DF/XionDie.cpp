#include "XionDie.h"
#include "AnimationMaker.h"

//������
XionDie::XionDie()
{
	isDie = false;
}

//�Ҹ���
XionDie::~XionDie()
{
}
//Init�Լ�(override)
void XionDie::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Die\\", 12);
}

//Update�Լ�(override)
void XionDie::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void XionDie::Enter()
{
	Delay = 70.0f;

	if (isDie)
	{
		Ani_Now = curAni.size() - 2;
	}
}

//���� ��Ȳ���� �� �ൿ(override)
void XionDie::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool XionDie::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	isDie = true;
	Delay = 0.0f;
	return true;
}