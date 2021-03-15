#include "O_Char.h"
#include "GraphicsManager.h"
#include "AnimationMaker.h"

O_Char::O_Char()
{
}


O_Char::~O_Char()
{
}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)
void O_Char::Init(string _Tag, float _x, float _y, bool _direction)
{
	//Load_Texture("Resource\\char.png");
	//Load_Texture("Resource\\5.bmp");
	stand = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\", 10);
	m_Pos.x = 100;
	m_Pos.y = 500;
	m_Size.x = 467;
	m_Size.y = 328;
}


bool O_Char::Input(int _state)
{
	// ����Ű ��
	if (GetKeyState(VK_UP) & 0x8000)
	{
		// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos += vec * 6;
	}

	// ����Ű �Ʒ�
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		// ���͸� �����ϰ� ����ȭ���� ������ �ӵ��� ������Ʈ�� ������ �������� �̵�
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos -= vec * 6;
	}

	// ����Ű ����
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		// ������ 2�� ����.
		Degree -= 2;
	}

	// ����Ű ������
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		// ������ 2�� ���Ѵ�.
		Degree += 2;
	}

	return false;
}

//Update�Լ�
void O_Char::Update(float _fETime, float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	Play_Animation(stand, CHAR_DELAY);
	//m_Texture = DoEngine::AnimationMaker::get_Instance()->get_Texture("Resource\\", 9, CHAR_DELAY);
	
}

//Draw �Լ�(overloding)
void O_Char::Render()
{
	string tmp = to_string(Ani_Now);
	DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, m_Pos.x, m_Pos.y, Degree);
	DoEngine::GraphicsManager::get_Instance()->Draw_Text(tmp, 400, 100, D3DCOLOR_XRGB(255, 255, 255));
}