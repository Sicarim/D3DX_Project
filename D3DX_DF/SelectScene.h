#pragma once
#include "DoEngine.h"
#include "defines.h"

class SelectScene : public DoEngine::Scene
{
private:
	vector<DoEngine::State*>	StandingMotion;
	LPDIRECT3DTEXTURE9			BackGround;

	LPDIRECT3DTEXTURE9			CutScene;
	float						ScenePos;

	LPDIRECT3DTEXTURE9			AICutScene;
	float						AIScenePos;

	float						curTiem;
	float						ChangePos;
	int							ButtonCount;
	int							AI_Select;
	bool						PlayerSelectDone;

	float						AITiem;
	int							AiCharSelect, SelectCount;
	bool							AISelectDone;


	bool GameStart;
public:
	SelectScene(); //생성자
	~SelectScene(); //소멸자
public:
	virtual void Init();				//Scene 초기화(override)
	virtual bool Input(float _fETime);	//Scene내에서 입력(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene 그리기(override)
	virtual void Release();					//Scene 지우기
};