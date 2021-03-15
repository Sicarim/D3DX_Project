#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GameManager.h"
#include "TriggerCollision.h"

class EnemyAI : public DoEngine::UserScript
{
private:
	DoEngine::Object*	Enemy_Charecter;	//�÷��̾�
	float				Enemy_HP;			//�� ü��
	bool				isDie;
public:
	EnemyAI();	//������
	~EnemyAI();	//�Ҹ���
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
//	EnemyAI();	//������
//	~EnemyAI(); //�Ҹ���
//public:
//	void SelectAI(DoEngine::Object* _charecter);	//ĳ���� ����
//	void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);
//	bool Input(int _state);
//	void Update(float _fETime);
//	void Render();
//	void Release();
//
//	DoEngine::Object* ReturnObject();
//
//	void AI_FSM(); //AI�� �ൿ���� ����
//};


