#pragma once
#include "GlobalDefines.h"
#include "CollisionManager.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief Trigger를 감지하는 Collision
	* @details Trigger를 감지한다. Collision객체를 선언과 동시에 초기화를 하게 되면 CollisionManager에 Collision가 등록된다. 사용시 반드시 태그 지정이 필수
	*/

	class TriggerCollision
	{
	private:
		TCHAR buf[255];
		DoRECT m_Rect;
		DoRECT tmp_Rect;
		string m_Tag;
		int HitState;
		int Hit_dir;
		bool isHitCheck, isBeforeHit, isDelete;
		int m_left, m_top, m_right, m_bottom;

	public:
		TriggerCollision(); //생성자

		void Init_Collision(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize); //콜라이더 범위 지정
		bool Draw_Collision(string _tag); //콜라이더 범위 그리기
		DoRECT get_Collision(string _tag); //콜라이더 범위 리턴

		int isCollision(string _tag); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollision(vector<string> _tags); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollision(string _tag, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollision(vector<string> _tags, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		int HitDir_Check(DoRECT _rc); //어느 방향에서 출동했는가??
		void DeleteCollision(); //콜라이더 삭제하기

		bool isInCollision(string _tag); //콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)

		int get_HitDir(); //충돌 방향 리턴

		~TriggerCollision(); //소멸자
	};
}