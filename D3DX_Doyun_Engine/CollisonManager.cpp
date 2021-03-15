#include "CollisionManager.h"

namespace DoEngine
{
	//생성자
	CollisionManager::CollisionManager()
	{
		Draw_trigger = true;
	}

	//콜라이더 넣기
	void CollisionManager::Insert_Collision(string _tag, DoRECT _rect)
	{
		//콜라이더를 찾고 있다면 값을 갱신, 없다면 새로 만든다.
		auto iter = m_mapCollision.find(_tag);

		if (iter == m_mapCollision.end())
		{
			m_mapCollision.insert(make_pair(_tag, _rect));
		}
		else
		{
			iter->second = _rect;
		}
	}

	//콜라이더 검색하기
	DoRECT CollisionManager::Search_Collision(std::string _tag)
	{
		auto iter = m_mapCollision.find(_tag);

		if (iter != m_mapCollision.end())
		{
			return iter->second;
		}
	}

	//콜라이더를 삭제한다
	void CollisionManager::Release_Collision(string _tag)
	{
		m_mapCollision.erase(_tag);
	}

	//모든 콜라이더 범위를 그린다.
	void CollisionManager::set_DrawCollision(bool _trigger)
	{
		Draw_trigger = _trigger;
	}

	//모든 콜라이더 범위를 그린다.
	bool CollisionManager::get_DrawCollision()
	{
		return Draw_trigger;
	}

	//모든 콜라이더를 비운다
	void CollisionManager::Clear_Collision()
	{
		m_mapCollision.clear();
	}

	//소멸자
	CollisionManager::~CollisionManager()
	{

	}
}