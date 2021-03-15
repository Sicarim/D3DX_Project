#include "BiceSecondAttack.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//생성자
BiceSecondAttack::BiceSecondAttack()
{
}

//소멸자
BiceSecondAttack::~BiceSecondAttack()
{
}

//Init함수(override)
void BiceSecondAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\Attack2\\", 12);
}

//Update함수(override)
void BiceSecondAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -100.0f;
		DirColly = -10.0f;
		AttackCollx = 135.0f;
		AttackColly = 10.0f;
	}
	else
	{
		DirCollx = -60.0f;
		DirColly = -10.0f;
		AttackCollx = -195.0f;
		AttackColly = 10.0f;
	}
	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 120, 180);
	
	if (Ani_Now >= 6 && Ani_Now < 10)
	{
		m_SecondAttack.Init_Collision(_tag + "Attack2", _posx + AttackCollx, _posy + AttackColly, 25, 30);
	}
	else if(Ani_Now == 10)
	{	
		m_SecondAttack.DeleteCollision();
	}
}

//Draw함수
void BiceSecondAttack::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	float tmp_pos;
	if (_direction)
	{
		tmp_pos = 100;
	}
	else
	{
		tmp_pos = -100;
	}
	DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx + tmp_pos, _posy, _direction, _degree, _sizex, _sizey);
	m_Coll.Draw_Collision();
	m_SecondAttack.Draw_Collision();
}

//다음 상태로 전환(override)
void BiceSecondAttack::Enter()
{
	Ani_Now = 0;
	Delay = 50.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}
	
//현재 상황에서 할 행동(override)
void BiceSecondAttack::Excute()
{

}

//다음 상황으로 넘어가기전 해야하는 행동(override)
bool BiceSecondAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	UIManager::get_Instance()->Return_IsAttack();
	Delay = 0.0f;
	return true;
}