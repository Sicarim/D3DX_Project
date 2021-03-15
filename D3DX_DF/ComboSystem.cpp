#include "ComboSystem.h"

//������
ComboSystem::ComboSystem()
{	

}

//�Ҹ���
ComboSystem::~ComboSystem()
{

}

//Ű �Է�
void ComboSystem::InputCommand(int _key)
{
	//����Ű�� �����Ѵ�
	BeforeKey = curKey;

	if (BeforeKey != _key)
	{
		//���� Ű�� ���� �ٽ� �����ٸ�
		if (_key != LEFT_KEYUP && _key != RIGHT_KEYUP)
		{
			Combo_Buffer.Push(_key, sumTime);
		}
	}
	//Ű�� ����Ű�� ����
	curKey = _key;
}

//Queue�� ����
void ComboSystem::ClearQueue(queue<int>& qBuffer)
{
	//���۸� clear�ϱ� ���� �� ť
	queue<int> empty_Queue;
	swap(qBuffer, empty_Queue);
}