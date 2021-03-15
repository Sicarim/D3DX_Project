#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GameManager.h"
#include "TriggerCollision.h"

class EnemyAI : public DoEngine::UserScript
{
private:
	DoEngine::Object*	Enemy_Charecter;	//플레이어
	float				Enemy_HP;			//적 체력
	bool				isDie;
public:
	EnemyAI();	//생성자
	~EnemyAI();	//소멸자
public:
	void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);
	bool Input(int _state);
	void Update(float _fETime);
	void Render();
	void Release();

	DoEngine::Object* ReturnObject();
};

//class EnemyAI
//{
//private:
//	DoEngine::Object*			m_AI;		//Enemy
//	DoEngine::TriggerCollision	m_triggerColl;
//	float						posX, posY;
//	float						curTime;
//	string						tag;
//
//	int							curState;
//	int							AttackCount;
//
//	bool						direction;
//	bool						isCollision;
//	bool Dash;
//public:
//	EnemyAI();	//생성자
//	~EnemyAI(); //소멸자
//public:
//	void SelectAI(DoEngine::Object* _charecter);	//캐릭터 선택
//	void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);
//	bool Input(int _state);
//	void Update(float _fETime);
//	void Render();
//	void Release();
//
//	DoEngine::Object* ReturnObject();
//
//	void AI_FSM(); //AI의 행동들을 정의
//};


