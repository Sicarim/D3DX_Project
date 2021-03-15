#include "BiceComboSystem.h"

//생성자
BiceComboSystem::BiceComboSystem()
{
	SkillColTime	= 0.0f;
	isBiceSkill		= true;
}

//소멸자
BiceComboSystem::~BiceComboSystem()
{

}

void BiceComboSystem::Init()
{
	sumTime = 0.0f;
	delTime = 0.0f;
	Combo_Buffer.Init();
}

//키 출력(override)
int BiceComboSystem::OutputKey()
{
	return CheckCommand();
}

//기술을 체크한다.(override)
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
	//흐르는 시간을 저장한다.
	sumTime += _fETime;

	//콤보 버퍼 크기가 1이상이라면
	if (Combo_Buffer.get_size() > 0)
	{
		delTime += _fETime;
		//3초마다 가장 앞의 노드를 삭제
		if (delTime > 3.0f)
		{
			Combo_Buffer.Pop();
			delTime = 0.0f;
		}
	}

	////////쿨타임////////
	//BiceSkill
	if (!isBiceSkill)
	{
		//스킬을 사용했다면, 흐른 시간을 저장한다.
		SkillColTime += _fETime;
		
		//2초가 지나면 스킬 상태를 스킬 사용상태 유무를 true로 바꾼다
		if (SkillColTime > 2.0f)
		{
			isBiceSkill = true;
			SkillColTime = 0.0f;
		}
	}
}

//ComboSystem 초기화(override)
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