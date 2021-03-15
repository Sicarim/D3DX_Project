#include "UclidThirdAttack.h"
#include "AnimationMaker.h"

//생성자
UclidThirdAttack::UclidThirdAttack()
{
}

//소멸자
UclidThirdAttack::~UclidThirdAttack()
{
}

//Init함수(override)
void UclidThirdAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Attack\\Attack3\\", 8);
}

//Update함수(override)
void UclidThirdAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = 100.0f;
		AttackColly = 30.0f;
	}
	else
	{
		DirCollx = -60.0f;
		DirColly = -10.0f;
		AttackCollx = -270.0f;
		AttackColly = 30.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 60, 180);

	if (Ani_Now >= 4 && Ani_Now <= 6)
	{
		m_ThirdAttack.Init_Collision(_tag + "Attack3", _posx + AttackCollx, _posy + AttackColly, 130, 30);
	}
	if (Ani_Now == 6)
	{
		m_ThirdAttack.DeleteCollision();
	}
}

//다음 상태로 전환(override)
void UclidThirdAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//현재 상황에서 할 행동(override)
void UclidThirdAttack::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UclidThirdAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}