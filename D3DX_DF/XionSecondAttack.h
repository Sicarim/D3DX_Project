#pragma once
#include "DoEngine.h"
#include "defines.h"

class XionSecondAttack : public DoEngine::State
{
private:
	DoEngine::Collision m_SecondAttack;
	float AttackCollx;
	float AttackColly;
public:
	XionSecondAttack(); //������
	~XionSecondAttack(); //�Ҹ���
public:
	virtual void Init();						//Init�Լ�(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);			//Update�Լ�(override)
	virtual void Enter();						//���� ���·� ��ȯ(override)
	virtual void Excute();						//���� ��Ȳ���� �� �ൿ(override)
	virtual bool Exit();						//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
	virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, int _sizex = 1, int _sizey = 1);	//Draw�Լ�
};
