#pragma once
#include "DoEngine.h"
#include "defines.h"

//리스트 구조체 선언
struct ComboList
{
	int					Value;	//노드 값
	struct ComboList*	next;	//다음 주소
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
	BiceComboList();	//생성자
	~BiceComboList();	//소멸자
public:
	void MakeCommand();	//커맨드 만들기
	void Skill_Dash();	//Dash Skill
	//return Skill_Cobo
};