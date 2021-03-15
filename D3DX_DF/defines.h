#pragma once
//Delay
#define CHAR_DELAY 80.0f

//���ӿ� ���� Key
#define BUTTON_S 0x53 //���۹�ư
#define BUTTON_X 0x58 //���ݹ�ư
#define CUT_INITPOS -1000
#define CUT_SPEED 50
#define BUTTON_SPACE 245; //Select ���ڰ� ����

//Player Health
#define PLAYER_HELTH_POSX 30
#define PLAYER_HELTH_POSY 30

#define ENEMY_HELTH_POSX 1860
#define ENEMY_HELTH_POSY 30

#define HELTH_SIZEX 1.3f
#define HELTH_SIZEY 2.0f

//���� ��Ÿ ����
#define BIRTH_TIME		1.0f		//ź�� ��� ��� �ð�
#define DIE_TIME		1.3f
#define END_DELAY		150.0f		//ĳ���Ͱ� ������ �����̸� ������ �ٲ۴�.
#define START_DELAY		70.0f		//�⺻ ��� ������
#define GAME_ENDDELAY	5.0f		//���� ���� �� ȭ�� ��ȯ �ð�
#define STANDING_NUMBER 0
#define NO_KEY			100			//�ƹ��� ������ �ƴҽ� NO_KeyŰ�� ��ȯ
#define AI_INPUT		1000		//�ƹ��� ������ �ƴҽ� NO_KeyŰ�� ��ȯ
#define MAX_BUFFER		5			//���ۿ� ���� �ִ� �ִ� ����
#define MAX_HP			1.3f		//MaxHP

//WinAndLose
/*
	Player�� ���� ����
*/
enum WINLOSE
{
	WINLOSE_WAIT,
	WINLOSE_RED,
	WINLOSE_BLUE
};

//Scene
/*
	Scene�� ������� *��ϼ����� ��ġ��ų��!*
*/
enum SCENE_INDEX
{
	SCENE_INDEX_START,
	SCENE_INDEX_SELECT,	
	SCENE_INDEX_SELECTMAP,
	SCENE_INDEX_GAME
};

//�� ����
enum MAP_INDEX
{
	MAP_ZERO,
	MAP_ONE,
	MAP_TWO,
	MAP_THREE,
	MAP_FOUR,
	MAP_FIVE,
};

//ī��Ʈ ����
enum COUNT_INDEX
{
	COUNT_START,
	COUNT_ONE,
	COUNT_TWO,
	COUNT_THREE
};

//ĳ���� ����
enum SELECT_CHARECTER
{
	SELECT_BICE,
	SELECT_UCLID,
	SELECT_XION
};

//Character
/*
	ĳ������ �ൿ�� ����
*/

//ĳ���� ���� �ൿ
enum CHAR_STATE
{
	STATE_STAND,
	STATE_BIRTH = 101,
	STATE_DIE,
	STATE_ATTACK
};

//���̽�
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

//��Ŭ����
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

//���ÿ�
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