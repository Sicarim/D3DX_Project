#pragma once
#include "DoEngine.h"
#include "EngineMain.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "GameManager.h"
//#include "S_Game.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT)
{
	//���� ����ũ�� 1890 * 980
	srand(time(NULL));
	//���� ȭ�� ũ��� ������ ����
	DoEngine::EngineMain engine("DF_Fighter", 1890, 1000);
	//���� �ʱ�ȭ
	GameManager::get_Instance()->Game_Init();

	//���� ����
	return engine.StartEngine(hInstance);
}