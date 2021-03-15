#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief Collision를 관리하는 Manager
	* @details 콜라이더를 선언하면 자동적으로 배열을 만든다. 기존에 같은 태그를 가진 배열이 존재한다면 추가를 하고, 없다면 새로 만들어서 추가를 한다.
	*/

	class CollisionManager : public Singleton<CollisionManager>
	{
	private:
		map<string, DoRECT>	m_mapCollision; //일련의 태그를 가진 RECT(콜라이더)의 집합
		bool				Draw_trigger;
	public:
		CollisionManager(); //생성자
		~CollisionManager(); //소멸자
	public:
		void Insert_Collision(string _tag, DoRECT _rect); //콜라이더 넣기
		DoRECT Search_Collision(std::string _tag); //콜라이더 검색하기
		void Release_Collision(string _tag); //콜라이더를 삭제한다
		void set_DrawCollision(bool _trigger = true); //모든 콜라이더 범위를 그린다.
		bool get_DrawCollision(); //모든 콜라이더 범위를 그린다.
		void Clear_Collision(); //모든 콜라이더를 비운다
	};
}