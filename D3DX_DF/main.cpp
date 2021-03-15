#pragma once
#include "DoEngine.h"
#include "EngineMain.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "GameManager.h"
//#include "S_Game.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT)
{
	//던파 게임크기 1890 * 980
	srand(time(NULL));
	//게임 화면 크기와 제목을 지정
	DoEngine::EngineMain engine("DF_Fighter", 1890, 1000);
	//게임 초기화
	GameManager::get_Instance()->Game_Init();

	//엔진 시작
	return engine.StartEngine(hInstance);
}