#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Collision.h"

class BiceStanding : public DoEngine::State
{
private:
public:
	BiceStanding(); //�Ҹ���
	~BiceStanding(); //������
public:
	virtual void Init();						//Init�Լ�(override)
	virtual void Update(string _tag, float _posx, float _posy, bool _direction);			//Update�Լ�(override)
	virtual void Enter();						//���� ���·� ��ȯ(override)
	virtual void Excute();						//���� ��Ȳ���� �� �ൿ(override)
	virtual bool Exit();						//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
};