#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Singleton.h"

class TextureMaker : public Singleton<TextureMaker>
{
private:
	int							Map_Num;
	TCHAR						buf[255];
	vector<LPDIRECT3DTEXTURE9>	MiniBackGround; //미니 맵
	vector<LPDIRECT3DTEXTURE9>	BackGround;		//전체 맵
public:
	TextureMaker();						//생성자
	~TextureMaker();						//소멸자
public:
	void Regist_Texture();				//Scene 등록
	void Game_Init();					//게임 초기화
	
	void Game_Release();				//Release함수

	vector<LPDIRECT3DTEXTURE9> get_MiniBack();				//Mini 화면 선택
	vector<LPDIRECT3DTEXTURE9> get_AllBackGround();				//캐릭터(AI) 선택 리턴

	LPDIRECT3DTEXTURE9 get_BackGround(int _num);				//캐릭터(AI) 선택 리턴
};