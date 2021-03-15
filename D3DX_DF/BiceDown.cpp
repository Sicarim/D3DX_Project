#include "BiceDown.h"
#include "AnimationMaker.h"

//생성자
BiceDown::BiceDown()
{
}

//소멸자
BiceDown::~BiceDown()
{
}
//Init함수(override)
void BiceDown::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Down\\", 3);
}

//Update함수(override)
void BiceDown::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//다음 상태로 전환(override)
void BiceDown::Enter()
{
	Delay = 70.0f;
}

//현재 상황에서 할 행동(override)
void BiceDown::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceDown::Exit()
{
	Delay = 0.0f;
	return true;
}