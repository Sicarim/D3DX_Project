#pragma once
#include "GlobalDefines.h"

namespace DoEngine
{
	/*
	* @brief ���ӿ� ���Ǵ� UnitObject���� �θ� Ŭ����
	* @details ���ӿ� ���Ǵ� Unit���� �θ� Ŭ����(�߿�!!!).�����ؾ� �ϴ� �׸��� ���� ���� �Լ��� ������
		���� - ���� �ʿ��� �޼���鸸 ��Ƶξ���. . - ������Ʈ ������ �� Ȱ���϶�.
	*/

	class Object
	{
	protected:
		// ������Ʈ�� ������ �־�� �� ��

		// �ؽ���, ������, ��ġ, ����, Visible
		LPDIRECT3DTEXTURE9	m_Texture;
		D3DXVECTOR2			m_Size;
		D3DXVECTOR2			m_Pos;
		float				Degree;
		bool				Visible;

		// �ִϸ��̼��� ���� ��
		// ���� �� ����������, üũ�� ���� �ð�
		int					Ani_Now;
		float				Ani_Time;
	public:
		Object();
		~Object();

	public:
		virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0) = 0;	//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)
		virtual bool Input(int _state = 0) = 0;			//Input, Key �Է�
		virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f) = 0;			//Update�Լ�
		virtual void Render() = 0;						//Draw �Լ�(overloding)

		// �޼���
		// �ؽ��� �ҷ�����
		void Load_Texture(std::string path);

		// ������� ��ġ ����
		void set_Size(int x, int y);
		void set_Pos(int x, int y);
		void set_Size(D3DXVECTOR2 size);
		void set_Pos(D3DXVECTOR2 pos);

		// ������� ��ġ ��������
		D3DXVECTOR2 get_Size();
		D3DXVECTOR2 get_Pos();
		LPDIRECT3DTEXTURE9 get_Texture();
		float get_Degree();
		bool get_Visible();

		//�ִϸ��̼�
		bool Play_Animation(vector< LPDIRECT3DTEXTURE9> _vec, float Delay);
	};
}
