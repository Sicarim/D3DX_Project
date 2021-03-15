#include "AnimationMaker.h"
#include "TextureManager.h"

namespace DoEngine
{
	//생성자
	AnimationMaker::AnimationMaker()
	{
	}

	//소멸자
	AnimationMaker::~AnimationMaker()
	{
		
	}

	//Maker 초기화
	void AnimationMaker::Ani_Init()
	{

	}

	//애니메이션 만들기
	vector<LPDIRECT3DTEXTURE9> AnimationMaker::Ani_Make(std::string path, int Frame)
	{
		//먼저 기존의 vector를 비운다.
		m_AniVector.clear();
		LPDIRECT3DTEXTURE9 tmp_Texture;
		Save_Path = path;

		for (int i = 0; i < Frame; i++)
		{
			path += to_string(i);
			path += ".png";
			tmp_Texture = TextureManager::get_Instance()->Load_Texture(path);
			m_AniVector.push_back(tmp_Texture);
			path = Save_Path;
		}
		
		return m_AniVector;
	}

	//애니메이션 리턴
	LPDIRECT3DTEXTURE9 AnimationMaker::get_Texture(string path)
	{
		return TextureManager::get_Instance()->Load_Texture(path);
	}
}