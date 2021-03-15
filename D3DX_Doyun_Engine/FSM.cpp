#include "FSM.h"

namespace DoEngine
{
	//������
	FSM::FSM()
	{
		curState = 0;
		m_pCurrentState = NULL;
		isEnd = true;
	}

	//���� ���� �ٲٱ�
	void FSM::ChangeState(State* _newstate, bool _skill)
	{
		//���� �ൿ�� BeforState�� ��´�
		BeforeState = m_pCurrentState;

		if (m_pCurrentState != NULL)
		{
			isEnd = m_pCurrentState->Exit(); //���� �ൿ�� ������.
		}
		if (isEnd)
		{
			m_pCurrentState = _newstate; //���ο� �ൿ�� ��´�.
			m_pCurrentState->set_BeforeState(BeforeState); //���� �ൿ�� ���� �ൿ�� �����ൿ���� �ִ´�.
			m_pCurrentState->Enter();
		}
	}

	//�Ҹ���
	FSM::~FSM()
	{

	}
}