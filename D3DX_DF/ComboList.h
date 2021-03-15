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

	//확인용
	vector<int> inputKey;
public:
	ComboList(); //생성자
	~ComboList(); //소멸자
public:
	void Init(); //초기화
	void Push(int _data, float _time); //데이터 삽입
	void Pop();	//데이터 삭제
	bool Find(int _data[], int _count); //데이터 검색

	void Clear(); //데이터 전체 삭제
	int get_size(); //List갯수 리턴
};