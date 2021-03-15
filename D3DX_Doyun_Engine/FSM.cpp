#include "FSM.h"

namespace DoEngine
{
	//생성자
	FSM::FSM()
	{
		curState = 0;
		m_pCurrentState = NULL;
		isEnd = true;
	}

	//현재 상태 바꾸기
	void FSM::ChangeState(State* _newstate, bool _skill)
	{
		//현재 행동을 BeforState에 담는다
		BeforeState = m_pCurrentState;

		if (m_pCurrentState != NULL)
		{
			isEnd = m_pCurrentState->Exit(); //현재 행동을 끝낸다.
		}
		if (isEnd)
		{
			m_pCurrentState = _newstate; //새로운 행동을 담는다.
			m_pCurrentState->set_BeforeState(BeforeState); //이전 행동을 현재 행동의 이전행동으로 넣는다.
			m_pCurrentState->Enter();
		}
	}

	//소멸자
	FSM::~FSM()
	{

	}
}