#include "XionFirstAttack.h"
#include "AnimationMaker.h"

//생성자
XionFirstAttack::XionFirstAttack()
{
}

//소멸자
XionFirstAttack::~XionFirstAttack()
{
}

//Init함수(override)
void XionFirstAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Attack\\Attack1\\", 10);
}

//Update함수(override)
void XionFirstAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = 30.0f;
		AttackColly = -5.0f;
	}
	else
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = -100.0f;
		AttackColly = -5.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 120, 120);

	if (Ani_Now >= 4 && Ani_Now <= 9)
	{
		m_FirstAttack.Init_Collision(_tag + "Attack1", _posx + AttackCollx, _posy + AttackColly, 110, 140);
	}
	if (Ani_Now == 8)
	{
		m_FirstAttack.DeleteCollision();
	}
}

//다음 상태로 전환(override)
void XionFirstAttack::Enter()
{
	Ani_Now = 0;
	Delay = 100.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//현재 상황에서 할 행동(override)
void XionFirstAttack::Excute()
{
}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool XionFirstAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}