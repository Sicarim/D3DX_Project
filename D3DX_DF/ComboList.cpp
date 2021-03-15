#include "ComboList.h"

//������
ComboList::ComboList()
{
	//Log.Create("Log");
}

//�Ҹ���
ComboList::~ComboList()
{

}

//�ʱ�ȭ
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

//������ ����
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

	Log.printf("List ����: ");
	while (tmp_Node != NULL)
	{
		wsprintf(buf, "%d->", tmp_Node->Data);
		Log.printf(buf);

		tmp_Node = tmp_Node->Next;
	}
	Log.printf("\n");
}

//������ ����
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

//������ �˻�
bool ComboList::Find(int _data[], int _count)
{
	Node*		tmp_SerchNode;

	tmp_SerchNode = head_Node;

	while (tmp_SerchNode != NULL)
	{
		//->//////->-> �ν� ����
		//��带 ã�Ҵٸ�
		if (tmp_SerchNode->Data == _data[CommandNum])
		{
			if (CommandNum == 0)
			{
				//ù ����� �ð��� ����
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
			Log.printf("��ų �ߵ�!");
			Log.printf("\n");
			return true;
		}
		//ã�� ���ߴٸ� ���� ��带 Ž��
		tmp_SerchNode = tmp_SerchNode->Next;
		
	}
	BeforeTime = 0.0f;
	CommandNum = 0;
	AnswerCount = 0;
	return false;
}

//������ ��ü ����
void ComboList::Clear()
{
	while (head_Node != NULL)
	{
		Pop();
	}
	NodeCount = 0;
}

//List���� ����
int ComboList::get_size()
{
	return NodeCount;
}