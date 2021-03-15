#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "EnemyAI.h"
#include "Player.h"
#include "InputHandler.h"

class GameScene : public DoEngine::Scene
{
private:
	/*DoEngine::Object* m_Bice;
	DoEngine::Object* m_Uclid;
	DoEngine::Object* m_Xion;*/
	//DoEngine::Object*			m_Player;	//�÷��̾�
	//DoEngine::Object*			m_AI;		//Enemy
	//EnemyAI m_testAI; //Enemy

	vector<LPDIRECT3DTEXTURE9>	BackGround;	//��ü ��

	DoEngine::UserScript*		m_Player;	//�÷��̾�
	DoEngine::UserScript*		m_Enemy;	//Enemy

	//�÷��̾ ������ Ŀ�ǵ� ��ü ����
	DoEngine::Command*			m_Command;
	InputHandler				m_Input;
public:
	GameScene(); //������
	~GameScene(); //�Ҹ���

public:
	virtual void Init();				//Scene �ʱ�ȭ(override)
	virtual bool Input(float _fETime);	//Scene������ �Է�(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene �׸���(override)
	virtual void Release();					//Scene �����
};