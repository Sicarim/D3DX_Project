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
	StartScene(); //생성자
	~StartScene(); //소멸자
public:
	virtual void Init();				//Scene 초기화(override)
	virtual bool Input(float _fETime);	//Scene내에서 입력(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene 그리기(override)
	virtual void Release();					//Scene 지우기
};