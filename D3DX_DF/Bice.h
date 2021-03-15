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
	Bice(); //생성자
	virtual ~Bice(); //소멸자
public:
	virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);	//초기화(override)
	virtual bool Input(int _state = 0);			//Object 입력(override)
	virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);			//Update함수(override)
	virtual void Render();						//Draw 함수(override)
};