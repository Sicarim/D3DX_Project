#include "UIAnimation.h"
#include "AnimationMaker.h"

//생성자
UIAnimation::UIAnimation()
{
}

//소멸자
UIAnimation::~UIAnimation()
{
}
//Init함수(override)
void UIAnimation::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\UI\\EndUI\\", 10);
}

//Update함수(override)
void UIAnimation::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//다음 상태로 전환(override)
void UIAnimation::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void UIAnimation::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UIAnimation::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}