#include "GraphicsManager.h"

namespace DoEngine
{

	GraphicsManager::GraphicsManager()
	{
	}


	GraphicsManager::~GraphicsManager()
	{
	}

	void GraphicsManager::Init(HWND hWnd, int _framex, int _framey)
	{
		// D3D 초기화
		g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		// true면 창모드, false면 전체화면
		d3dpp.Windowed = true;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		//화면 사이즈에 맞게 백버퍼 변경
		d3dpp.BackBufferWidth = _framex;
		d3dpp.BackBufferHeight = _framey;

		// 디바이스 생성
		g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice);

		// 스프라이트와 폰트를 생성
		Create_Sprite();
		Create_Font();
	};

	void GraphicsManager::Create_Sprite()
	{
		// 스프라이트 생성
		D3DXCreateSprite(g_pd3dDevice, &g_pSprite);
		D3DXCreateLine(g_pd3dDevice, &g_pLine); // Line 생성
	}

	void GraphicsManager::Create_Font()
	{
		// 폰트 생성
		D3DXCreateFont(g_pd3dDevice, 30, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, NULL, NULL, NULL, "맑은고딕체", &g_pFont);
	}

	void GraphicsManager::RenderStart()
	{
		// 화면을 깨끗하게 한 후, 시작
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		g_pd3dDevice->BeginScene();
	}

	//단순 텍스쳐를 그린다.
	void GraphicsManager::TextureRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction, float _sizex, float _sizey, int _alph)
	{
		D3DSURFACE_DESC		desc;
		_texture->GetLevelDesc(0, &desc);

		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = desc.Width;
		size.bottom = desc.Height;

		// 오브젝트의 각도값을 받는다.
		// Radian으로 변환한 이유는 회전을 위해

		// 메트릭스 선언
		D3DXMATRIX mat;
		//이동
		D3DXMATRIX Trns;
		//크기
		D3DXMATRIX Scale;

		// 단위행렬로 초기화
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&Trns);

		D3DXMatrixTranslation(&Trns, _posx, _posy, 0);
		D3DXMatrixScaling(&Scale, _sizex, _sizey, 0);

		// 전체 메트릭스에 곱한후s
		mat = Scale * Trns;

		if (!_direction)
		{
			//좌우 반전
			mat._11 = -_sizex;
		}

		// 적용
		g_pSprite->SetTransform(&mat);

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pSprite->Draw(_texture, &size, NULL, NULL, D3DCOLOR_ARGB(_alph, 255, 255, 255));
		g_pSprite->End();
	}

	void GraphicsManager::ObjectRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction, float _degree, float _sizex, float _sizey)
	{	
		// 오브젝트의 Visible이 true일 경우에만 그린다.
		//if (obj->get_Visible() == true)
		//{
		// 오브젝트의 사이즈
		D3DSURFACE_DESC		desc;
		_texture->GetLevelDesc(0, &desc);

		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = desc.Width;
		size.bottom = desc.Height;

		// 오브젝트의 각도값을 받는다.
		// Radian으로 변환한 이유는 회전을 위해
		float Degree = D3DXToRadian(_degree);

		// 메트릭스 선언
		D3DXMATRIX mat;

		/*
		direction이 false라면 왼쪽, True라면 오른쪽을 바라본다.
		*/
		if (!_direction)
		{
			_posx += 410 * _sizex;
		}
		
		//회전, 이동, 센터, 역센터
		D3DXMATRIX Rot;
		D3DXMATRIX Trns;
		D3DXMATRIX Center;
		D3DXMATRIX Centerl;
		D3DXMATRIX Scale;

		//단위행렬로 초기화
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&Rot);
		D3DXMatrixIdentity(&Trns);
		D3DXMatrixIdentity(&Center);
		D3DXMatrixIdentity(&Centerl);

		 //Z축을 기준으로 Degree값 만큼 회전
		D3DXMatrixRotationZ(&Rot, Degree);

		 //역행렬 적용
		D3DXMatrixInverse(&Centerl, NULL, &Center);
		D3DXMatrixTranslation(&Trns, _posx, _posy, 0);

		 //센터값과 이동(위치)값을 적용
		D3DXMatrixTranslation(&Centerl, (-size.right / 2) * _sizex, (-size.bottom / 2) * _sizey, 0);
		D3DXMatrixScaling(&Scale, _sizex, _sizey, 0);

		 //전체 메트릭스에 곱한후
		mat = Scale * Centerl * Rot * Center * Trns;

		if (!_direction)
		{
			//좌우 반전
			mat._11 = -_sizex;
		}

		// 적용
		g_pSprite->SetTransform(&mat);

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pSprite->Draw(_texture, &size, NULL, NULL, 0xffffffff);

		g_pSprite->End();
		//}
	}

	//사각형의 네모를 그린다.
	void GraphicsManager::BoxRender(int _left, int _top, int _right, int _bottom, int _r, int _g, int _b)
	{
		g_pLine->SetWidth(2); // 라인의 굵기를 설정

		D3DXVECTOR2 vList[] = {
			D3DXVECTOR2(_left, _top),
			D3DXVECTOR2(_left, _bottom),
			D3DXVECTOR2(_right, _bottom),
			D3DXVECTOR2(_right, _top),
			D3DXVECTOR2(_left, _top)
		};

		g_pLine->Begin();

		g_pLine->Draw(vList, 5, D3DCOLOR_XRGB(_r, _g, _b));

		g_pLine->End();
	}

	void GraphicsManager::Draw_Text(string Text, int x, int y, D3DXCOLOR color)
	{
		// 사이즈 정의
		RECT size;
		size.top = y;
		size.left = x;
		size.right = 0;
		size.bottom = 0;

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pFont->DrawTextA(g_pSprite, Text.c_str(), -1, &size, DT_NOCLIP, color);

		g_pSprite->End();
	}

	void GraphicsManager::RenderEnd()
	{
		// 끝낸후 해제
		g_pd3dDevice->EndScene();
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	void GraphicsManager::Release()
	{
		// 디바이스와 D3D, 스프라이트, 폰트 해제

		if (g_pd3dDevice != NULL)
			g_pd3dDevice->Release();

		if (g_pD3D != NULL)
			g_pD3D->Release();

		if (g_pSprite != NULL)
			g_pSprite->Release();

		if (g_pFont != NULL)
			g_pFont->Release();
	}
}
