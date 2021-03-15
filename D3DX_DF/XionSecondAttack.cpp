#include "XionSecondAttack.h"
#include "AnimationMaker.h"

//������
XionSecondAttack::XionSecondAttack()
{
}

//�Ҹ���
XionSecondAttack::~XionSecondAttack()
{
}

//Init�Լ�(override)
void XionSecondAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Xion\\Attack\\Attack2\\", 9);
}

//Update�Լ�(override)
void XionSecondAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = 20.0f;
		AttackColly = -5.0f;
	}
	else
	{
		DirCollx = -50.0f;
		DirColly = -10.0f;
		AttackCollx = -130.0f;
		AttackColly = -5.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 120, 120);

	if (Ani_Now >= 0 && Ani_Now <= 6)
	{
		m_SecondAttack.Init_Collision(_tag + "Attack2", _posx + AttackCollx, _posy + AttackColly, 150, 140);
	}
	if (Ani_Now == 8)
	{
		m_SecondAttack.DeleteCollision();
	}
}

//Draw�Լ�
void XionSecondAttack::Render(float _posx, float _posy, bool _direction, float _degree, int _sizex, int _sizey)
{
	float tmp_pos;
	if (_direction)
	{
		tmp_pos = 20;
	}
	else
	{
		tmp_pos = -20;
	}
	DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx + tmp_pos, _posy, _direction, _degree, _sizex, _sizey);
	m_Coll.Draw_Collision();
	m_SecondAttack.Draw_Collision();
}


//���� ���·� ��ȯ(override)
void XionSecondAttack::Enter()
{
	Ani_Now = 0;
	Delay = 120.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//���� ��Ȳ���� �� �ൿ(override)
void XionSecondAttack::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool XionSecondAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	Delay = 0.0f;
	return true;
}