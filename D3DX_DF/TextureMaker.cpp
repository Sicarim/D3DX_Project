#include "TextureMaker.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "SelectMapScene.h"
#include "GameScene.h"


//생성기
TextureMaker::TextureMaker()
{
	
}

//게임 초기화
void TextureMaker::Game_Init()

{
}

//소멸자
TextureMaker::~TextureMaker()
{

}

void TextureMaker::Regist_Texture()
{
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

//Release함수
/*
	게임 재시작시 필요한 번수들을 지워준다.
*/
void TextureMaker::Game_Release()
{
	
}

//Mini 화면 선택
vector<LPDIRECT3DTEXTURE9> TextureMaker::get_MiniBack()
{
	return MiniBackGround;
}

//캐릭터(AI) 선택 리턴
vector<LPDIRECT3DTEXTURE9> TextureMaker::get_AllBackGround()
{
	return BackGround;
}

//캐릭터(AI) 선택 리턴
LPDIRECT3DTEXTURE9 TextureMaker::get_BackGround(int _num)
{
	return BackGround[_num];
}