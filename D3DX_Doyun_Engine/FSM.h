#pragma once
#include "DoEngine.h"

namespace DoEngine
{
	/**
	* @brief �ൿ���� ������ �߻� Ŭ����
	* @detail �� �ൿ�� ������ FSM�� �����Ѵ�.
	*/
	class FSM
	{
	protected:
		DoEngine::State*	BeforeState; //���� �ൿ, ���� �ൿ�� ���ϱ��� �ٷ� ���� �ൿ
		State*				m_pCurrentState; //���� ĳ���� ����
		int					curState;
		bool				isEnd;
	public:
		FSM();
		virtual ~FSM();
	public:
		virtual void Init(int _posx, int _posy) = 0;										//FSM �ʱ�ȭ
		virtual void Input(int _curState) = 0;												//FSM Input
		virtual void Update(string _tag, float _posx, float _posy, bool _direction) = 0;	//FSM Update
		virtual void UpdateTime(float _fETime) = 0;											//FSM UpdateTime
		void ChangeState(State* _newstate, bool _skill = false);													//���� ���� �ٲٱ�
		virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f) = 0; //FSM Draw
	};
}