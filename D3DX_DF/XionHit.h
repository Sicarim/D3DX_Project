#pragma once
#include "DoEngine.h"
#include "defines.h"

class XionHit : public DoEngine::State
{
private:
public:
	XionHit(); //소멸자
	~XionHit(); //생성자
public:
	virtual void Init();						//Init함수(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);			//Update함수(override)
	virtual void Enter();						//다음 상태로 전환(override)
	virtual void Excute();						//현재 상황에서 할 행동(override)
	virtual bool Exit();						//다음 상황으로 넘어가기전 해야하는 행동(override)
};