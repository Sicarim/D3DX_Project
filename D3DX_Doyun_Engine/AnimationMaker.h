#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"

namespace DoEngine
{
	class AnimationMaker : public Singleton<AnimationMaker>
	{
	private:
		// 애니메이션을 위한 값
		// 현재 몇 프레임인지, 체크를 위한 시간
		float						Ani_Time;
		string						Save_Path; //첫 경로를 저장
		vector<LPDIRECT3DTEXTURE9>	m_AniVector;
	public:
		AnimationMaker(); //생성자
		~AnimationMaker(); //소멸자
	public:
		void Ani_Init(); //Maker 초기화
		vector<LPDIRECT3DTEXTURE9> Ani_Make(std::string path, int Frame); //애니메이션 만들기
		LPDIRECT3DTEXTURE9 get_Texture(string path); //애니메이션 리턴
	};
}