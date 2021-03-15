#pragma once
#include "GlobalDefines.h"
#include "CollisionManager.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief Trigger�� �����ϴ� Collision
	* @details Trigger�� �����Ѵ�. Collision��ü�� ����� ���ÿ� �ʱ�ȭ�� �ϰ� �Ǹ� CollisionManager�� Collision�� ��ϵȴ�. ���� �ݵ�� �±� ������ �ʼ�
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
		TriggerCollision(); //������

		void Init_Collision(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize); //�ݶ��̴� ���� ����
		bool Draw_Collision(string _tag); //�ݶ��̴� ���� �׸���
		DoRECT get_Collision(string _tag); //�ݶ��̴� ���� ����

		int isCollision(string _tag); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollision(vector<string> _tags); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollision(string _tag, int _state); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollision(vector<string> _tags, int _state); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		int HitDir_Check(DoRECT _rc); //��� ���⿡�� �⵿�ߴ°�??
		void DeleteCollision(); //�ݶ��̴� �����ϱ�

		bool isInCollision(string _tag); //�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)

		int get_HitDir(); //�浹 ���� ����

		~TriggerCollision(); //�Ҹ���
	};
}