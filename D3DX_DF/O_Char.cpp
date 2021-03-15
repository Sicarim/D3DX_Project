#include "O_Char.h"
#include "GraphicsManager.h"
#include "AnimationMaker.h"

O_Char::O_Char()
{
}


O_Char::~O_Char()
{
}

//초기화(시작 위치 초기화 가능)
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
	// 방향키 위
	if (GetKeyState(VK_UP) & 0x8000)
	{
		// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos += vec * 6;
	}

	// 방향키 아래
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
		D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));
		D3DXVec2Normalize(&vec, &vec);
		m_Pos -= vec * 6;
	}

	// 방향키 왼쪽
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		// 각도를 2를 뺀다.
		Degree -= 2;
	}

	// 방향키 오른쪽
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		// 각도를 2를 더한다.
		Degree += 2;
	}

	return false;
}

//Update함수
void O_Char::Update(float _fETime, float _posx, float _posy, bool _direction, float _degree, float _sizex, float _sizey)
{
	Play_Animation(stand, CHAR_DELAY);
	//m_Texture = DoEngine::AnimationMaker::get_Instance()->get_Texture("Resource\\", 9, CHAR_DELAY);
	
}

//Draw 함수(overloding)
void O_Char::Render()
{
	string tmp = to_string(Ani_Now);
	DoEngine::GraphicsManager::get_Instance()->ObjectRender(m_Texture, m_Pos.x, m_Pos.y, Degree);
	DoEngine::GraphicsManager::get_Instance()->Draw_Text(tmp, 400, 100, D3DCOLOR_XRGB(255, 255, 255));
}