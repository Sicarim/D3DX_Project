#pragma once
#include "DoEngine.h"
#include "Collision.h"

namespace DoEngine
{
	/**
	* @brief 행동들을 정의할 추상 클래스
	* @detail 각 행동의 부모 클래스
	*/

	class State
	{
	protected:
		vector<LPDIRECT3DTEXTURE9>	curAni; //현재 상태에서 행해야할 애니메이션
		LPDIRECT3DTEXTURE9			m_Texture;
		State*						BeforeState; //이전 행동, 현재 행동을 행하기전 바로 이전 행동
		Collision					m_Coll; //현재 충돌 범위

		DoEngine::Collision m_FirstAttack;
		DoEngine::Collision m_ThirdAttack;

		//DoEngine::Collision Uclid

		// 애니메이션을 위한 값
		// 현재 몇 프레임인지, 체크를 위한 시간
		int					Ani_Now;
		float				Time;
		float				Delay;
		float				DirCollx;
		float				DirColly;
	public:
		State(); //생성자
		virtual ~State(); //소멸자
	public:
		void State_Init();								//행동 초기화
		bool Play_Animation(float _delay = 70.0f);							//Animation 실행
		int get_curFrame();
		void set_BeforeState(State* _state);		//행해야할 Animation set
		Collision get_Coll(); //현재 콜라이더를 리턴

		virtual void Init() = 0;						//Init함수
		virtual void Update(string _tag, float _posx, float _posy, bool _direction) = 0;			//Update함수
		virtual void Enter() = 0;						//다음 상태로 전환
		virtual void Excute() = 0;						//현재 상황에서 할 행동
		virtual bool Exit() = 0;						//다음 상황으로 넘어가기전 해야하는 행동
		virtual void Render(float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);	//Draw함수
	};
}