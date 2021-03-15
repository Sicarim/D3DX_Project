#pragma once
#include "DoEngine.h"
#include "Singleton.h"
#include "defines.h"

class UIManager : public Singleton<UIManager>
{
private:
	LPDIRECT3DTEXTURE9	m_tPlayer_HealthBar;
	LPDIRECT3DTEXTURE9	m_tPlayer_Health;
	LPDIRECT3DTEXTURE9	m_tEnemy_HealthBar;
	LPDIRECT3DTEXTURE9	m_tEnemy_Health;
	LPDIRECT3DTEXTURE9	m_tPlayerWin;
	LPDIRECT3DTEXTURE9	m_tEnemyWin;

	vector<LPDIRECT3DTEXTURE9>	m_tNumber;
	DoEngine::State*			m_UIAni; //UIAnimation

	bool PlayerBirth, EnemyBirth, BirthComplate;

	float	Player_Health;
	float	Enemy_Health;
	float	curTime;
	bool	isAttack;
	int		StartCount;
	TCHAR	buf[255];

public:
	UIManager(); //생성자
	~UIManager(); //소멸자

public:
	void UI_Init(); //UI초기화
	void UI_Update(float _fETime); //UI Update
	void UI_Render();//UI 그리기
	void UI_Release(); //UI 삭제

	void set_Damege(string _Mytag, float _num); //데미지 삽입
	void Return_IsAttack(); //Attack 되돌리기

	void set_isBirth(string _tag, bool _isBirth); //캐릭터 탄생 여부
	bool get_isBirth(); //캐릭터 탄생 여부 리턴
	bool get_IsCharBirth(string _tag); //플레이어 생성완료
};