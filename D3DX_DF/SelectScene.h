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
	SelectScene(); //������
	~SelectScene(); //�Ҹ���
public:
	virtual void Init();				//Scene �ʱ�ȭ(override)
	virtual bool Input(float _fETime);	//Scene������ �Է�(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene �׸���(override)
	virtual void Release();					//Scene �����
};