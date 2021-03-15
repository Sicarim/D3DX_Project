#pragma once
#include "Scene.h"
#include "Object.h"

class S_Game : public DoEngine::Scene	// 씬을 상속받는다.
{
public:
	S_Game();
	~S_Game();

public:
	virtual void Init();
	virtual bool Input(float _fETime);
	virtual void Update(float _fETime);
	virtual void Render();

public:
	// 캐릭터 클래스를 선언
	//O_Char* m_Char;
	DoEngine::Object* m_Char2;
};

