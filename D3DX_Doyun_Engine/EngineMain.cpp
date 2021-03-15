#include "EngineMain.h"
#include "GraphicsManager.h"
#include "SceneManager.h"

namespace DoEngine
{
	//default
	EngineMain::EngineMain()
	{

	}

	//생성자
	EngineMain::EngineMain(string _title, int _cx, int _cy)
	{
		m_strTitle = _title;
		m_winSizeX = _cx;
		m_winSizeY = _cy;
	}

	LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		// 메인 프록시저
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	//엔진 시작
	int EngineMain::StartEngine(HINSTANCE hInstance)
	{
		// 윈도우 클래스를 생성후 적용
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "Doyun_Engine", NULL
		};

		RegisterClassEx(&wc);

		// 윈도우를 생성후
		HWND hWnd = CreateWindow("Doyun_Engine", m_strTitle.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, m_winSizeX, m_winSizeY, GetDesktopWindow(), NULL, wc.hInstance, NULL);

		//윈도우를 출력 후, Update실행
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		//GraphicsManager 초기화
		GraphicsManager::get_Instance()->Init(hWnd, m_winSizeX, m_winSizeY);

		//SceneManager 초기화
		SceneManager::get_Instance()->Init(hWnd, m_winSizeX, m_winSizeY);

		MSG msg;
		ZeroMemory(&msg, sizeof(msg));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				//렌더링 시작
				GraphicsManager::get_Instance()->RenderStart();
				//SceneManager Update
				if (SceneManager::get_Instance()->Update())
				{
					SendMessage(hWnd, WM_DESTROY, 0, 0);
				}
				//렌더링 종료
				GraphicsManager::get_Instance()->RenderEnd();
			}
		}
		SceneManager::get_Instance()->Release();

		return 0;
	}

	//소멸자
	EngineMain::~EngineMain()
	{

	}
}