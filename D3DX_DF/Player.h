#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GameManager.h"

class Player : public DoEngine::UserScript
{
private:
	DoEngine::Object*	Player_Charecter;	//�÷��̾�
	float				Player_HP;			//�÷��̾� ü��
	bool				isDie;
public:
	Player();	//������
	~Player();	//�Ҹ���
public:
	void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);
	bool Input(int _state);
	void Update(float _fETime);
	void Render();
	void Release();

	DoEngine::Object* ReturnObject();
};