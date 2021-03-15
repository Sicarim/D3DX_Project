#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
private:
	int		Select_Character;
	int		Select_AI;
	int		Select_Map;
	int		RedBlue;

	float	Motion_Delay;
	float	curTime;

	bool	FightStart, FightEnd;
	bool	PlayerDie, EnemyDie, CharDie;
	bool	GameEnd;

	//AI Info//
	float	AI_posX, AI_posY;
	int		HitCount;

public:
	GameManager();						//������
	~GameManager();						//�Ҹ���
public:
	void Game_Init();					//���� �ʱ�ȭ
	void Key_Init();					//Ű ���
	void Regist_Scene();				//Scene ���
	void Update(float _fETime);			//Update �Լ�
	void Game_Release();				//Release�Լ�
	void ChangeFightStart();			//�ο� ����

	DoEngine::Object* get_PlayerSelect();			//ĳ����(Player) ���� ����
	void set_PlayerSelect(int _num);				//ĳ����(Player) ���� ����

	DoEngine::Object* get_AISelect();				//ĳ����(AI) ���� ����
	void set_AISelect(int _num);					//ĳ����(AI) ���� ����

	int get_MapSelect();							//ĳ����(AI) ���� ����
	void set_MapSelect(int _num);					//ĳ����(AI) ���� ����

	
	void set_IsDie(bool _isDie);					//ĳ���� ���� ����
	bool get_IsDie();								//ĳ���� ���� ����

	void set_IsPlayerDie(bool _isDie);				//Player ���� ����
	bool get_IsPlayerDie();							//Player ���� ����

	void set_IsEnemyDie(bool _isDie);				//Enemy ���� ����
	bool get_IsEnemyDie();							//Enemy ���� ����

	float get_MotionDelay();								//������ ����

	bool get_IsFightStart();							//�ο� ����(����) �����Ϸ�
	bool get_IsFightEnd();								//�ο� ����
	bool get_IsGameEnd();								//���� ����
	int get_RedBlue();									//�÷�� �̰����, ���� �̰���� ����
	//void get_IsCharBirth(string _tag, bool _isBirth);//ĳ���� �����Ϸ�

	//AI//
	void set_AIposX(float _posx); //�� ��ġ ����(posX)
	float get_AIposX(); //�� ��ġ ����(posY)
	void set_AIposY(float _posy); //�� ��ġ ����(posY)
	float get_AIposY(); //�� ��ġ ����(posY)
	void set_HitCount(int _count); //�� Ÿ�� �� ����
	int get_HitCount(); //�� Ÿ�� �� ����
	
};