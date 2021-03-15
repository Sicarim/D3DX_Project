#include "Object.h"
#include "TextureManager.h"
#include "GraphicsManager.h"

namespace DoEngine
{
	Object::Object()
	{
		// ������ 0��, 0������, Visible�� true�� ����
		Degree = 0;
		Ani_Now = 0;
		Visible = true;
	}

	Object::~Object()
	{
	}

	void Object::Load_Texture(std::string path)
	{
		// �ؽ��� Ŭ�������� �ؽ��ĸ� �ҷ��´�
		m_Texture = TextureManager::get_Instance()->Load_Texture(path);
	}

	void Object::set_Size(int x, int y)
	{
		// ũ�� ������ x, y���� ���Ѵ�
		m_Size.x = x;
		m_Size.y = y;
	}

	void Object::set_Pos(int x, int y)
	{
		// ��ġ ������ x, y���� ���Ѵ�
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
		 //���� ����ð� - ����Ƚð��� �����̺��� ũ��
		if (GetTickCount() - Ani_Time >= Delay)
		{
			// ����ð��� ���� �ð��� �����Ѵ�
			Ani_Time = GetTickCount();

			// ���� ���� �������� ��ǥ �����Ӱ� ���ٸ�
			if (Ani_Now == _vec.size() - 1)
			{
				// ���� �������� 0���� �ְ�
				Ani_Now = 0;

				// �ð� �ʱ�ȭ
				Ani_Time = 0;

				// true���� �����Ѵ�.
				return true;
			}

			// ���� �������� �ϳ� �ø���
			Ani_Now++;

			// �ؽ��ĸ� �ҷ����� �ٲ۴�.
			m_Texture = _vec[Ani_Now];
		}

		// �ִϸ��̼��� ���� �ƴ϶�� false�� ����
		return false;
	}
}
