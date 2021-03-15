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
	UIManager(); //������
	~UIManager(); //�Ҹ���

public:
	void UI_Init(); //UI�ʱ�ȭ
	void UI_Update(float _fETime); //UI Update
	void UI_Render();//UI �׸���
	void UI_Release(); //UI ����

	void set_Damege(string _Mytag, float _num); //������ ����
	void Return_IsAttack(); //Attack �ǵ�����

	void set_isBirth(string _tag, bool _isBirth); //ĳ���� ź�� ����
	bool get_isBirth(); //ĳ���� ź�� ���� ����
	bool get_IsCharBirth(string _tag); //�÷��̾� �����Ϸ�
};