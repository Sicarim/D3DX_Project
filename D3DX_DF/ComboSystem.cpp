#include "ComboSystem.h"

//생성자
ComboSystem::ComboSystem()
{	

}

//소멸자
ComboSystem::~ComboSystem()
{

}

//키 입력
void ComboSystem::InputCommand(int _key)
{
	//이전키를 저장한다
	BeforeKey = curKey;

	if (BeforeKey != _key)
	{
		//만약 키를 때고 다시 눌럿다면
		if (_key != LEFT_KEYUP && _key != RIGHT_KEYUP)
		{
			Combo_Buffer.Push(_key, sumTime);
		}
	}
	//키를 현재키에 저장
	curKey = _key;
}

//Queue를 비운다
void ComboSystem::ClearQueue(queue<int>& qBuffer)
{
	//버퍼를 clear하기 위한 빈 큐
	queue<int> empty_Queue;
	swap(qBuffer, empty_Queue);
}