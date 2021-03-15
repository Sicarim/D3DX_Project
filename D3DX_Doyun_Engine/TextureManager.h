#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"

namespace DoEngine
{
	/**
	* @brief DoEngine::Texture클레스를 관리하는 클래스
	* @details DoEngine::Texture클레스를 관리하는 클래스 , 같은 DoEngine::Texture 객체가 생성되는 것을 막아주고 파일로드를 담당.
	*/

	// 텍스쳐 정보를 담고있는 구조체
	class TextureManager : public Singleton<TextureManager>
	{
	private:
		//텍스쳐를 관리할 Map
		map<string, LPDIRECT3DTEXTURE9>	m_mapTexture;

		string							path;
		LPDIRECT3DTEXTURE9				Texture;
	public:
		TextureManager();
		~TextureManager();

	public:
		// 텍스쳐 불러오기, 추가, 해제
		LPDIRECT3DTEXTURE9 Load_Texture(string path);
		void Add_Texture(string path);
		void Release();
	};
}



