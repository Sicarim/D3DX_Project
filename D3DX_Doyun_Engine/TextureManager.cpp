#include "TextureManager.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	TextureManager::TextureManager()
	{
	}


	TextureManager::~TextureManager()
	{
	}

	LPDIRECT3DTEXTURE9 TextureManager::Load_Texture(string path)
	{
		auto iter = m_mapTexture.find(path);

		if (iter != m_mapTexture.end())
		{
			return iter->second;
		}

		// ���� �̹����� Map�� ���ٸ� �̹����� �߰����� �ٽ� ������.
		Add_Texture(path);
		return Load_Texture(path);
	}

	void TextureManager::Add_Texture(string path)
	{
		D3DXCreateTextureFromFileEx(GraphicsManager::get_Instance()->g_pd3dDevice,
			path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			1,
			1,
			NULL,
			NULL,
			NULL,
			&Texture);

		/*if (&Texture == NULL)
		{
			MessageBox(NULL, path.c_str(), "File Not Find", MB_OK);
			return;
		}*/

		// path�� �ؽ��Ŀ� ���� �־��ٸ� Map�� �����Ѵ�.
		m_mapTexture.insert(make_pair(path, Texture));
	}

	void TextureManager::Release()
	{
		//auto iter = 
		for (auto iter = m_mapTexture.begin(); iter != m_mapTexture.end(); iter++)
		{
			iter->second->Release();
		}

		m_mapTexture.clear();
	}
}