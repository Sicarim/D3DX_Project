#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Singleton.h"

class TextureMaker : public Singleton<TextureMaker>
{
private:
	int							Map_Num;
	TCHAR						buf[255];
	vector<LPDIRECT3DTEXTURE9>	MiniBackGround; //�̴� ��
	vector<LPDIRECT3DTEXTURE9>	BackGround;		//��ü ��
public:
	TextureMaker();						//������
	~TextureMaker();						//�Ҹ���
public:
	void Regist_Texture();				//Scene ���
	void Game_Init();					//���� �ʱ�ȭ
	
	void Game_Release();				//Release�Լ�

	vector<LPDIRECT3DTEXTURE9> get_MiniBack();				//Mini ȭ�� ����
	vector<LPDIRECT3DTEXTURE9> get_AllBackGround();				//ĳ����(AI) ���� ����

	LPDIRECT3DTEXTURE9 get_BackGround(int _num);				//ĳ����(AI) ���� ����
};