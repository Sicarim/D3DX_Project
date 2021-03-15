#pragma once
#pragma once
#include "DoEngine.h"
#include "defines.h"

class SelectMapScene : public DoEngine::Scene
{
private:
	int							Map_Num;
	TCHAR						buf[255];
	vector<LPDIRECT3DTEXTURE9>	MiniBackGround; //미니 맵
	vector<LPDIRECT3DTEXTURE9>	BackGround;		//전체 맵
public:
	SelectMapScene(); //생성자
	~SelectMapScene(); //소멸자
public:
	virtual void Init();				//Scene 초기화(override)
	virtual bool Input(float _fETime);	//Scene내에서 입력(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene 그리기(override)
	virtual void Release();					//Scene 지우기
};