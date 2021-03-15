#include "Collision.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	//������
	Collision::Collision()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//�ݶ��̴� ���� ���� (�±�, ��ǥ = Left, Top, Right, Bottom)
	void Collision::Init_Collision(string _tag, int _left, int _top, int _right, int _bottom)
	{
		//�±׿� Top, Left, Right, Bottom�� ����
		m_Tag = _tag;
		m_left = _left;
		m_top = _top;
		m_right = _left + _right;
		m_bottom = _top + _bottom;
		isDelete = false;
		m_Rect = { m_left, m_top, m_right, m_bottom };
		//CollisionManager�� �ݶ��̴� ���
		DoEngine::CollisionManager::get_Instance()->Insert_Collision(m_Tag, m_Rect);
	}

	//�ݶ��̴� ���� �׸���
	void Collision::Draw_Collision()
	{
		if (CollisionManager::get_Instance()->get_DrawCollision())
		{
			if (!isDelete)
			{
				DoEngine::GraphicsManager::get_Instance()->BoxRender(m_left, m_top, m_right, m_bottom, 0, 255, 0);
				////�ʷϻ����� �׸���
				//m_Collision = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
				//m_oldCollision = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collision);

				////�����ϰ� �׸���
				//brush_Collision = (HBRUSH)GetStockObject(NULL_BRUSH);
				//brush_oldCollision = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collision);

				//Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

				//DeleteObject(m_oldCollision);
				//DeleteObject(brush_oldCollision);
			}
		}
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)
	bool Collision::isCollision(string _tag)
	{
		//�ش� Tag�� CollisionManager���� ã�� ��, �ӽ�Rect�� ��´�.
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		//�浹 ���θ� ����
		return m_Rect.isOutCollision(tmp_rc);
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
	bool Collision::isCollision(vector<string> _tags)
	{
		//Collision Vector���� �ش� �±׸� ã�� ��, �浹���θ� ����
		DoRECT tmp_rc;

		for (int i = 0; i < _tags.size(); i++)
		{
			tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tags[i]);

			if (m_Rect.isOutCollision(tmp_rc))
			{
				return true;
			}
		}
		return false;
	}

	bool Collision::isCollision(string _tag, int _state)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		//�浹 üũ ����
		if (!m_Rect.isOutCollision(tmp_rc))
		{
			isHitCheck = false;
			return false;
		}

		else
		{
			//���ʷ� �ε����°�?
			if (!isHitCheck)
			{
				isHitCheck = true;
				HitState = _state;
			}

			//�ε�ģ ����� ������ �ϴ� ������ ������?
			if (_state != HitState)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}

	bool Collision::isCollision(vector<string> _tags, int _state)
	{
		for (int i = 0; i < _tags.size(); i++)
		{
			DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tags[i]);

			if (m_Rect.isOutCollision(tmp_rc))
			{
				break;
			}

			if (i == _tags.size() - 1)
			{
				isHitCheck = false;
				isBeforeHit = false;
				return false;
			}
		}

		for (int i = 0; i < _tags.size(); i++)
		{
			DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tags[i]);

			//�浹 üũ ����
			if (!m_Rect.isOutCollision(tmp_rc) && !isHitCheck)
			{
				isHitCheck = false;
				isBeforeHit = false;
			}

			else
			{
				//���ʷ� �ε����°�?
				if (!isHitCheck)
				{
					isBeforeHit = true;
					isHitCheck = true;
					HitState = _state;
				}

				//�ε�ģ ����� ������ �ϴ� ������ ������?
				if (_state != HitState)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)
	bool Collision::isInCollision(string _tag)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//�ݶ��̴� ���� ����
	DoRECT Collision::get_Collision(string _tag)
	{
		return DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);
	}

	//�ݶ��̴� �����ϱ�
	void Collision::DeleteCollision()
	{
		DoEngine::CollisionManager::get_Instance()->Release_Collision(m_Tag);
		isDelete = true;
	}

	//�ݶ��̴� �����ϱ�
	void Collision::DeleteCollision(string _tag)
	{
		DoEngine::CollisionManager::get_Instance()->Release_Collision(_tag);
		isDelete = true;
	}

	//�ݶ��̴� �ʱ�ȭ
	void Collision::Release_Collision()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//�Ҹ���
	Collision::~Collision()
	{

	}
}