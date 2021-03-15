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
	GameManager();						//생성자
	~GameManager();						//소멸자
public:
	void Game_Init();					//게임 초기화
	void Key_Init();					//키 등록
	void Regist_Scene();				//Scene 등록
	void Update(float _fETime);			//Update 함수
	void Game_Release();				//Release함수
	void ChangeFightStart();			//싸움 시작

	DoEngine::Object* get_PlayerSelect();			//캐릭터(Player) 선택 리턴
	void set_PlayerSelect(int _num);				//캐릭터(Player) 선택 삽입

	DoEngine::Object* get_AISelect();				//캐릭터(AI) 선택 리턴
	void set_AISelect(int _num);					//캐릭터(AI) 선택 삽입

	int get_MapSelect();							//캐릭터(AI) 선택 리턴
	void set_MapSelect(int _num);					//캐릭터(AI) 선택 삽입

	
	void set_IsDie(bool _isDie);					//캐릭터 죽음 삽입
	bool get_IsDie();								//캐릭터 죽음 리턴

	void set_IsPlayerDie(bool _isDie);				//Player 죽음 삽입
	bool get_IsPlayerDie();							//Player 죽음 리턴

	void set_IsEnemyDie(bool _isDie);				//Enemy 죽음 삽입
	bool get_IsEnemyDie();							//Enemy 죽음 리턴

	float get_MotionDelay();								//딜레이 리턴

	bool get_IsFightStart();							//싸움 시작(게임) 생성완료
	bool get_IsFightEnd();								//싸움 종료
	bool get_IsGameEnd();								//게임 종료
	int get_RedBlue();									//플레어가 이겼는지, 적이 이겼는지 리턴
	//void get_IsCharBirth(string _tag, bool _isBirth);//캐릭터 생성완료

	//AI//
	void set_AIposX(float _posx); //적 위치 삽입(posX)
	float get_AIposX(); //적 위치 리턴(posY)
	void set_AIposY(float _posy); //적 위치 삽입(posY)
	float get_AIposY(); //적 위치 삽입(posY)
	void set_HitCount(int _count); //적 타격 수 삽입
	int get_HitCount(); //적 타격 수 삽입
	
};