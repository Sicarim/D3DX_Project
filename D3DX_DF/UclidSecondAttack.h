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
	UclidSecondAttack(); //������
	~UclidSecondAttack(); //�Ҹ���
public:
	virtual void Init();						//Init�Լ�(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);			//Update�Լ�(override)
	virtual void Enter();						//���� ���·� ��ȯ(override)
	virtual void Excute();						//���� ��Ȳ���� �� �ൿ(override)
	virtual bool Exit();						//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
	virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);	//Draw�Լ�
};