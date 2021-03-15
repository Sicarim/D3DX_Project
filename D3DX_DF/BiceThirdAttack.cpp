#include "BiceThirdAttack.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//������
BiceThirdAttack::BiceThirdAttack()
{
}

//�Ҹ���
BiceThirdAttack::~BiceThirdAttack()
{
}

//Init�Լ�(override)
void BiceThirdAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\Attack3\\", 11);
}

//Update�Լ�(override)
void BiceThirdAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = 0.0f;
		DirColly = -10.0f;
		AttackCollx = 80.0f;
		AttackColly = -120.0f;
	}
	else
	{
		DirCollx = -160.0f;
		DirColly = -10.0f;
		AttackCollx = -240.0f;
		AttackColly = -120.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 120, 180);

	if (Ani_Now >= 3 && Ani_Now <= 4)
	{
		m_ThirdAttack.Init_Collision(_tag + "Attack3", _posx + AttackCollx, _posy, 100, 120);
	}
	else if (Ani_Now == 5)
	{
		m_ThirdAttack.DeleteCollision();
	}
	else if (Ani_Now >= 6 && Ani_Now <= 8)
	{
		m_ThirdAttack.Init_Collision(_tag + "Attack3", _posx + AttackCollx, _posy + AttackColly, 150, 210);
	}
	else if (Ani_Now == 9)
	{
		m_ThirdAttack.DeleteCollision();
	}
}

//���� ���·� ��ȯ(override)
void BiceThirdAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceThirdAttack::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceThirdAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	UIManager::get_Instance()->Return_IsAttack();
	return true;
}