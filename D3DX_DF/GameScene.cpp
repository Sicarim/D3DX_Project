#include "GameScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "Bice.h"
#include "Uclid.h"
#include "Xion.h"

//생성자
GameScene::GameScene()
{

}

//소멸자
GameScene::~GameScene()
{

}

//Scene 초기화(override)
void GameScene::Init()
{
	TCHAR				buf[255];
	LPDIRECT3DTEXTURE9	tmp_Back;

	//전체 화면
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

	UIManager::get_Instance()->UI_Init(); //UI초기화



	// 캐릭터를 메모리 할당이후 텍스쳐를 불러오고, 크기, 위치값을 준다.
	//m_AI		= GameManager::get_Instance()->get_AISelect();

	//Player, AI 초기화
	//m_Player->Init("Player", 300.0f, 600.0f, true);
	//m_Player.SelectCharecter(GameManager::get_Instance()->get_PlayerSelect());
	//m_testAI.SelectAI(GameManager::get_Instance()->get_AISelect());
	//m_AI->Init("Enemy", 1700.0f, 600.0f, false);

	//AI Test;
	//m_Player.Init("Player", 300.0f, 600.0f, true);
	//m_testAI.Init("Enemy", 1700.0f, 600.0f, false);

	//Object 등록
	//obj.Add_Object(m_Player->ReturnObject());
	//obj.Add_Object(m_Enemy->ReturnObject());
}

//Scene내에서 입력(override)
bool GameScene::Input(float _fETime)
{
	//Scene 상호작용
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//전투가 끝나면 캐릭터 선택화면으로 돌아간다.
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

//Scene 그리기(override)
void GameScene::Render()
{
	//Map 그리기
	DoEngine::GraphicsManager::get_Instance()->TextureRender(BackGround[GameManager::get_Instance()->get_MapSelect()], 0, 0);

	//UI그리기
	UIManager::get_Instance()->UI_Render();

	//m_AI->Render();

	//m_testAI.Render();
	//Enemy Render
	m_Enemy->Render();
	//Player Render
	m_Player->Render();
}

//Scene 지우기
void GameScene::Release()
{
	UIManager::get_Instance()->UI_Release();
	GameManager::get_Instance()->Game_Release();
}