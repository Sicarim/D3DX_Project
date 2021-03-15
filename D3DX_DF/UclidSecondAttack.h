#pragma once
#include "DoEngine.h"
#include "defines.h"

class UclidSecondAttack : public DoEngine::State
{
private:
	float AttackCollx;
	float AttackColly;
	DoEngine::Collision m_SecondAttack;
public:
	UclidSecondAttack(); //생성자
	~UclidSecondAttack(); //소멸자
public:
	virtual void Init();						//Init함수(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);			//Update함수(override)
	virtual void Enter();						//다음 상태로 전환(override)
	virtual void Excute();						//현재 상황에서 할 행동(override)
	virtual bool Exit();						//다음 상황으로 넘어가기전 해야하는 행동(override)
	virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);	//Draw함수
};