#pragma once
#include "ComboSystem.h"

class BiceComboSystem : public ComboSystem
{
private:
	//스킬 정의
	int			BiceSkiil_Command[4] = { LEFT, RIGHT, RIGHT, ATTACK };

	//스킬 사용 유무, 쿨타임 관리
	bool		isBiceSkill;			//Skill 사용 유무
	float		SkillColTime;
public:
	BiceComboSystem();	//생성자
	virtual ~BiceComboSystem(); //소멸자
public:
	virtual void	Init();
	virtual int		OutputKey();					//키 출력(override)
	virtual int		CheckCommand();					//기술을 체크한다.(override)
	virtual void	ComboUpdate(float _fETime);		//Combo_System Update(override)
	virtual void	Combo_Release();				//ComboSystem 초기화(override)

	bool			Bice_Skill();							//BiceSkill
};