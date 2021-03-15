#include "BiceComboSystem.h"

//������
BiceComboSystem::BiceComboSystem()
{
	SkillColTime	= 0.0f;
	isBiceSkill		= true;
}

//�Ҹ���
BiceComboSystem::~BiceComboSystem()
{

}

void BiceComboSystem::Init()
{
	sumTime = 0.0f;
	delTime = 0.0f;
	Combo_Buffer.Init();
}

//Ű ���(override)
int BiceComboSystem::OutputKey()
{
	return CheckCommand();
}

//����� üũ�Ѵ�.(override)
int BiceComboSystem::CheckCommand()
{
	int Command = 0;

	//BiceSkill
	if (isBiceSkill)
	{
		if (Bice_Skill())
		{
			Command = BICE_ATTACK_SKILL;
			isBiceSkill = false;
		}
	}

	return Command;
}

//Combo_System Update(override)
void BiceComboSystem::ComboUpdate(float _fETime)
{
	//�帣�� �ð��� �����Ѵ�.
	sumTime += _fETime;

	//�޺� ���� ũ�Ⱑ 1�̻��̶��
	if (Combo_Buffer.get_size() > 0)
	{
		delTime += _fETime;
		//3�ʸ��� ���� ���� ��带 ����
		if (delTime > 3.0f)
		{
			Combo_Buffer.Pop();
			delTime = 0.0f;
		}
	}

	////////��Ÿ��////////
	//BiceSkill
	if (!isBiceSkill)
	{
		//��ų�� ����ߴٸ�, �帥 �ð��� �����Ѵ�.
		SkillColTime += _fETime;
		
		//2�ʰ� ������ ��ų ���¸� ��ų ������ ������ true�� �ٲ۴�
		if (SkillColTime > 2.0f)
		{
			isBiceSkill = true;
			SkillColTime = 0.0f;
		}
	}
}

//ComboSystem �ʱ�ȭ(override)
void BiceComboSystem::Combo_Release()
{
	Combo_Buffer.Clear();
}

//BiceSkill
bool BiceComboSystem::Bice_Skill()
{
	if (Combo_Buffer.Find(BiceSkiil_Command, 4))
	{
		Combo_Buffer.Clear();
		return true;
	}
	else
	{
		return false;
	}
}