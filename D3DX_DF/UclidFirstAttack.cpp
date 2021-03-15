#include "UclidFirstAttack.h"
#include "AnimationMaker.h"

//생성자
UclidFirstAttack::UclidFirstAttack()
{
}

//소멸자
UclidFirstAttack::~UclidFirstAttack()
{
}

//Init함수(override)
void UclidFirstAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Attack\\Attack1\\", 8);
}

//Update함수(override)
void UclidFirstAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = -230.0f;
		AttackColly = -5.0f;
	}
	else
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = -250.0f;
		AttackColly = -5.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 60, 180);

	if (Ani_Now >= 4 && Ani_Now <= 7)
	{
		m_FirstAttack.Init_Collision(_tag + "Attack1", _posx + AttackCollx, _posy + AttackColly, 440, 100);
	}
	if (Ani_Now == 6)
	{
		m_FirstAttack.DeleteCollision();
	}
}

//다음 상태로 전환(override)
void UclidFirstAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//현재 상황에서 할 행동(override)
void UclidFirstAttack::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UclidFirstAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}