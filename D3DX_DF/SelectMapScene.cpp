#include "SelectMapScene.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "AnimationMaker.h"
#include "BiceStanding.h"
#include "UclidStanding.h"
#include "XionStanding.h"

//생성자
SelectMapScene::SelectMapScene()
{
}

//소멸자
SelectMapScene::~SelectMapScene()
{

}

//Scene 초기화(override)
void SelectMapScene::Init()
{
	Map_Num = MAP_ZERO;
	LPDIRECT3DTEXTURE9 tmp_Back;

	//미니 화면 
	for (int i = 0; i < 6; i++)
	{
		wsprintf(buf, "Resource\\BackGround\\Select_Back\\%d.png", i);
		tmp_Back = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		MiniBackGround.push_back(tmp_Back);
	}

	//전체 화면
	for (int i = 0; i < 6; i++)
	{
		wsprintf(buf, "Resource\\BackGround\\Back\\%d.png", i);
		tmp_Back = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		BackGround.push_back(tmp_Back);
	}
}

//Scene내에서 입력(override)
bool SelectMapScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RIGHT))
	{
		if (Map_Num == MAP_FIVE)
		{
			Map_Num = MAP_ZERO;
		}
		else
		{
			Map_Num++;
		}
	}
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_LEFT))
	{
		if (Map_Num == MAP_ZERO)
		{
			Map_Num = MAP_FIVE;
		}
		else
		{
			Map_Num--;
		}
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		GameManager::get_Instance()->set_MapSelect(Map_Num);
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}

	return false;
}

//Scene Update(override)
void SelectMapScene::Update(float _fETime)
{
	
}

//Scene 그리기(override)
void SelectMapScene::Render()
{
	//뒷 배경 그리기
	DoEngine::GraphicsManager::get_Instance()->TextureRender(BackGround[Map_Num], 0, 0, true, 1, 1, 70);
	//전체 배경 그리기
	DoEngine::GraphicsManager::get_Instance()->TextureRender(MiniBackGround[Map_Num], 630, 200, true, 1, 1, 255);
	DoEngine::GraphicsManager::get_Instance()->Draw_Text("◁ SELECT ▷", 220, 350, D3DCOLOR_XRGB(255, 255, 255));
}

//Scene 지우기
void SelectMapScene::Release()
{
	
}