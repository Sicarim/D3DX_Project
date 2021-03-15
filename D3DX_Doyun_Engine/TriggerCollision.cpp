#include "TriggerCollision.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	//생성자
	TriggerCollision::TriggerCollision()
	{
		isHitCheck = false;
		isDelete = false;
		Hit_dir = 0;
	}

	//콜라이더 범위 지정 (태그, 좌표 = Left, Top, Right, Bottom)
	void TriggerCollision::Init_Collision(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize)
	{
		wsprintf(buf, "Trigger%s", _tag);
		m_Tag = buf;
		m_left = _left - _leftsize;
		m_top = _top - _topsize;
		m_right = _left + _right + _leftsize;
		m_bottom = _top + _bottom + _topsize;

		m_Rect = { m_left, m_top, m_right, m_bottom };
		//CollisionManager에 콜라이더 등록
		//DoEngine::CollisionManager::get_Instance()->Insert_Collision(m_Tag, m_Rect.get_Rect());
		DoEngine::CollisionManager::get_Instance()->Insert_Collision(m_Tag, m_Rect);
	}

	//콜라이더 범위 그리기
	bool TriggerCollision::Draw_Collision(string _tag)
	{
		if (CollisionManager::get_Instance()->get_DrawCollision())
		{
			if (!isDelete)
			{
				//범위 안에 들어왔다면 빨간색으로 그리기
				if (isCollision(_tag) > 0)
				{
					DoEngine::GraphicsManager::get_Instance()->BoxRender(m_left, m_top, m_right, m_bottom, 255, 0, 0);
					//m_Collision = CreatePen(PS_SOLID, 3, RGB(205, 16, 57));
					//m_oldCollision = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collision);

					////투명하게 그리기
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
					//파란색으로 그리기
					//m_Collision = CreatePen(PS_SOLID, 3, RGB(0, 100, 255));
					//m_oldCollision = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collision);

					////투명하게 그리기
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

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)
	int TriggerCollision::isCollision(string _tag)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);
		Hit_dir = HitDir_Check(tmp_rc);

		return m_Rect.isOutCollision(tmp_rc);
	}

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
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

		//충돌 체크 여부
		if (!m_Rect.isOutCollision(tmp_rc))
		{
			isHitCheck = false;
			return false;
		}

		else
		{
			//최초로 부딛혓는가?
			if (!isHitCheck)
			{
				isHitCheck = true;
				HitState = _state;
			}

			//부딪친 방향과 가려고 하는 방향이 같은가?
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

			//충돌 체크 여부
			if (!m_Rect.isOutCollision(tmp_rc) && !isHitCheck)
			{
				isHitCheck = false;
				isBeforeHit = false;
			}

			else
			{
				//최초로 부딛혓는가?
				if (!isHitCheck)
				{
					isBeforeHit = true;
					isHitCheck = true;
					HitState = _state;
				}

				//부딪친 방향과 가려고 하는 방향이 같은가?
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

	//어느 방향에서 출동했는가??
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

	//콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)
	bool TriggerCollision::isInCollision(string _tag)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//콜라이더 범위 리턴
	DoRECT TriggerCollision::get_Collision(string _tag)
	{
		return DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);
	}

	//콜라이더 삭제하기
	void TriggerCollision::DeleteCollision()
	{
		DoEngine::CollisionManager::get_Instance()->Release_Collision(m_Tag);
		isDelete = true;
	}

	//충돌 방향 리턴
	int TriggerCollision::get_HitDir()
	{
		return Hit_dir;
	}

	//소멸자
	TriggerCollision::~TriggerCollision()
	{

	}
}