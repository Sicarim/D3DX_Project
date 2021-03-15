#include "GameManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "SelectMapScene.h"
#include "GameScene.h"
#include "Bice.h"
#include "Uclid.h"
#include "Xion.h"


//생성기
GameManager::GameManager()
{

}

//게임 초기화
void GameManager::Game_Init()
{
	Select_Character = 0;
	Motion_Delay = 70.0f;
	Select_AI = 0;
	curTime = 0.0f;
	RedBlue = WINLOSE_WAIT;

	CharDie = false;
	PlayerDie = false;
	EnemyDie = false;
	GameEnd = false;

	FightStart = false;

	FightEnd = false;

	//키등록
	Key_Init();
	//Scene등록
	Regist_Scene();

	//AI info//
	AI_posX = 0.0f;
	AI_posY = 0.0f;
	HitCount = 0;
}

//소멸자
GameManager::~GameManager()
{

}

//키 등록
/*
	게임에서 사용할 키를 등록한다.
*/
void GameManager::Key_Init()
{
	//키 비우기
	DoEngine::InputManager::get_Instance()->Clear();
	//방향키 (왼)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LEFT);
	//방향키 (오)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RIGHT);
	//방향키 (위)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_UP);
	//방향키 (아래)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_DOWN);
	//게임 종료
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
	//엔터키
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RETURN);
	//마우스 좌클릭
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LBUTTON);

	//시작버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//공격버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
}

//Scene 등록
/*
	게임을 진행할 Scene들을 등록한다. 이때, defines.h의 등록순서와 일치하도록한다.
*/
void GameManager::Regist_Scene()
{
	DoEngine::SceneManager::get_Instance()->RegistScene(new StartScene); //StartScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new SelectScene); //SelectScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new SelectMapScene); //SelectMapScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene); //GameScene등록
	//ResultScene등록
	//DoEngine::SceneManager::get_Instance()->RegistScene(new ResultScene);
}

//Update 함수
/*
	게임을 시작하는동안 실행될 Update함수
*/
void GameManager::Update(float _fETime)
{
	if (PlayerDie || EnemyDie)
	{
		curTime += _fETime;
		Motion_Delay = END_DELAY;
	}

	//처치시 애니메이션 재생시간
	if (curTime > DIE_TIME)
	{
		Motion_Delay = START_DELAY;
		CharDie = false;
		FightEnd = true;
		if (PlayerDie) //플레이어가 죽었다면
		{
			RedBlue = WINLOSE_BLUE;
		}
		else if (EnemyDie) //Enemy가 죽엇다면
		{
			RedBlue = WINLOSE_RED;
		}
	}

	if (curTime > GAME_ENDDELAY)
	{
		GameEnd = true;
	}
}

//Release함수
/*
	게임 재시작시 필요한 번수들을 지워준다.
*/
void GameManager::Game_Release()
{
	Select_Character = 0;
	Select_AI = 0;
	curTime = 0.0f;
	RedBlue = WINLOSE_WAIT;

	CharDie = false;
	PlayerDie = false;
	EnemyDie = false;


	FightStart = false;
	FightEnd = false;
	GameEnd = false;
}

//캐릭터 선택 리턴
DoEngine::Object* GameManager::get_PlayerSelect()
{
	if (Select_Character == SELECT_BICE)
	{
		return new Bice;
	}
	else if (Select_Character == SELECT_UCLID)
	{
		return new Uclid;
	}
	else if (Select_Character == SELECT_XION)
	{
		return new Xion;
	}
}

//캐릭터 선택 삽입
void GameManager::set_PlayerSelect(int _num)
{
	Select_Character = _num;
}

//캐릭터(AI) 선택 리턴
DoEngine::Object* GameManager::get_AISelect()
{
	if (Select_AI == SELECT_BICE)
	{
		return new Bice;
	}
	else if (Select_AI == SELECT_UCLID)
	{
		//return new Uclid;
		return new Bice;
	}
	else if (Select_AI == SELECT_XION)
	{
		//return new Xion;
		return new Bice;
	}
}

//캐릭터 죽음 삽입(캐릭터 둘중 하나의 HP가 0)
void GameManager::set_IsDie(bool _isDie)
{
	CharDie = _isDie;
}

//캐릭터 죽음 리턴(캐릭터 둘중 하나의 HP가 0)
bool GameManager::get_IsDie()
{
	return CharDie;
}

//Player 죽음 삽입
void GameManager::set_IsPlayerDie(bool _isDie)
{
	PlayerDie = _isDie;
}

//Player 죽음 리턴
bool GameManager::get_IsPlayerDie()
{
	return PlayerDie;
}

//Enemy 죽음 삽입
void GameManager::set_IsEnemyDie(bool _isDie)
{
	EnemyDie = _isDie;
}

//Enemy 죽음 리턴
bool GameManager::get_IsEnemyDie()
{
	return EnemyDie;
}

//딜레이 리턴
float GameManager::get_MotionDelay()
{
	return Motion_Delay;
}

//캐릭터(AI) 선택 삽입
void GameManager::set_AISelect(int _num)
{
	Select_AI = _num;
}

//캐릭터(AI) 선택 리턴
int GameManager::get_MapSelect()
{
	return Select_Map;
}

//캐릭터(AI) 선택 삽입
void GameManager::set_MapSelect(int _num)
{
	Select_Map = _num;
}

//싸움 시작
void GameManager::ChangeFightStart()
{
	FightStart = true;
}

//싸움 시작(게임) 생성완료
bool GameManager::get_IsFightStart()
{
	return FightStart;
}

//싸움 종료
bool GameManager::get_IsFightEnd()
{
	return FightEnd;
}

//플레어가 이겼는지, 적이 이겼는지 리턴
int GameManager::get_RedBlue()
{
	return RedBlue;
}

//게임 종료
bool GameManager::get_IsGameEnd()
{
	return GameEnd;
}

//AI//
 //적 위치 삽입(posX)
void GameManager::set_AIposX(float _posx)
{
	AI_posX = _posx;
}

//적 위치 리턴(posY)
float GameManager::get_AIposX()
{
	return AI_posX;
}

//적 위치 삽입(posY)
void GameManager::set_AIposY(float _posy)
{
	AI_posY = _posy;
}

//적 위치 삽입(posY)
float GameManager::get_AIposY()
{
	return AI_posY;
}

//적 타격 수 삽입
void GameManager::set_HitCount(int _count)
{
	HitCount = _count;
}

//적 타격 수 삽입
int GameManager::get_HitCount()
{
	return HitCount;
}