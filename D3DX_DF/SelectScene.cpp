#include "SelectScene.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "AnimationMaker.h"
#include "BiceStanding.h"
#include "UclidStanding.h"
#include "XionStanding.h"

//생성자
SelectScene::SelectScene()
{
}

//소멸자
SelectScene::~SelectScene()
{

}

//Scene 초기화(override)
void SelectScene::Init()
{
	AITiem = 0.0f;
	AiCharSelect = 0;
	SelectCount = 0;
	GameStart = false;

	curTiem = 0.0f;
	ChangePos = 0.0f;
	ButtonCount = 0;
	ChangePos = 650;
	AI_Select = 0;

	ScenePos = CUT_INITPOS;
	AIScenePos = 1895;

	PlayerSelectDone = false;
	AISelectDone = false;
	
	BackGround = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\BackGround\\Select_Back.png");

	DoEngine::State* Stand;
	Stand = new BiceStanding();
	StandingMotion.push_back(Stand);
	Stand = new UclidStanding();
	StandingMotion.push_back(Stand);
	Stand = new XionStanding();
	StandingMotion.push_back(Stand);

	for (int i = 0; i < StandingMotion.size(); i++)
	{
		StandingMotion[i]->Init();
		StandingMotion[i]->Play_Animation();
	}
}

//Scene내에서 입력(override)
bool SelectScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	if (!PlayerSelectDone)
	{
		if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RIGHT))
		{
			if (ButtonCount < 2)
			{
				ScenePos = CUT_INITPOS;
				ButtonCount++;
				ChangePos += BUTTON_SPACE;
			}
		}

		else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_LEFT))
		{
			if (ButtonCount > 0)
			{
				ScenePos = CUT_INITPOS;
				ButtonCount--;
				ChangePos -= BUTTON_SPACE;
			}
		}
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		GameManager::get_Instance()->set_PlayerSelect(ButtonCount);
		PlayerSelectDone = true;
	}

	//AI, 캐릭터 선택이 끝나면 GameScene으로 넘어간다.
	if (GameStart)
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_SELECTMAP);
	}

	return false;
}

//Scene Update(override)
void SelectScene::Update(float _fETime)
{
	curTiem += _fETime;
	AITiem += _fETime;

	if (ScenePos <= -1)
	{
		ScenePos += CUT_SPEED;
	}

	//선택화면 몬스터 스탠딩 모션
	if (curTiem > 0.1f)
	{
		StandingMotion[SELECT_BICE]->Play_Animation();
		StandingMotion[SELECT_UCLID]->Play_Animation();
		StandingMotion[SELECT_XION]->Play_Animation();
		curTiem = 0.0f;
	}

	//컷신 변경
	if (ButtonCount == SELECT_BICE)
	{
		CutScene = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\CutScene\\BiceCutScene.png");
	}
	else if (ButtonCount == SELECT_UCLID)
	{
		CutScene = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\CutScene\\UclidCutScene.png");
	}
	else if (ButtonCount == SELECT_XION)
	{
		CutScene = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\CutScene\\XionCutScene.png");
	}

	//AI의 캐릭터 선택
	if (PlayerSelectDone && !AISelectDone)
	{
		if (AITiem > 0.03f)
		{
			AiCharSelect = rand() % 3;
			SelectCount++;
			if (AiCharSelect == SELECT_BICE)
			{
				ChangePos = 650;
				AICutScene = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\CutScene\\BiceCutScene.png");
			}
			else if (AiCharSelect == SELECT_UCLID)
			{
				ChangePos = 895;
				AICutScene = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\CutScene\\UclidCutScene.png");
			}
			else if (AiCharSelect == SELECT_XION)
			{
				ChangePos = 1140;
				AICutScene = DoEngine::TextureManager::get_Instance()->Load_Texture("Resource\\CutScene\\XionCutScene.png");
			}
			AITiem = 0.0f;
		}
	}

	//AI가 정해졌다면
	if (SelectCount == 15)
	{
		AISelectDone = true;
		GameManager::get_Instance()->set_AISelect(AiCharSelect);

		if (AIScenePos > 945)
		{
			AIScenePos -= CUT_SPEED;
		}

		if (AITiem > 0.9f)
		{
			GameStart = true;
		}
	}
}

//Scene 그리기(override)
void SelectScene::Render()
{
	DoEngine::GraphicsManager::get_Instance()->TextureRender(BackGround, 0, 0, true, 1, 1, 60);
	DoEngine::GraphicsManager::get_Instance()->Draw_Text("SELECT", ChangePos, 490, D3DCOLOR_XRGB(255, 255, 255));
	DoEngine::GraphicsManager::get_Instance()->TextureRender(CutScene, ScenePos, 0, true, 1, 1, 80);		//캐릭터 선택 컷신

	//AI가 선택이 완료 되엇다면...
	if (AISelectDone)
	{
		DoEngine::GraphicsManager::get_Instance()->TextureRender(AICutScene, AIScenePos, 0, true, 1, 1, 80);		//AI 선택 컷신
	}
	
	StandingMotion[SELECT_BICE]->Render(720, 300, true);
	StandingMotion[SELECT_UCLID]->Render(970, 300, true);
	StandingMotion[SELECT_XION]->Render(1170, 300, true);
}

//Scene 지우기
void SelectScene::Release()
{
	AITiem = 0.0f;
	AiCharSelect = 0;
	SelectCount = 0;
	GameStart = false;

	curTiem = 0.0f;
	ChangePos = 0.0f;
	ButtonCount = 0;
	ChangePos = 650;
	AI_Select = 0;
	ScenePos = CUT_INITPOS;
	PlayerSelectDone = false;
	AISelectDone = false;
}