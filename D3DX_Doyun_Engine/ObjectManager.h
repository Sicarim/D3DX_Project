#pragma once
#include "GlobalDefines.h"
#include "Object.h"

using namespace std;

namespace DoEngine
{
	/**
	* @brief Object와 UI를 관리한다.
	* @details 현재 Scene의 Object, 카메라를 담당한다.
	*/

	class ObjectManager
	{
	private:
		// 오브젝트를 관리할 오브젝트 벡터와 Ui 벡터
		vector<Object*> Object_Vector, UI_Vector;
	public:
		ObjectManager();
		~ObjectManager();

	public:
		void Add_Object(Object* obj);	// 오브젝트를 추가하는 메서드
		void Add_UI(Object* ui);		// Ui를 추가하는 메서드
		void Release();					// 모든 게임 오브젝트를 해제하는 메서드
		void Camera_Move(int x, int y); // 화면을 인자값 만큼 이동하는 메서드
	};
}

