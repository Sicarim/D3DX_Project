#include "Scene.h"

namespace DoEngine
{
	Scene::Scene()
	{
	}


	Scene::~Scene()
	{
	}

	void Scene::Release()
	{
		// �ؽ��Ŀ� ������Ʈ�� ��� �����Ѵ�.
		TextureManager::get_Instance()->Release();
		obj.Release();
	}
}

