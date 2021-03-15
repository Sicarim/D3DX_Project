#pragma once
#include "DoEngine.h"
#include "XionFSM.h"
#include "defines.h"

class Xion : public DoEngine::Object
{
private:
	DoEngine::FSM*		m_FSM;
	string				Char_Tag;
	bool				Direction;
	float				curTime;
	bool				isDie;
public:
	Xion(); //생성자
	virtual ~Xion(); //소멸자
public:
	virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);	//초기화(override)
	virtual bool Input(int _state = 0);			//Object 입력(override)
	virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);			//Update함수(override)
	virtual void Render();						//Draw 함수(override)
};