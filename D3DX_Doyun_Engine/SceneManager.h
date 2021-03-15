#pragma once
#include "GlobalDefines.h"
#include "Scene.h"
#include "InputManager.h"

namespace DoEngine
{
	/**
	* @brief ���ӿ� ���Ǵ� Scene���� �����ϴ� Ŭ����
	* @details ���ӿ� ���Ǵ� Scene���� �����ϴ� Ŭ������ ������ ������ ����ϴ� Ŭ�����Դϴ�.
	*/

	class SceneManager
	{
	private:
		bool			m_bInit; //�ʱ�ȭ ����
		HWND			m_hWnd; //hWnd ����
		vector<Scene*>	m_vecScene; //�� ����
		Scene* m_curScene; //���� ��
		Scene* m_lastScene; //������ ��(���� ��)
		InputManager* m_input; //�Է� ����
		int				m_iWinCX; //������ x(����)
		int				m_iWinCY; //������ y(����)

		static SceneManager* m_hInstance;
		SceneManager();
	public:
		static SceneManager* get_Instance()
		{
			if (m_hInstance == NULL)
			{
				m_hInstance = new SceneManager();
			}
			return m_hInstance;
		}

		void Init(HWND hWnd, int win_cx, int win_cy); //SceneManager�ʱ�ȭ
		bool Update(); //Update �Լ�
		void RegistScene(Scene* _reg); //�� ����ϱ�
		void LoadScene(int _sceneindex); //�� �ҷ�����
		void Release(); //���� �Լ�

		~SceneManager();
	};
}