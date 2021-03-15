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
	//DoEngine::Object*			m_Player;	//플레이어
	//DoEngine::Object*			m_AI;		//Enemy
	//EnemyAI m_testAI; //Enemy

	vector<LPDIRECT3DTEXTURE9>	BackGround;	//전체 맵

	DoEngine::UserScript*		m_Player;	//플레이어
	DoEngine::UserScript*		m_Enemy;	//Enemy

	//플레이어를 움직일 커맨드 객체 선언
	DoEngine::Command*			m_Command;
	InputHandler				m_Input;
public:
	GameScene(); //생성자
	~GameScene(); //소멸자

public:
	virtual void Init();				//Scene 초기화(override)
	virtual bool Input(float _fETime);	//Scene내에서 입력(override)
	virtual void Update(float _fETime);	//Scene Update(override)
	virtual void Render();				//Scene 그리기(override)
	virtual void Release();					//Scene 지우기
};