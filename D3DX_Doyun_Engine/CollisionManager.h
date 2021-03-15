#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief Collision�� �����ϴ� Manager
	* @details �ݶ��̴��� �����ϸ� �ڵ������� �迭�� �����. ������ ���� �±׸� ���� �迭�� �����Ѵٸ� �߰��� �ϰ�, ���ٸ� ���� ���� �߰��� �Ѵ�.
	*/

	class CollisionManager : public Singleton<CollisionManager>
	{
	private:
		map<string, DoRECT>	m_mapCollision; //�Ϸ��� �±׸� ���� RECT(�ݶ��̴�)�� ����
		bool				Draw_trigger;
	public:
		CollisionManager(); //������
		~CollisionManager(); //�Ҹ���
	public:
		void Insert_Collision(string _tag, DoRECT _rect); //�ݶ��̴� �ֱ�
		DoRECT Search_Collision(std::string _tag); //�ݶ��̴� �˻��ϱ�
		void Release_Collision(string _tag); //�ݶ��̴��� �����Ѵ�
		void set_DrawCollision(bool _trigger = true); //��� �ݶ��̴� ������ �׸���.
		bool get_DrawCollision(); //��� �ݶ��̴� ������ �׸���.
		void Clear_Collision(); //��� �ݶ��̴��� ����
	};
}