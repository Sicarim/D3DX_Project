#include "EngineMain.h"
#include "GraphicsManager.h"
#include "SceneManager.h"

namespace DoEngine
{
	//default
	EngineMain::EngineMain()
	{

	}

	//������
	EngineMain::EngineMain(string _title, int _cx, int _cy)
	{
		m_strTitle = _title;
		m_winSizeX = _cx;
		m_winSizeY = _cy;
	}

	LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		// ���� ���Ͻ���
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	//���� ����
	int EngineMain::StartEngine(HINSTANCE hInstance)
	{
		// ������ Ŭ������ ������ ����
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "Doyun_Engine", NULL
		};

		RegisterClassEx(&wc);

		// �����츦 ������
		HWND hWnd = CreateWindow("Doyun_Engine", m_strTitle.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, m_winSizeX, m_winSizeY, GetDesktopWindow(), NULL, wc.hInstance, NULL);

		//�����츦 ��� ��, Update����
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		//GraphicsManager �ʱ�ȭ
		GraphicsManager::get_Instance()->Init(hWnd, m_winSizeX, m_winSizeY);

		//SceneManager �ʱ�ȭ
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
				//������ ����
				GraphicsManager::get_Instance()->RenderStart();
				//SceneManager Update
				if (SceneManager::get_Instance()->Update())
				{
					SendMessage(hWnd, WM_DESTROY, 0, 0);
				}
				//������ ����
				GraphicsManager::get_Instance()->RenderEnd();
			}
		}
		SceneManager::get_Instance()->Release();

		return 0;
	}

	//�Ҹ���
	EngineMain::~EngineMain()
	{

	}
}