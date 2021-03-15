#include "UIAnimation.h"
#include "AnimationMaker.h"

//������
UIAnimation::UIAnimation()
{
}

//�Ҹ���
UIAnimation::~UIAnimation()
{
}
//Init�Լ�(override)
void UIAnimation::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\UI\\EndUI\\", 10);
}

//Update�Լ�(override)
void UIAnimation::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void UIAnimation::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void UIAnimation::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool UIAnimation::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}