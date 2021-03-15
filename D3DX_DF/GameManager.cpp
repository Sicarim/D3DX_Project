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


//������
GameManager::GameManager()
{

}

//���� �ʱ�ȭ
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

	//Ű���
	Key_Init();
	//Scene���
	Regist_Scene();

	//AI info//
	AI_posX = 0.0f;
	AI_posY = 0.0f;
	HitCount = 0;
}

//�Ҹ���
GameManager::~GameManager()
{

}

//Ű ���
/*
	���ӿ��� ����� Ű�� ����Ѵ�.
*/
void GameManager::Key_Init()
{
	//Ű ����
	DoEngine::InputManager::get_Instance()->Clear();
	//����Ű (��)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LEFT);
	//����Ű (��)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RIGHT);
	//����Ű (��)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_UP);
	//����Ű (�Ʒ�)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_DOWN);
	//���� ����
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
	//����Ű
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RETURN);
	//���콺 ��Ŭ��
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LBUTTON);

	//���۹�ư ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//���ݹ�ư ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
}

//Scene ���
/*
	������ ������ Scene���� ����Ѵ�. �̶�, defines.h�� ��ϼ����� ��ġ�ϵ����Ѵ�.
*/
void GameManager::Regist_Scene()
{
	DoEngine::SceneManager::get_Instance()->RegistScene(new StartScene); //StartScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new SelectScene); //SelectScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new SelectMapScene); //SelectMapScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene); //GameScene���
	//ResultScene���
	//DoEngine::SceneManager::get_Instance()->RegistScene(new ResultScene);
}

//Update �Լ�
/*
	������ �����ϴµ��� ����� Update�Լ�
*/
void GameManager::Update(float _fETime)
{
	if (PlayerDie || EnemyDie)
	{
		curTime += _fETime;
		Motion_Delay = END_DELAY;
	}

	//óġ�� �ִϸ��̼� ����ð�
	if (curTime > DIE_TIME)
	{
		Motion_Delay = START_DELAY;
		CharDie = false;
		FightEnd = true;
		if (PlayerDie) //�÷��̾ �׾��ٸ�
		{
			RedBlue = WINLOSE_BLUE;
		}
		else if (EnemyDie) //Enemy�� �׾��ٸ�
		{
			RedBlue = WINLOSE_RED;
		}
	}

	if (curTime > GAME_ENDDELAY)
	{
		GameEnd = true;
	}
}

//Release�Լ�
/*
	���� ����۽� �ʿ��� �������� �����ش�.
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

//ĳ���� ���� ����
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

//ĳ���� ���� ����
void GameManager::set_PlayerSelect(int _num)
{
	Select_Character = _num;
}

//ĳ����(AI) ���� ����
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

//ĳ���� ���� ����(ĳ���� ���� �ϳ��� HP�� 0)
void GameManager::set_IsDie(bool _isDie)
{
	CharDie = _isDie;
}

//ĳ���� ���� ����(ĳ���� ���� �ϳ��� HP�� 0)
bool GameManager::get_IsDie()
{
	return CharDie;
}

//Player ���� ����
void GameManager::set_IsPlayerDie(bool _isDie)
{
	PlayerDie = _isDie;
}

//Player ���� ����
bool GameManager::get_IsPlayerDie()
{
	return PlayerDie;
}

//Enemy ���� ����
void GameManager::set_IsEnemyDie(bool _isDie)
{
	EnemyDie = _isDie;
}

//Enemy ���� ����
bool GameManager::get_IsEnemyDie()
{
	return EnemyDie;
}

//������ ����
float GameManager::get_MotionDelay()
{
	return Motion_Delay;
}

//ĳ����(AI) ���� ����
void GameManager::set_AISelect(int _num)
{
	Select_AI = _num;
}

//ĳ����(AI) ���� ����
int GameManager::get_MapSelect()
{
	return Select_Map;
}

//ĳ����(AI) ���� ����
void GameManager::set_MapSelect(int _num)
{
	Select_Map = _num;
}

//�ο� ����
void GameManager::ChangeFightStart()
{
	FightStart = true;
}

//�ο� ����(����) �����Ϸ�
bool GameManager::get_IsFightStart()
{
	return FightStart;
}

//�ο� ����
bool GameManager::get_IsFightEnd()
{
	return FightEnd;
}

//�÷�� �̰����, ���� �̰���� ����
int GameManager::get_RedBlue()
{
	return RedBlue;
}

//���� ����
bool GameManager::get_IsGameEnd()
{
	return GameEnd;
}

//AI//
 //�� ��ġ ����(posX)
void GameManager::set_AIposX(float _posx)
{
	AI_posX = _posx;
}

//�� ��ġ ����(posY)
float GameManager::get_AIposX()
{
	return AI_posX;
}

//�� ��ġ ����(posY)
void GameManager::set_AIposY(float _posy)
{
	AI_posY = _posy;
}

//�� ��ġ ����(posY)
float GameManager::get_AIposY()
{
	return AI_posY;
}

//�� Ÿ�� �� ����
void GameManager::set_HitCount(int _count)
{
	HitCount = _count;
}

//�� Ÿ�� �� ����
int GameManager::get_HitCount()
{
	return HitCount;
}