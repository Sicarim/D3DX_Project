#pragma once
#include "GlobalDefines.h"
#include "Scene.h"
#include "InputManager.h"

namespace DoEngine
{
	/**
	* @brief 게임에 사용되는 Scene들을 관리하는 클레스
	* @details 게임에 사용되는 Scene들을 관리하는 클레스로 로직적 메인을 담당하는 클레스입니다.
	*/

	class SceneManager
	{
	private:
		bool			m_bInit; //초기화 여부
		HWND			m_hWnd; //hWnd 선언
		vector<Scene*>	m_vecScene; //씬 모음
		Scene* m_curScene; //현재 씬
		Scene* m_lastScene; //마지막 씬(이전 씬)
		InputManager* m_input; //입력 관리
		int				m_iWinCX; //윈도우 x(넓이)
		int				m_iWinCY; //윈도우 y(높이)

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

		void Init(HWND hWnd, int win_cx, int win_cy); //SceneManager초기화
		bool Update(); //Update 함수
		void RegistScene(Scene* _reg); //씬 등록하기
		void LoadScene(int _sceneindex); //씬 불러오기
		void Release(); //삭제 함수

		~SceneManager();
	};
}