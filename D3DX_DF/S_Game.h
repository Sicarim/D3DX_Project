#pragma once
#include "Scene.h"
#include "Object.h"

class S_Game : public DoEngine::Scene	// ���� ��ӹ޴´�.
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
	// ĳ���� Ŭ������ ����
	//O_Char* m_Char;
	DoEngine::Object* m_Char2;
};

