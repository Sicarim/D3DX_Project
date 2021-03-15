#pragma once
#pragma once
#include "DoEngine.h"
#include "defines.h"

class SelectMapScene : public DoEngine::Scene
{
private:
	int							Map_Num;
	TCHAR						buf[255];
	vector<LPDIRECT3DTEXTURE9>	MiniBackGround; //�̴� ��
	vector<LPDIRECT3DTEXTURE9>	BackGround;		//��ü ��
public:
	SelectMapScene(); //������
	~SelectMapScene(); //�Ҹ���
public:
	virtual void Init();				//Scene �ʱ�ȭ(override)
	virtual bool Input(float _fETime);	//Scene������ �Է�(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene �׸���(override)
	virtual void Release();					//Scene �����
};