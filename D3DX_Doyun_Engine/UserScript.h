#pragma once
#include "GlobalDefines.h"
#include "Object.h"

namespace DoEngine
{
	/*
	* @brief Player �Ǵ� EnemyAI�� �̸� ��ӹ޾� ����Ѵ�.
	* @details Player(AI)�� ����� �Լ����� ����
	*/
	class UserScript
	{
	protected:
		D3DXVECTOR2		m_Pos;
		string			Tag;
		bool			Direction;
		float			Degree;
		bool			Visible;
	public:
		UserScript();			//������
		virtual ~UserScript();	//�Ҹ���
	public:
		virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0) = 0;
		virtual bool Input(int _state) = 0;
		virtual void Update(float _fETime) = 0;
		virtual void Render() = 0;
		virtual void Release() = 0;

		virtual Object* ReturnObject() = 0;
	};
}