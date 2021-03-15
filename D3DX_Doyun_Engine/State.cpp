#include "State.h"

namespace DoEngine
{
	//������
	State::State()
	{
		State_Init();
	}

	//�Ҹ���
	State::~State()
	{

	}

	//�ൿ �ʱ�ȭ
	void State::State_Init()
	{
		curAni.clear();
		Ani_Now = 0;
		Delay = 0.0f;
		Time = 0.0f;
		DirCollx = 0;
		DirColly = 0;
	}

	//Animation ����
	bool State::Play_Animation(float _delay)
	{
		if (_delay != 70.0f)
		{
			Delay = _delay;
		}
		//���� ����ð� - ����Ƚð��� �����̺��� ũ��
		if (GetTickCount() - Time >= Delay)
		{
			// ����ð��� ���� �ð��� �����Ѵ�
			Time = GetTickCount();

			// ���� ���� �������� ��ǥ �����Ӱ� ���ٸ�
			if (Ani_Now == curAni.size() - 1)
			{
				// ���� �������� 0���� �ְ�
				Ani_Now = 0;

				// �ð� �ʱ�ȭ
				Time = 0;

				// true���� �����Ѵ�.
				return true;
			}

			// ���� �������� �ϳ� �ø���
			Ani_Now++;
			// �ؽ��ĸ� �ҷ����� �ٲ۴�.
			m_Texture = curAni[Ani_Now];
		}

		// �ִϸ��̼��� ���� �ƴ϶�� false�� ����
		return false;
	}

	//Draw�Լ�
	void State::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
	{
		DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx, _posy, _direction, _degree, _sizex, _sizey);
		m_Coll.Draw_Collision();

		m_FirstAttack.Draw_Collision();
		m_ThirdAttack.Draw_Collision();
	}

	//���� �ݶ��̴��� ����
	Collision State::get_Coll()
	{
		return m_Coll;
	}

	//���ؾ��� Animation set
	void State::set_BeforeState(State* _state)
	{
		
	}

	int State::get_curFrame()
	{
		return Ani_Now;
	}
};