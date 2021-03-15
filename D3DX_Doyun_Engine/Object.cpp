#include "Object.h"
#include "TextureManager.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	Object::Object()
	{
		// 각도를 0도, 0프레임, Visible을 true로 설정
		Degree = 0;
		Ani_Now = 0;
		Visible = true;
	}

	Object::~Object()
	{
	}

	void Object::Load_Texture(std::string path)
	{
		// 텍스쳐 클래스에서 텍스쳐를 불러온다
		m_Texture = TextureManager::get_Instance()->Load_Texture(path);
	}

	void Object::set_Size(int x, int y)
	{
		// 크기 벡터의 x, y값을 정한다
		m_Size.x = x;
		m_Size.y = y;
	}

	void Object::set_Pos(int x, int y)
	{
		// 위치 벡터의 x, y값을 정한다
		m_Pos.x = x;
		m_Pos.y = y;
	}

	void Object::set_Size(D3DXVECTOR2 size)
	{
		m_Size = size;
	}

	void Object::set_Pos(D3DXVECTOR2 pos)
	{
		m_Pos = pos;
	}

	D3DXVECTOR2 Object::get_Size()
	{
		return m_Size;
	}

	D3DXVECTOR2 Object::get_Pos()
	{
		return m_Pos;
	}

	LPDIRECT3DTEXTURE9 Object::get_Texture()
	{
		return m_Texture;
	}

	float Object::get_Degree()
	{
		return Degree;
	}

	bool Object::get_Visible()
	{
		return Visible;
	}

	bool Object::Play_Animation(vector< LPDIRECT3DTEXTURE9> _vec, float Delay)
	{
		 //만약 현재시간 - 저장된시간이 딜레이보다 크면
		if (GetTickCount() - Ani_Time >= Delay)
		{
			// 저장시간에 현재 시간을 저장한다
			Ani_Time = GetTickCount();

			// 만약 현재 프레임이 목표 프레임과 같다면
			if (Ani_Now == _vec.size() - 1)
			{
				// 현재 프레임을 0으로 주고
				Ani_Now = 0;

				// 시간 초기화
				Ani_Time = 0;

				// true값을 리턴한다.
				return true;
			}

			// 현재 프레임을 하나 늘리고
			Ani_Now++;

			// 텍스쳐를 불러온후 바꾼다.
			m_Texture = _vec[Ani_Now];
		}

		// 애니메이션이 끝이 아니라면 false을 리턴
		return false;
	}
}
