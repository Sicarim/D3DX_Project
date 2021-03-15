#pragma once
#include "GlobalDefines.h"
#include "CollisionManager.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief 충돌을 감당하는 Collision
	* @details 충돌을 감지한다. Collision객체를 선언과 동시에 초기화를 하게 되면 CollisionManager에 Collision가 등록된다. 사용시 반드시 태그 지정이 필수
	*/

	class Collision
	{
	private:
		DoRECT	m_Rect;
		DoRECT	tmp_Rect;
		string	m_Tag;

		int		m_left, m_top, m_right, m_bottom;
		int		HitState;
		bool	isHitCheck,
				isBeforeHit,
				isDelete;

	public:
		Collision(); //생성자
		~Collision(); //소멸자
	public:
		void Init_Collision(string _tag, int _left, int _top, int _right, int _bottom); //콜라이더 범위 지정
		void Draw_Collision(); //콜라이더 범위 그리기
		DoRECT get_Collision(string _tag); //콜라이더 범위 리턴

		bool isCollision(string _tag); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollision(vector<string> _tags); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollision(string _tag, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollision(vector<string> _tags, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		void DeleteCollision(); //콜라이더 삭제하기
		void DeleteCollision(string _tag); //콜라이더 삭제하기
		void Release_Collision(); //콜라이더 초기화

		bool isInCollision(string _tag); //콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)
	};
};
