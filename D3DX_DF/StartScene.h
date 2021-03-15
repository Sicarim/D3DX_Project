#pragma once
#include "DoEngine.h"
#include "defines.h"

class StartScene : public DoEngine::Scene
{
private:
	vector<LPDIRECT3DTEXTURE9>	BackGround;

	int Alph, SceneCount;
	bool UpCount, DownCount;
public:
	StartScene(); //������
	~StartScene(); //�Ҹ���
public:
	virtual void Init();				//Scene �ʱ�ȭ(override)
	virtual bool Input(float _fETime);	//Scene������ �Է�(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene �׸���(override)
	virtual void Release();					//Scene �����
};