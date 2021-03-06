#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "AnimationMaker.h"
#include "Collision.h"
#include "FSM.h"

class BiceFSM : public DoEngine::FSM
{
private:
	vector<DoEngine::State*>	m_State; //행동들의 집합
	DoEngine::Collision			m_Coll;
	string						EnemyTag; //적 태그
	float						curTime;
	float						BeforeTime;
	float						hit;

	int							state;
	int							Pos_x, Pos_y;
	int							AttackCount, HitCount;

	//AI INFO//
	float HitTime;
public:
	BiceFSM();			//생성자
	virtual ~BiceFSM(); //소멸자
public:
	virtual void Init(int _posx, int _posy);//FSM 초기화(override)
	virtual void Input(int _curState);		//FSM Input(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);		//FSM Update(override)
	virtual void UpdateTime(float _fETime);												//FSM UpdateTime(override)
	virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);//FSM Draw(override)

	bool isHit(string _tag); //피격 판정
};