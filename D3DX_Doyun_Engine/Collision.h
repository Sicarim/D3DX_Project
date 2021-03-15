#pragma once
#include "GlobalDefines.h"
#include "CollisionManager.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief �浹�� �����ϴ� Collision
	* @details �浹�� �����Ѵ�. Collision��ü�� ����� ���ÿ� �ʱ�ȭ�� �ϰ� �Ǹ� CollisionManager�� Collision�� ��ϵȴ�. ���� �ݵ�� �±� ������ �ʼ�
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
		Collision(); //������
		~Collision(); //�Ҹ���
	public:
		void Init_Collision(string _tag, int _left, int _top, int _right, int _bottom); //�ݶ��̴� ���� ����
		void Draw_Collision(); //�ݶ��̴� ���� �׸���
		DoRECT get_Collision(string _tag); //�ݶ��̴� ���� ����

		bool isCollision(string _tag); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollision(vector<string> _tags); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollision(string _tag, int _state); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollision(vector<string> _tags, int _state); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		void DeleteCollision(); //�ݶ��̴� �����ϱ�
		void DeleteCollision(string _tag); //�ݶ��̴� �����ϱ�
		void Release_Collision(); //�ݶ��̴� �ʱ�ȭ

		bool isInCollision(string _tag); //�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)
	};
};
