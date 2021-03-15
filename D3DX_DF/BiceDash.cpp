#include "BiceDash.h"
#include "AnimationMaker.h"

//생성자
BiceDash::BiceDash()
{
}

//소멸자
BiceDash::~BiceDash()
{
}
//Init함수(override)
void BiceDash::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Dash\\", 5);
}

//Update함수(override)
void BiceDash::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//다음 상태로 전환(override)
void BiceDash::Enter()
{
	Ani_Now = 0;
	Delay = 50.0f;
}

//현재 상황에서 할 행동(override)
void BiceDash::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceDash::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}