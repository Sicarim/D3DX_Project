#include "AnimationMaker.h"
#include "TextureManager.h"

namespace DoEngine
{
	//������
	AnimationMaker::AnimationMaker()
	{
	}

	//�Ҹ���
	AnimationMaker::~AnimationMaker()
	{
		
	}

	//Maker �ʱ�ȭ
	void AnimationMaker::Ani_Init()
	{

	}

	//�ִϸ��̼� �����
	vector<LPDIRECT3DTEXTURE9> AnimationMaker::Ani_Make(std::string path, int Frame)
	{
		//���� ������ vector�� ����.
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

	//�ִϸ��̼� ����
	LPDIRECT3DTEXTURE9 AnimationMaker::get_Texture(string path)
	{
		return TextureManager::get_Instance()->Load_Texture(path);
	}
}