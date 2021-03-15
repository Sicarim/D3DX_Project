#include "GameScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "Bice.h"
#include "Uclid.h"
#include "Xion.h"

//������
GameScene::GameScene()
{

}

//�Ҹ���
GameScene::~GameScene()
{

}

//Scene �ʱ�ȭ(override)
void GameScene::Init()
{
	TCHAR				buf[255];
	LPDIRECT3DTEXTURE9	tmp_Back;

	//��ü ȭ��
	for (int i = 0; i < 6; i++)
	{
		wsprintf(buf, "Resource\\BackGround\\Back\\%d.png", i);
		tmp_Back = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		BackGround.push_back(tmp_Back);
	}

	//Player
	m_Player = new Player;
	m_Player->Init("Player", 300.0f, 600.0f, true);

	//Enemy
	m_Enemy = new EnemyAI;
	m_Enemy->Init("Enemy", 1700.0f, 600.0f, false);

	UIManager::get_Instance()->UI_Init(); //UI�ʱ�ȭ



	// ĳ���͸� �޸� �Ҵ����� �ؽ��ĸ� �ҷ�����, ũ��, ��ġ���� �ش�.
	//m_AI		= GameManager::get_Instance()->get_AISelect();

	//Player, AI �ʱ�ȭ
	//m_Player->Init("Player", 300.0f, 600.0f, true);
	//m_Player.SelectCharecter(GameManager::get_Instance()->get_PlayerSelect());
	//m_testAI.SelectAI(GameManager::get_Instance()->get_AISelect());
	//m_AI->Init("Enemy", 1700.0f, 600.0f, false);

	//AI Test;
	//m_Player.Init("Player", 300.0f, 600.0f, true);
	//m_testAI.Init("Enemy", 1700.0f, 600.0f, false);

	//Object ���
	//obj.Add_Object(m_Player->ReturnObject());
	//obj.Add_Object(m_Enemy->ReturnObject());
}

//Scene������ �Է�(override)
bool GameScene::Input(float _fETime)
{
	//Scene ��ȣ�ۿ�
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//������ ������ ĳ���� ����ȭ������ ���ư���.
	if (GameManager::get_Instance()->get_IsGameEnd())
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_SELECT);
	}

	//Player
	m_Command = m_Input.CommandInput();

	if (m_Command)
	{
		m_Command->excute(*m_Player);
	}

	//Enemy
	m_Enemy->Input(AI_INPUT);
	return false;
}

//Scene Update(override)
void GameScene::Update(float _fETime)
{
	//Enemy Update
	m_Enemy->Update(_fETime);
	//Player Update
	m_Player->Update(_fETime);



	//m_AI->Update(_fETime);
	//m_testAI.Update(_fETime);

	//Game Update
	GameManager::get_Instance()->Update(_fETime);
	//UI Update
	UIManager::get_Instance()->UI_Update(_fETime);
}

//Scene �׸���(override)
void GameScene::Render()
{
	//Map �׸���
	DoEngine::GraphicsManager::get_Instance()->TextureRender(BackGround[GameManager::get_Instance()->get_MapSelect()], 0, 0);

	//UI�׸���
	UIManager::get_Instance()->UI_Render();

	//m_AI->Render();

	//m_testAI.Render();
	//Enemy Render
	m_Enemy->Render();
	//Player Render
	m_Player->Render();
}

//Scene �����
void GameScene::Release()
{
	UIManager::get_Instance()->UI_Release();
	GameManager::get_Instance()->Game_Release();
}