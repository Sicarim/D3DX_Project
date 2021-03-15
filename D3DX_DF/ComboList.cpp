#include "ComboList.h"

//생성자
ComboList::ComboList()
{
	//Log.Create("Log");
}

//소멸자
ComboList::~ComboList()
{

}

//초기화
void ComboList::Init()
{
	head_Node	= NULL;
	Tail_Node	= NULL;
	cur_Node	= NULL;
	new_Node	= NULL;
	NodeCount	= 0;

	AnswerCount = 0;
	BeforeTime	= 0.0f;
	CommandNum	= 0;
}

//데이터 삽입
void ComboList::Push(int _data, float _time)
{
	inputKey.push_back(_data);
	NodeCount++;

	new_Node = new Node;
	new_Node->Data = _data;
	new_Node->Time = _time;
	new_Node->Next = NULL;

	if (head_Node == NULL)
	{
		head_Node = new_Node;
	}
	else
	{
		Tail_Node->Next = new_Node;
	}

	Tail_Node = new_Node;


	Node* tmp_Node;
	tmp_Node = head_Node;

	Log.printf("List 내부: ");
	while (tmp_Node != NULL)
	{
		wsprintf(buf, "%d->", tmp_Node->Data);
		Log.printf(buf);

		tmp_Node = tmp_Node->Next;
	}
	Log.printf("\n");
}

//데이터 삭제
void ComboList::Pop()
{
	Node* tmp_PopNode;
	tmp_PopNode = head_Node;

	if (tmp_PopNode != NULL)
	{
		head_Node = head_Node->Next;
	}

	delete tmp_PopNode;
}

//데이터 검색
bool ComboList::Find(int _data[], int _count)
{
	Node*		tmp_SerchNode;

	tmp_SerchNode = head_Node;

	while (tmp_SerchNode != NULL)
	{
		//->//////->-> 인식 못함
		//노드를 찾았다면
		if (tmp_SerchNode->Data == _data[CommandNum])
		{
			if (CommandNum == 0)
			{
				//첫 노드의 시간을 저장
				BeforeTime = tmp_SerchNode->Time;
				CommandNum++;
				AnswerCount++;
			}
			else
			{
				if (tmp_SerchNode->Time - BeforeTime < 0.8f)
				{
					CommandNum++;
					AnswerCount++;
					BeforeTime = tmp_SerchNode->Time;
				}
			}
		}

		if (AnswerCount == _count)
		{
			//break;
			BeforeTime = 0.0f;
			AnswerCount = 0;
			CommandNum = 0;
			Log.printf("스킬 발동!");
			Log.printf("\n");
			return true;
		}
		//찾지 못했다면 다음 노드를 탐색
		tmp_SerchNode = tmp_SerchNode->Next;
		
	}
	BeforeTime = 0.0f;
	CommandNum = 0;
	AnswerCount = 0;
	return false;
}

//데이터 전체 삭제
void ComboList::Clear()
{
	while (head_Node != NULL)
	{
		Pop();
	}
	NodeCount = 0;
}

//List갯수 리턴
int ComboList::get_size()
{
	return NodeCount;
}