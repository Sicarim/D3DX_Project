#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "BiceFSM.h"
#include "BiceComboSystem.h"

class Bice : public DoEngine::Object
{
private:
	DoEngine::FSM*		m_FSM;
	BiceComboSystem*	m_Combo; //ComboSystem
	string				Char_Tag;
	float				curTime;
	float				sizeX, sizeY;
	bool				Direction; 

	int curState;
	int BiceSkiil;
public:
	Bice(); //������
	virtual ~Bice(); //�Ҹ���
public:
	virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);	//�ʱ�ȭ(override)
	virtual bool Input(int _state = 0);			//Object �Է�(override)
	virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);			//Update�Լ�(override)
	virtual void Render();						//Draw �Լ�(override)
};