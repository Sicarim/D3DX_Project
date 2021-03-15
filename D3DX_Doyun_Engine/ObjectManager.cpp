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
		// 오브젝트 벡터에 게임 오브젝트를 넣는다.
		Object_Vector.push_back(obj);
	}

	void ObjectManager::Add_UI(Object* ui)
	{
		// Ui 벡터에 게임 오브젝트를 넣는다.
		UI_Vector.push_back(ui);
	}

	void ObjectManager::Release()
	{
		// 오브젝트 벡터와 Ui 벡터를 크기만큼 for문을 돌려서 삭제 후
		for (int i = 0; i < Object_Vector.size(); i++)
		{
			delete Object_Vector[i];
		}
		for (int i = 0; i < UI_Vector.size(); i++)
		{
			delete UI_Vector[i];
		}

		// 벡터들을 비운다.
		Object_Vector.clear();
		UI_Vector.clear();
	}

	void ObjectManager::Camera_Move(int x, int y)
	{
		// 오브젝트의 크기만큼 for문을 돌린후
		for (int i = 0; i < Object_Vector.size(); i++)
		{
			// 오브젝트 벡터 즉, Ui가 아닌 오브젝트들을 전부 이동시킨다.
			// 그럼 Ui는 가만히 있고 다른 오브젝트들은 전부 인자값 x, y만큼 움직인다.
			Object_Vector[i]->set_Pos(Object_Vector[i]->get_Pos().x - x, Object_Vector[i]->get_Pos().y - y);
		}
	}
}
