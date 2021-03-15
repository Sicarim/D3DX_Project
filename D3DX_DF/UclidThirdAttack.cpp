#include "UclidThirdAttack.h"
#include "AnimationMaker.h"

//������
UclidThirdAttack::UclidThirdAttack()
{
}

//�Ҹ���
UclidThirdAttack::~UclidThirdAttack()
{
}

//Init�Լ�(override)
void UclidThirdAttack::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Uclid\\Attack\\Attack3\\", 8);
}

//Update�Լ�(override)
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

//���� ���·� ��ȯ(override)
void UclidThirdAttack::Enter()
{
	Ani_Now = 0;
	Delay = 70.0f;
	DirCollx = 0;
	DirCollx = 0;
	AttackCollx = 0;
	AttackColly = 0;
}

//���� ��Ȳ���� �� �ൿ(override)
void UclidThirdAttack::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool UclidThirdAttack::Exit()
{
	if (Ani_Now != curAni.size() - 1)
	{
		return false;
	}

	Delay = 0.0f;
	return true;
}