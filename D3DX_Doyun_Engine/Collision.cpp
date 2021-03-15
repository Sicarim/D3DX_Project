#include "Collision.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	//생성자
	Collision::Collision()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//콜라이더 범위 지정 (태그, 좌표 = Left, Top, Right, Bottom)
	void Collision::Init_Collision(string _tag, int _left, int _top, int _right, int _bottom)
	{
		//태그와 Top, Left, Right, Bottom을 지정
		m_Tag = _tag;
		m_left = _left;
		m_top = _top;
		m_right = _left + _right;
		m_bottom = _top + _bottom;
		isDelete = false;
		m_Rect = { m_left, m_top, m_right, m_bottom };
		//CollisionManager에 콜라이더 등록
		DoEngine::CollisionManager::get_Instance()->Insert_Collision(m_Tag, m_Rect);
	}

	//콜라이더 범위 그리기
	void Collision::Draw_Collision()
	{
		if (CollisionManager::get_Instance()->get_DrawCollision())
		{
			if (!isDelete)
			{
				DoEngine::GraphicsManager::get_Instance()->BoxRender(m_left, m_top, m_right, m_bottom, 0, 255, 0);
				////초록색으로 그리기
				//m_Collision = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
				//m_oldCollision = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collision);

				////투명하게 그리기
				//brush_Collision = (HBRUSH)GetStockObject(NULL_BRUSH);
				//brush_oldCollision = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collision);

				//Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

				//DeleteObject(m_oldCollision);
				//DeleteObject(brush_oldCollision);
			}
		}
	}

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)
	bool Collision::isCollision(string _tag)
	{
		//해당 Tag를 CollisionManager에서 찾은 후, 임시Rect에 담는다.
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		//충돌 여부를 리턴
		return m_Rect.isOutCollision(tmp_rc);
	}

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
	bool Collision::isCollision(vector<string> _tags)
	{
		//Collision Vector에서 해당 태그를 찾은 후, 충돌여부를 리턴
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

	//콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)
	bool Collision::isInCollision(string _tag)
	{
		DoRECT tmp_rc = DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//콜라이더 범위 리턴
	DoRECT Collision::get_Collision(string _tag)
	{
		return DoEngine::CollisionManager::get_Instance()->Search_Collision(_tag);
	}

	//콜라이더 삭제하기
	void Collision::DeleteCollision()
	{
		DoEngine::CollisionManager::get_Instance()->Release_Collision(m_Tag);
		isDelete = true;
	}

	//콜라이더 삭제하기
	void Collision::DeleteCollision(string _tag)
	{
		DoEngine::CollisionManager::get_Instance()->Release_Collision(_tag);
		isDelete = true;
	}

	//콜라이더 초기화
	void Collision::Release_Collision()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//소멸자
	Collision::~Collision()
	{

	}
}