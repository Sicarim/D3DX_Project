#include "CollisionManager.h"

namespace DoEngine
{
	//������
	CollisionManager::CollisionManager()
	{
		Draw_trigger = true;
	}

	//�ݶ��̴� �ֱ�
	void CollisionManager::Insert_Collision(string _tag, DoRECT _rect)
	{
		//�ݶ��̴��� ã�� �ִٸ� ���� ����, ���ٸ� ���� �����.
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

	//�ݶ��̴� �˻��ϱ�
	DoRECT CollisionManager::Search_Collision(std::string _tag)
	{
		auto iter = m_mapCollision.find(_tag);

		if (iter != m_mapCollision.end())
		{
			return iter->second;
		}
	}

	//�ݶ��̴��� �����Ѵ�
	void CollisionManager::Release_Collision(string _tag)
	{
		m_mapCollision.erase(_tag);
	}

	//��� �ݶ��̴� ������ �׸���.
	void CollisionManager::set_DrawCollision(bool _trigger)
	{
		Draw_trigger = _trigger;
	}

	//��� �ݶ��̴� ������ �׸���.
	bool CollisionManager::get_DrawCollision()
	{
		return Draw_trigger;
	}

	//��� �ݶ��̴��� ����
	void CollisionManager::Clear_Collision()
	{
		m_mapCollision.clear();
	}

	//�Ҹ���
	CollisionManager::~CollisionManager()
	{

	}
}