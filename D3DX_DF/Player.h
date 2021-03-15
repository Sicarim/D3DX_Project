#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GameManager.h"

class Player : public DoEngine::UserScript
{
private:
	DoEngine::Object*	Player_Charecter;	//플레이어
	float				Player_HP;			//플레이어 체력
	bool				isDie;
public:
	Player();	//생성자
	~Player();	//소멸자
public:
	void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);
	bool Input(int _state);
	void Update(float _fETime);
	void Render();
	void Release();

	DoEngine::Object* ReturnObject();
};