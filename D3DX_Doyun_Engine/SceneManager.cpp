#include "SceneManager.h"
#include "TimeManager.h"

namespace DoEngine
{
	SceneManager* SceneManager::m_hInstance = NULL;

	SceneManager::SceneManager()
	{

	}

	//SceneManager�ʱ�ȭ
	void SceneManager::Init(HWND hWnd, int win_cx, int win_cy)
	{
		m_hWnd = hWnd;
		m_iWinCX = win_cx;
		m_iWinCY = win_cy;

		::RECT rcClient, rcWindow;
		GetClientRect(hWnd, &rcClient); //������ ȭ�� ���ݰ����� ��ġ������ ��ȯ
		GetWindowRect(hWnd, &rcWindow); //������ Ŭ���̾�Ʈ �����翡���� ��ǥ�� ��ȯ

		int CXFrame = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		int CYFrame = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		MoveWindow(hWnd, 0, 0, win_cx + CXFrame, win_cy + CYFrame, true); //�������� ��ġ�� ũ�⸦ ���ÿ� ����

		m_curScene = m_vecScene[0];
		m_curScene->Init();
	}

	//�� ����ϱ�
	void SceneManager::RegistScene(Scene* Reg)
	{
		m_vecScene.push_back(Reg);
	}

	//Update �Լ�
	bool SceneManager::Update()
	{
		if (!DoEngine::TimeManager::get_Instance()->Update())
		{
			return false;
		}

		//InputManager ����, Ű�� ���°��� ��� �����Ѵ�.
		DoEngine::InputManager::get_Instance()->Update();
		//UIManager ����, UI�� ���°��� ��� ���� �Ѵ�.
		//DoEngine::UIManager::get_Instance()->Update();

		//���� �ð��� �Է¹޾� ���� ���� Ű�Է��� �����Ѵ�.
		if (m_curScene->Input(DoEngine::TimeManager::get_Instance()->get_ElipseTime()))
		{
			return true;
		}

		//���� Scene�̹Ƿ� TitleScene�� �̵�, TileScene�� ���°��� ��� �����Ѵ�
		m_curScene->Update(DoEngine::TimeManager::get_Instance()->get_ElipseTime());
		//���� �� �׸���
		m_curScene->Render();

		return false;
	}

	//�� �ҷ�����
	void SceneManager::LoadScene(int _sceneindex)
	{
		//UI�� �����Ѵ�.
		//UIManager::get_Instance()->ReleaseUI();
		m_lastScene = m_curScene; //������� ���� ���� ��´�.
		m_curScene = m_vecScene[_sceneindex]; //���Ϳ� ��� ���� ������� ��´�

		m_lastScene->Release(); //�������� �����Ѵ�
		m_curScene->Init(); //���� ���� �ʱ�ȭ�Ѵ�.
	}

	//���� �Լ�
	void SceneManager::Release()
	{
		for (auto iter = m_vecScene.begin(); iter != m_vecScene.end();)
		{
			Scene* pDelete = *iter;
			pDelete->Release(); //������ ����
			iter++;
			SAFE_DELETE(pDelete);
		}

		SAFE_DELETE(m_hInstance);
	}

	SceneManager::~SceneManager()
	{

	}
}