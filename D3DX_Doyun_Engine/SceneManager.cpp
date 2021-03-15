#include "SceneManager.h"
#include "TimeManager.h"

namespace DoEngine
{
	SceneManager* SceneManager::m_hInstance = NULL;

	SceneManager::SceneManager()
	{

	}

	//SceneManager초기화
	void SceneManager::Init(HWND hWnd, int win_cx, int win_cy)
	{
		m_hWnd = hWnd;
		m_iWinCX = win_cx;
		m_iWinCY = win_cy;

		::RECT rcClient, rcWindow;
		GetClientRect(hWnd, &rcClient); //윈도우 화면 좌쵸값으로 위치정보를 반환
		GetWindowRect(hWnd, &rcWindow); //윈도우 클라이언트 영역사에서의 좌표값 반환

		int CXFrame = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		int CYFrame = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		MoveWindow(hWnd, 0, 0, win_cx + CXFrame, win_cy + CYFrame, true); //윈도우의 위치와 크기를 동시에 변경

		m_curScene = m_vecScene[0];
		m_curScene->Init();
	}

	//씬 등록하기
	void SceneManager::RegistScene(Scene* Reg)
	{
		m_vecScene.push_back(Reg);
	}

	//Update 함수
	bool SceneManager::Update()
	{
		if (!DoEngine::TimeManager::get_Instance()->Update())
		{
			return false;
		}

		//InputManager 갱신, 키의 상태값을 계속 참조한다.
		DoEngine::InputManager::get_Instance()->Update();
		//UIManager 갱신, UI의 상태값을 계속 참조 한다.
		//DoEngine::UIManager::get_Instance()->Update();

		//현재 시간을 입력받아 현재 씬의 키입력을 관리한다.
		if (m_curScene->Input(DoEngine::TimeManager::get_Instance()->get_ElipseTime()))
		{
			return true;
		}

		//현재 Scene이므로 TitleScene로 이동, TileScene의 상태값을 계속 참조한다
		m_curScene->Update(DoEngine::TimeManager::get_Instance()->get_ElipseTime());
		//현재 씬 그리기
		m_curScene->Render();

		return false;
	}

	//씬 불러오기
	void SceneManager::LoadScene(int _sceneindex)
	{
		//UI를 삭제한다.
		//UIManager::get_Instance()->ReleaseUI();
		m_lastScene = m_curScene; //현재씬을 이전 씬에 담는다.
		m_curScene = m_vecScene[_sceneindex]; //벡터에 담긴 씬을 현재씬에 담는다

		m_lastScene->Release(); //이전씬을 삭제한다
		m_curScene->Init(); //현재 씬을 초기화한다.
	}

	//삭제 함수
	void SceneManager::Release()
	{
		for (auto iter = m_vecScene.begin(); iter != m_vecScene.end();)
		{
			Scene* pDelete = *iter;
			pDelete->Release(); //데이터 삭제
			iter++;
			SAFE_DELETE(pDelete);
		}

		SAFE_DELETE(m_hInstance);
	}

	SceneManager::~SceneManager()
	{

	}
}