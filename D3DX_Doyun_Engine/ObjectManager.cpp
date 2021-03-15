#include "ObjectManager.h"

namespace DoEngine
{
	ObjectManager::ObjectManager()
	{
	}


	ObjectManager::~ObjectManager()
	{
	}

	void ObjectManager::Add_Object(Object* obj)
	{
		// ������Ʈ ���Ϳ� ���� ������Ʈ�� �ִ´�.
		Object_Vector.push_back(obj);
	}

	void ObjectManager::Add_UI(Object* ui)
	{
		// Ui ���Ϳ� ���� ������Ʈ�� �ִ´�.
		UI_Vector.push_back(ui);
	}

	void ObjectManager::Release()
	{
		// ������Ʈ ���Ϳ� Ui ���͸� ũ�⸸ŭ for���� ������ ���� ��
		for (int i = 0; i < Object_Vector.size(); i++)
		{
			delete Object_Vector[i];
		}
		for (int i = 0; i < UI_Vector.size(); i++)
		{
			delete UI_Vector[i];
		}

		// ���͵��� ����.
		Object_Vector.clear();
		UI_Vector.clear();
	}

	void ObjectManager::Camera_Move(int x, int y)
	{
		// ������Ʈ�� ũ�⸸ŭ for���� ������
		for (int i = 0; i < Object_Vector.size(); i++)
		{
			// ������Ʈ ���� ��, Ui�� �ƴ� ������Ʈ���� ���� �̵���Ų��.
			// �׷� Ui�� ������ �ְ� �ٸ� ������Ʈ���� ���� ���ڰ� x, y��ŭ �����δ�.
			Object_Vector[i]->set_Pos(Object_Vector[i]->get_Pos().x - x, Object_Vector[i]->get_Pos().y - y);
		}
	}
}
