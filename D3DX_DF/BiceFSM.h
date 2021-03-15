#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "AnimationMaker.h"
#include "Collision.h"
#include "FSM.h"

class BiceFSM : public DoEngine::FSM
{
private:
	vector<DoEngine::State*>	m_State; //�ൿ���� ����
	DoEngine::Collision			m_Coll;
	string						EnemyTag; //�� �±�
	float						curTime;
	float						BeforeTime;
	float						hit;

	int							state;
	int							Pos_x, Pos_y;
	int							AttackCount, HitCount;

	//AI INFO//
	float HitTime;
public:
	BiceFSM();			//������
	virtual ~BiceFSM(); //�Ҹ���
public:
	virtual void Init(int _posx, int _posy);//FSM �ʱ�ȭ(override)
	virtual void Input(int _curState);		//FSM Input(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);		//FSM Update(override)
	virtual void UpdateTime(float _fETime);												//FSM UpdateTime(override)
	virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);//FSM Draw(override)

	bool isHit(string _tag); //�ǰ� ����
};