#include "BiceFirstAttack.h"
#include "AnimationMaker.h"
#include "UIManager.h"

//������
BiceFirstAttack::BiceFirstAttack()
{
}

//�Ҹ���
BiceFirstAttack::~BiceFirstAttack()
{
}

//Init�Լ�(override)
void BiceFirstAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Attack\\Attack1\\", 10);
}

//Update�Լ�(override)
void BiceFirstAttack::Update(string _tag, float _posx, float _posy, bool _direction)
{
	if (_direction)
	{
		DirCollx = 5.0f;
		DirColly = -10.0f;
		AttackCollx = -50.0f;
		AttackColly = 10.0f;
	}
	else
	{
		DirCollx = -130.0f;
		DirColly = -10.0f;
		AttackCollx = -175.0f;
		AttackColly = 10.0f;
	}

	m_Coll.Init_Collision(_tag, _posx + DirCollx, _posy + DirColly, 100, 180);

	if (Ani_Now >= 4 && Ani_Now < 9)
	{
		m_FirstAttack.Init_Collision(_tag + "Attack1", _posx + AttackCollx, _posy + AttackColly, 200, 150);
	}
	if (Ani_Now == 8)
	{
		m_FirstAttack.DeleteCollision();
	}
}

//���� ���·� ��ȯ(override)
void BiceFirstAttack::Enter()
{
	Ani_Now = 0;
	Delay = 50.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceFirstAttack::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceFirstAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}
	UIManager::get_Instance()->Return_IsAttack();
	Delay = 0.0f;
	return true;
}