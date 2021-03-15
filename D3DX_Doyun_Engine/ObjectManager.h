#pragma once
#include "GlobalDefines.h"
#include "Object.h"

using namespace std;

namespace DoEngine
{
	/**
	* @brief Object�� UI�� �����Ѵ�.
	* @details ���� Scene�� Object, ī�޶� ����Ѵ�.
	*/

	class ObjectManager
	{
	private:
		// ������Ʈ�� ������ ������Ʈ ���Ϳ� Ui ����
		vector<Object*> Object_Vector, UI_Vector;
	public:
		ObjectManager();
		~ObjectManager();

	public:
		void Add_Object(Object* obj);	// ������Ʈ�� �߰��ϴ� �޼���
		void Add_UI(Object* ui);		// Ui�� �߰��ϴ� �޼���
		void Release();					// ��� ���� ������Ʈ�� �����ϴ� �޼���
		void Camera_Move(int x, int y); // ȭ���� ���ڰ� ��ŭ �̵��ϴ� �޼���
	};
}

