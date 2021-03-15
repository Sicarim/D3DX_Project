#include "TextureMaker.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "SelectMapScene.h"
#include "GameScene.h"


//������
TextureMaker::TextureMaker()
{
	
}

//���� �ʱ�ȭ
void TextureMaker::Game_Init()

{
}

//�Ҹ���
TextureMaker::~TextureMaker()
{

}

void TextureMaker::Regist_Texture()
{
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

//Release�Լ�
/*
	���� ����۽� �ʿ��� �������� �����ش�.
*/
void TextureMaker::Game_Release()
{
	
}

//Mini ȭ�� ����
vector<LPDIRECT3DTEXTURE9> TextureMaker::get_MiniBack()
{
	return MiniBackGround;
}

//ĳ����(AI) ���� ����
vector<LPDIRECT3DTEXTURE9> TextureMaker::get_AllBackGround()
{
	return BackGround;
}

//ĳ����(AI) ���� ����
LPDIRECT3DTEXTURE9 TextureMaker::get_BackGround(int _num)
{
	return BackGround[_num];
}