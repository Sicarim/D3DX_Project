#include "UclidBirth.h"
#include "AnimationMaker.h"
#include "GameManager.h"

//생성자
UclidBirth::UclidBirth()
{
}

//소멸자
UclidBirth::~UclidBirth()
{
}
//Init함수(override)
void UclidBirth::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Birth\\", 11);
}

//Update함수(override)
void UclidBirth::Update(string _tag, float _posx, float _posy, bool _direction)
{
	Tag = _tag;
}

//다음 상태로 전환(override)
void UclidBirth::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void UclidBirth::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UclidBirth::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}