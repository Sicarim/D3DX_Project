#include "StartScene.h"
#include "TextureMaker.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"

//������
StartScene::StartScene()
{
}

//�Ҹ���
StartScene::~StartScene()
{
}

//Scene �ʱ�ȭ(override)
void StartScene::Init()
{
	Alph = 0;
	SceneCount = -1;
	UpCount = false;
	DownCount = false;

	LPDIRECT3DTEXTURE9 tmp_bm;
	TCHAR buf[255];

	for (int i = 0; i < 3; i++)
	{
		wsprintf(buf, "Resource\\BackGround\\%d.png", i);
		tmp_bm = DoEngine::TextureManager::get_Instance()->Load_Texture(buf);
		BackGround.push_back(tmp_bm);
	}
	//Texture���
	TextureMaker::get_Instance()->Regist_Texture();
}

//Scene������ �Է�(override)
bool StartScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_SELECT);
	}
	return false;
}

//Scene Update(override)
void StartScene::Update(float _fETime)
{
	if (Alph == 0)
	{
		UpCount = true;
		DownCount = false;
		SceneCount++;
		if (SceneCount > 2)
		{
			SceneCount = 0;
		}
	}
	else if (Alph == 254)
	{
		UpCount = false;
		DownCount = true;
	}

	//Alpha�� ����
	if (UpCount)
		Alph += 1;
	if (DownCount)
		Alph -= 1;
}

//Scene �׸���(override)
void StartScene::Render()
{	
	DoEngine::GraphicsManager::get_Instance()->TextureRender(BackGround[SceneCount], 0, 0, true, 1, 1, Alph);
}

//Scene �����
void StartScene::Release()
{

}