#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "ConsoleLogger.h"

struct Node
{
	int Data;
	float Time;
	Node* Next;
};

class ComboList
{
private:	
	CConsoleLogger Log;
	TCHAR buf[255];


	int		NodeCount;
	Node*	head_Node;
	Node*	Tail_Node;
	Node*	cur_Node;
	Node*	new_Node;

	int		AnswerCount;
	int		CommandNum;
	float	BeforeTime;

	//Ȯ�ο�
	vector<int> inputKey;
public:
	ComboList(); //������
	~ComboList(); //�Ҹ���
public:
	void Init(); //�ʱ�ȭ
	void Push(int _data, float _time); //������ ����
	void Pop();	//������ ����
	bool Find(int _data[], int _count); //������ �˻�

	void Clear(); //������ ��ü ����
	int get_size(); //List���� ����
};