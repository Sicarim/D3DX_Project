#pragma once
#include "DoEngine.h"
#include "Collision.h"

namespace DoEngine
{
	/**
	* @brief �ൿ���� ������ �߻� Ŭ����
	* @detail �� �ൿ�� �θ� Ŭ����
	*/

	class State
	{
	protected:
		vector<LPDIRECT3DTEXTURE9>	curAni; //���� ���¿��� ���ؾ��� �ִϸ��̼�
		LPDIRECT3DTEXTURE9			m_Texture;
		State*						BeforeState; //���� �ൿ, ���� �ൿ�� ���ϱ��� �ٷ� ���� �ൿ
		Collision					m_Coll; //���� �浹 ����

		DoEngine::Collision m_FirstAttack;
		DoEngine::Collision m_ThirdAttack;

		//DoEngine::Collision Uclid

		// �ִϸ��̼��� ���� ��
		// ���� �� ����������, üũ�� ���� �ð�
		int					Ani_Now;
		float				Time;
		float				Delay;
		float				DirCollx;
		float				DirColly;
	public:
		State(); //������
		virtual ~State(); //�Ҹ���
	public:
		void State_Init();								//�ൿ �ʱ�ȭ
		bool Play_Animation(float _delay = 70.0f);							//Animation ����
		int get_curFrame();
		void set_BeforeState(State* _state);		//���ؾ��� Animation set
		Collision get_Coll(); //���� �ݶ��̴��� ����

		virtual void Init() = 0;						//Init�Լ�
		virtual void Update(string _tag, float _posx, float _posy, bool _direction) = 0;			//Update�Լ�
		virtual void Enter() = 0;						//���� ���·� ��ȯ
		virtual void Excute() = 0;						//���� ��Ȳ���� �� �ൿ
		virtual bool Exit() = 0;						//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ
		virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);	//Draw�Լ�
	};
}