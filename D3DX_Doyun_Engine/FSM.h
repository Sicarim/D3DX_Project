#pragma once
#include "DoEngine.h"

namespace DoEngine
{
	/**
	* @brief 행동들을 정의할 추상 클래스
	* @detail 각 행동을 실행할 FSM을 정의한다.
	*/
	class FSM
	{
	protected:
		DoEngine::State*	BeforeState; //이전 행동, 현재 행동을 행하기전 바로 이전 행동
		State*				m_pCurrentState; //현재 캐릭터 상태
		int					curState;
		bool				isEnd;
	public:
		FSM();
		virtual ~FSM();
	public:
		virtual void Init(int _posx, int _posy) = 0;										//FSM 초기화
		virtual void Input(int _curState) = 0;												//FSM Input
		virtual void Update(string _tag, float _posx, float _posy, bool _direction) = 0;	//FSM Update
		virtual void UpdateTime(float _fETime) = 0;											//FSM UpdateTime
		void ChangeState(State* _newstate, bool _skill = false);													//현재 상태 바꾸기
		virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f) = 0; //FSM Draw
	};
}