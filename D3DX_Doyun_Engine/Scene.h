#pragma once
#include "GlobalDefines.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "ObjectManager.h"
#include "SoundManager.h"
#include "TextureManager.h"

namespace DoEngine
{
	/**
	* @brief ���ӿ� ���Ǵ� Scene���� �θ� Ŭ����
	* @details ���ӿ� ���Ǵ� Scene���� �θ� Ŭ����(�߿�!!!).Scene�����ؾ� �ϴ� �׸��� ���� ���� �Լ��� ������ ����
	*/
	class Scene
	{
	protected:
		// ������Ʈ �Ŵ����� �����Ѵ�.
		ObjectManager obj;
	public:
		Scene();
		~Scene();
	public:
		virtual void Init() = 0;				//Scene �ʱ�ȭ
		virtual bool Input(float _fETime) = 0;	//Scene �Է�
		virtual void Update(float _fETime) = 0;	//Scene Update
		virtual void Render() = 0;				//Scene �׸���
		virtual void Release();					//Scene �����
	};
}

