#pragma once
//Delay
#define CHAR_DELAY 80.0f

//게임에 사용될 Key
#define BUTTON_S 0x53 //시작버튼
#define BUTTON_X 0x58 //공격버튼
#define CUT_INITPOS -1000
#define CUT_SPEED 50
#define BUTTON_SPACE 245; //Select 글자간 간격

//Player Health
#define PLAYER_HELTH_POSX 30
#define PLAYER_HELTH_POSY 30

#define ENEMY_HELTH_POSX 1860
#define ENEMY_HELTH_POSY 30

#define HELTH_SIZEX 1.3f
#define HELTH_SIZEY 2.0f

//각종 기타 변수
#define BIRTH_TIME		1.0f		//탄생 모션 재생 시간
#define DIE_TIME		1.3f
#define END_DELAY		150.0f		//캐릭터가 죽으면 딜레이를 느리게 바꾼다.
#define START_DELAY		70.0f		//기본 모션 딜레이
#define GAME_ENDDELAY	5.0f		//게임 종료 후 화면 전환 시간
#define STANDING_NUMBER 0
#define NO_KEY			100			//아무런 조건이 아닐시 NO_Key키를 반환
#define AI_INPUT		1000		//아무런 조건이 아닐시 NO_Key키를 반환
#define MAX_BUFFER		5			//버퍼에 들어갈수 있는 최대 갯수
#define MAX_HP			1.3f		//MaxHP

//WinAndLose
/*
	Player의 승패 유무
*/
enum WINLOSE
{
	WINLOSE_WAIT,
	WINLOSE_RED,
	WINLOSE_BLUE
};

//Scene
/*
	Scene의 재생순서 *등록순서와 일치시킬것!*
*/
enum SCENE_INDEX
{
	SCENE_INDEX_START,
	SCENE_INDEX_SELECT,	
	SCENE_INDEX_SELECTMAP,
	SCENE_INDEX_GAME
};

//맵 순서
enum MAP_INDEX
{
	MAP_ZERO,
	MAP_ONE,
	MAP_TWO,
	MAP_THREE,
	MAP_FOUR,
	MAP_FIVE,
};

//카운트 숫자
enum COUNT_INDEX
{
	COUNT_START,
	COUNT_ONE,
	COUNT_TWO,
	COUNT_THREE
};

//캐릭터 선택
enum SELECT_CHARECTER
{
	SELECT_BICE,
	SELECT_UCLID,
	SELECT_XION
};

//Character
/*
	캐릭터의 행동을 정의
*/

//캐릭터 공통 행동
enum CHAR_STATE
{
	STATE_STAND,
	STATE_BIRTH = 101,
	STATE_DIE,
	STATE_ATTACK
};

//바이스
enum BICE_STATE
{
	BICE_STAND,
	BICE_WORK,
	BICE_ATTACK_FIRST,
	BICE_ATTACK_SECOND,
	BICE_ATTACK_THIRD,
	BICE_ATTACK_SKILL,
	BICE_HIT,
	BICE_BIRTH,
	BICE_DIE,
	BICE_DASH,
	BICE_ATTACK
};

//유클리드
enum UCLID_STATE
{
	UCLID_STAND,
	UCLID_ATTACK_FIRST,
	UCLID_ATTACK_SECOND,
	UCLID_ATTACK_THIRD,
	UCLID_HIT,
	UCLID_BIRTH,
	UCLID_DIE,
	UCLID_ATTACK
};

//엑시온
enum XION_STATE
{
	XION_STAND,
	XION_WORK,
	XION_ATTACK_FIRST,
	XION_ATTACK_SECOND,
	//XION_ATTACK_THIRD,
	XION_HIT,
	XION_DIE,
	XION_ATTACK
};