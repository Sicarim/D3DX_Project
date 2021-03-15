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
	* @brief 게임에 사용되는 Scene들의 부모 클래스
	* @details 게임에 사용되는 Scene들의 부모 클래스(중요!!!).Scene구현해야 하는 항목을 순수 가상 함수로 가지고 있음
	*/
	class Scene
	{
	protected:
		// 오브젝트 매니저를 선언한다.
		ObjectManager obj;
	public:
		Scene();
		~Scene();
	public:
		virtual void Init() = 0;				//Scene 초기화
		virtual bool Input(float _fETime) = 0;	//Scene 입력
		virtual void Update(float _fETime) = 0;	//Scene Update
		virtual void Render() = 0;				//Scene 그리기
		virtual void Release();					//Scene 지우기
	};
}

