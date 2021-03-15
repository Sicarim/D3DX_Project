#include "UclidSecondAttack.h"
#include "AnimationMaker.h"

//생성자
UclidSecondAttack::UclidSecondAttack()
{
}

//소멸자
UclidSecondAttack::~UclidSecondAttack()
{
}

//Init함수(override)
void UclidSecondAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Attack\\Attack2\\", 6);
}

//Update함수(override)
void UclidSecondAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -60.0f;
		DirColly = -10.0f;
		AttackCollx = -150.0f;
		AttackColly = -145.0f;
	}
	else
	{
		DirCollx = -60.0f;
		DirColly = -10.0f;
		AttackCollx = -105.0f;
		AttackColly = -145.0f;
	}
	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 60, 180);

	if (Ani_Now >= 2 && Ani_Now <= 5)
	{
		m_SecondAttack.Init_Collision(_tag + "Attack2", _posx + AttackCollx, _posy + AttackColly, 210, 200);
	}
	if (Ani_Now == 4)
	{
		m_SecondAttack.DeleteCollision();
	}
}

//Draw함수
void UclidSecondAttack::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx, _posy, _direction, _degree, _sizex, _sizey);
	m_Coll.Draw_Collision();
	m_SecondAttack.Draw_Collision();
}

//다음 상태로 전환(override)
void UclidSecondAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//현재 상황에서 할 행동(override)
void UclidSecondAttack::Excute()
{

}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool UclidSecondAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}