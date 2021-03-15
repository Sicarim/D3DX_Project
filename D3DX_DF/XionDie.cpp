#include "XionDie.h"
#include "AnimationMaker.h"

//생성자
XionDie::XionDie()
{
	isDie = false;
}

//소멸자
XionDie::~XionDie()
{
}
//Init함수(override)
void XionDie::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Die\\", 12);
}

//Update함수(override)
void XionDie::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//다음 상태로 전환(override)
void XionDie::Enter()
{
	Delay = 70.0f;

	if (isDie)
	{
		Ani_Now = curAni.size() - 2;
	}
}

//현재 상황에서 할 행동(override)
void XionDie::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
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