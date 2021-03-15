#include "TriggerCollision.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	//������
	TriggerCollision::TriggerCollision()
	{
		isHitCheck = false;
		isDelete = false;
		Hit_dir = 0;
	}

	//�ݶ��̴� ���� ���� (�±�, ��ǥ = Left, Top, Right, Bottom)
	void TriggerCollision::Init_Collision(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize)
	{
		wsprintf(buf, "Trigger%s", _tag);
		m_Tag = buf;
		m_left = _left - _leftsize;
		m_top = _top - _topsize;
		m_right = _left + _right + _leftsize;
		m_bottom = _top + _bottom + _topsize;

		m_Rect = { m_left, m_top, m_right, m_bottom };
		//CollisionManager�� �ݶ��̴� ���
		//DoEngine::CollisionManager::get_Instance()->Insert_Collision(m_Tag, m_Rect.get_Rect());
		DoEngine::CollisionManager::get_Instance()->Insert_Collision(m_Tag, m_Rect);
	}

	//�ݶ��̴� ���� �׸���
	bool TriggerCollision::Draw_Collision(string _tag)
	{
		if (CollisionManager::get_Instance()->get_DrawCollision())
		{
			if (!isDelete)
			{
				//���� �ȿ� ���Դٸ� ���������� �׸���
				if (isCollision(_tag) > 0)
				{
					DoEngine::GraphicsManager::get_Instance()->BoxRender(m_left, m_top, m_right, m_bottom, 255, 0, 0);
					//m_Collision = CreatePen(PS_SOLID, 3, RGB(205, 16, 57));
					//m_oldCollision = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collision);

					////�����ϰ� �׸���
					//brush_Collision = (HBRUSH)GetStockObject(NULL_BRUSH);
					//brush_oldCollision = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collision);

					//Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

					//DeleteObject(m_oldCollision);
					//DeleteObject(brush_oldCollision);

					return true;
				}
				else
				{
					DoEngine::GraphicsManager::get_Instance()->BoxRender(m_left, m_top, m_right, m_bottom, 0, 0, 255);
					//�Ķ������� �׸���
					//m_Collision = CreatePen(PS_SOLID, 3, RGB(0, 100, 255));
					//m_oldCollision = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collision);

					////�����ϰ� �׸���
					//brush_Collision = (HBRUSH)GetStockObject(NULL_BRUSH);
					//brush_oldCollision = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collision);

					//Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

					//DeleteObject(m_oldCollision);
					//DeleteObject(brush_oldCollision);

					return false;
				}
			}
		}
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)
	int TriggerCollision::isCollision(string _tag)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);
		Hit_dir = HitDir_Check(tmp_rc);

		return m_Rect.isOutCollision(tmp_rc);
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
	bool TriggerCollision::isCollision(vector<string> _tags)
	{
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

	bool TriggerCollision::isCollision(string _tag, int _state)
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

	bool TriggerCollision::isCollision(vector<string> _tags, int _state)
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

	//��� ���⿡�� �⵿�ߴ°�??
	int TriggerCollision::HitDir_Check(DoRECT _rc)
	{
		if (m_left < _rc.right && m_right > _rc.right&& m_top < _rc.top && m_bottom > _rc.bottom)
		{
			return LEFT;
		}

		else if (m_right > _rc.left&& m_left < _rc.left && m_top < _rc.top && m_bottom > _rc.bottom)
		{
			return RIGHT;
		}

		else if (m_top < _rc.bottom && m_left < _rc.left && m_right > _rc.right&& m_bottom > _rc.bottom)
		{
			return UP;
		}

		else if (m_bottom > _rc.top&& m_left < _rc.left && m_right > _rc.right&& m_top < _rc.top)
		{
			return DOWN;
		}
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)
	bool TriggerCollision::isInCollision(string _tag)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//�ݶ��̴� ���� ����
	DoRECT TriggerCollision::get_Collision(string _tag)
	{
		return DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);
	}

	//�ݶ��̴� �����ϱ�
	void TriggerCollision::DeleteCollision()
	{
		DoEngine::CollisionManager::get_Instance()->Release_Collision(m_Tag);
		isDelete = true;
	}

	//�浹 ���� ����
	int TriggerCollision::get_HitDir()
	{
		return Hit_dir;
	}

	//�Ҹ���
	TriggerCollision::~TriggerCollision()
	{

	}
}