#include "State.h"

namespace DoEngine
{
	//생성자
	State::State()
	{
		State_Init();
	}

	//소멸자
	State::~State()
	{

	}

	//행동 초기화
	void State::State_Init()
	{
		curAni.clear();
		Ani_Now = 0;
		Delay = 0.0f;
		Time = 0.0f;
		DirCollx = 0;
		DirColly = 0;
	}

	//Animation 실행
	bool State::Play_Animation(float _delay)
	{
		if (_delay != 70.0f)
		{
			Delay = _delay;
		}
		//만약 현재시간 - 저장된시간이 딜레이보다 크면
		if (GetTickCount() - Time >= Delay)
		{
			// 저장시간에 현재 시간을 저장한다
			Time = GetTickCount();

			// 만약 현재 프레임이 목표 프레임과 같다면
			if (Ani_Now == curAni.size() - 1)
			{
				// 현재 프레임을 0으로 주고
				Ani_Now = 0;

				// 시간 초기화
				Time = 0;

				// true값을 리턴한다.
				return true;
			}

			// 현재 프레임을 하나 늘리고
			Ani_Now++;
			// 텍스쳐를 불러온후 바꾼다.
			m_Texture = curAni[Ani_Now];
		}

		// 애니메이션이 끝이 아니라면 false을 리턴
		return false;
	}

	//Draw함수
	void State::Render(float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
	{
		DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, _posx, _posy, _direction, _degree, _sizex, _sizey);
		m_Coll.Draw_Collision();

		m_FirstAttack.Draw_Collision();
		m_ThirdAttack.Draw_Collision();
	}

	//현재 콜라이더를 리턴
	Collision State::get_Coll()
	{
		return m_Coll;
	}

	//행해야할 Animation set
	void State::set_BeforeState(State* _state)
	{
		
	}

	int State::get_curFrame()
	{
		return Ani_Now;
	}
};