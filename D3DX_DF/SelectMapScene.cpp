#include "SelectMapScene.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "AnimationMaker.h"
#include "BiceStanding.h"
#include "UclidStanding.h"
#include "XionStanding.h"

//������
SelectMapScene::SelectMapScene()
{
}

//�Ҹ���
SelectMapScene::~SelectMapScene()
{

}

//Scene �ʱ�ȭ(override)
void SelectMapScene::Init()
{
	Map_Num = MAP_ZERO;
	LPDIRECT3DTEXTURE9 tmp_Back;

	//�̴� ȭ�� 
	for (int i = 0; i < 6; i++)
	{
		wsprintf(buf, "Resource\\BackGround\\Select_Back\\%d.png", i);
		tmp_Back = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		MiniBackGround.push_back(tmp_Back);
	}

	//��ü ȭ��
	for (int i = 0; i < 6; i++)
	{
		wsprintf(buf, "Resource\\BackGround\\Back\\%d.png", i);
		tmp_Back = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		BackGround.push_back(tmp_Back);
	}
}

//Scene������ �Է�(override)
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

//Scene �׸���(override)
void SelectMapScene::Render()
{
	//�� ��� �׸���
	DoEngine::GraphicsManager::get_Instance()->TextureRender(BackGround[Map_Num], 0, 0, true, 1, 1, 70);
	//��ü ��� �׸���
	DoEngine::GraphicsManager::get_Instance()->TextureRender(MiniBackGround[Map_Num], 630, 200, true, 1, 1, 255);
	DoEngine::GraphicsManager::get_Instance()->Draw_Text("�� SELECT ��", 220, 350, D3DCOLOR_XRGB(255, 255, 255));
}

//Scene �����
void SelectMapScene::Release()
{
	
}