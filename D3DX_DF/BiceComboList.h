#pragma once
#include "DoEngine.h"
#include "defines.h"

//����Ʈ ����ü ����
struct ComboList
{
	int					Value;	//��� ��
	struct ComboList*	next;	//���� �ּ�
};

class BiceComboList
{
private:
	vector<ComboList> BiceSkill;
	ComboList* head_Node;
	ComboList* tail_Node;
	ComboList* cur_Node;
	ComboList* new_Node;

	int LeftSkilDash[2];
	int RightSkilDash[2];

public:
	BiceComboList();	//������
	~BiceComboList();	//�Ҹ���
public:
	void MakeCommand();	//Ŀ�ǵ� �����
	void Skill_Dash();	//Dash Skill
	//return Skill_Cobo
};