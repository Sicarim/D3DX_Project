#pragma once
#include "ComboSystem.h"

class BiceComboSystem : public ComboSystem
{
private:
	//��ų ����
	int			BiceSkiil_Command[4] = { LEFT, RIGHT, RIGHT, ATTACK };

	//��ų ��� ����, ��Ÿ�� ����
	bool		isBiceSkill;			//Skill ��� ����
	float		SkillColTime;
public:
	BiceComboSystem();	//������
	virtual ~BiceComboSystem(); //�Ҹ���
public:
	virtual void	Init();
	virtual int		OutputKey();					//Ű ���(override)
	virtual int		CheckCommand();					//����� üũ�Ѵ�.(override)
	virtual void	ComboUpdate(float _fETime);		//Combo_System Update(override)
	virtual void	Combo_Release();				//ComboSystem �ʱ�ȭ(override)

	bool			Bice_Skill();							//BiceSkill
};