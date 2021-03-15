#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"

namespace DoEngine
{
	/**
	* @brief DoEngine::TextureŬ������ �����ϴ� Ŭ����
	* @details DoEngine::TextureŬ������ �����ϴ� Ŭ���� , ���� DoEngine::Texture ��ü�� �����Ǵ� ���� �����ְ� ���Ϸε带 ���.
	*/

	// �ؽ��� ������ ����ִ� ����ü
	class TextureManager : public Singleton<TextureManager>
	{
	private:
		//�ؽ��ĸ� ������ Map
		map<string, LPDIRECT3DTEXTURE9>	m_mapTexture;

		string							path;
		LPDIRECT3DTEXTURE9				Texture;
	public:
		TextureManager();
		~TextureManager();

	public:
		// �ؽ��� �ҷ�����, �߰�, ����
		LPDIRECT3DTEXTURE9 Load_Texture(string path);
		void Add_Texture(string path);
		void Release();
	};
}



