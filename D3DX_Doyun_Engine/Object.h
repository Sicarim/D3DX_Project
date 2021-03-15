#pragma once
#include "GlobalDefines.h"

namespace DoEngine
{
	/*
	* @brief 게임에 사용되는 UnitObject들의 부모 클래스
	* @details 게임에 사용되는 Unit들의 부모 클래스(중요!!!).구현해야 하는 항목을 순수 가상 함수로 가지고
		있음 - 정말 필요한 메서드들만 모아두었다. . - 컴포넌트 패턴을 잘 활용하라.
	*/

	class Object
	{
	protected:
		// 오브젝트가 가지고 있어야 할 값

		// 텍스쳐, 사이즈, 위치, 각도, Visible
		LPDIRECT3DTEXTURE9	m_Texture;
		D3DXVECTOR2			m_Size;
		D3DXVECTOR2			m_Pos;
		float				Degree;
		bool				Visible;

		// 애니메이션을 위한 값
		// 현재 몇 프레임인지, 체크를 위한 시간
		int					Ani_Now;
		float				Ani_Time;
	public:
		Object();
		~Object();

	public:
		virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0) = 0;	//초기화(시작 위치 초기화 가능)
		virtual bool Input(int _state = 0) = 0;			//Input, Key 입력
		virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f) = 0;			//Update함수
		virtual void Render() = 0;						//Draw 함수(overloding)

		// 메서드
		// 텍스쳐 불러오기
		void Load_Texture(std::string path);

		// 사이즈와 위치 적용
		void set_Size(int x, int y);
		void set_Pos(int x, int y);
		void set_Size(D3DXVECTOR2 size);
		void set_Pos(D3DXVECTOR2 pos);

		// 사이즈와 위치 가져오기
		D3DXVECTOR2 get_Size();
		D3DXVECTOR2 get_Pos();
		LPDIRECT3DTEXTURE9 get_Texture();
		float get_Degree();
		bool get_Visible();

		//애니메이션
		bool Play_Animation(vector< LPDIRECT3DTEXTURE9> _vec, float Delay);
	};
}
