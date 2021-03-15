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
		// D3D �ʱ�ȭ
		g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		// true�� â���, false�� ��üȭ��
		d3dpp.Windowed = true;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		//ȭ�� ����� �°� ����� ����
		d3dpp.BackBufferWidth = _framex;
		d3dpp.BackBufferHeight = _framey;

		// ����̽� ����
		g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice);

		// ��������Ʈ�� ��Ʈ�� ����
		Create_Sprite();
		Create_Font();
	};

	void GraphicsManager::Create_Sprite()
	{
		// ��������Ʈ ����
		D3DXCreateSprite(g_pd3dDevice, &g_pSprite);
		D3DXCreateLine(g_pd3dDevice, &g_pLine); // Line ����
	}

	void GraphicsManager::Create_Font()
	{
		// ��Ʈ ����
		D3DXCreateFont(g_pd3dDevice, 30, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, NULL, NULL, NULL, "�������ü", &g_pFont);
	}

	void GraphicsManager::RenderStart()
	{
		// ȭ���� �����ϰ� �� ��, ����
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		g_pd3dDevice->BeginScene();
	}

	//�ܼ� �ؽ��ĸ� �׸���.
	void GraphicsManager::TextureRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction, float _sizex, float _sizey, int _alph)
	{
		D3DSURFACE_DESC		desc;
		_texture->GetLevelDesc(0, &desc);

		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = desc.Width;
		size.bottom = desc.Height;

		// ������Ʈ�� �������� �޴´�.
		// Radian���� ��ȯ�� ������ ȸ���� ����

		// ��Ʈ���� ����
		D3DXMATRIX mat;
		//�̵�
		D3DXMATRIX Trns;
		//ũ��
		D3DXMATRIX Scale;

		// ������ķ� �ʱ�ȭ
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&Trns);

		D3DXMatrixTranslation(&Trns, _posx, _posy, 0);
		D3DXMatrixScaling(&Scale, _sizex, _sizey, 0);

		// ��ü ��Ʈ������ ������s
		mat = Scale * Trns;

		if (!_direction)
		{
			//�¿� ����
			mat._11 = -_sizex;
		}

		// ����
		g_pSprite->SetTransform(&mat);

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pSprite->Draw(_texture, &size, NULL, NULL, D3DCOLOR_ARGB(_alph, 255, 255, 255));
		g_pSprite->End();
	}

	void GraphicsManager::ObjectRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction, float _degree, float _sizex, float _sizey)
	{	
		// ������Ʈ�� Visible�� true�� ��쿡�� �׸���.
		//if (obj->get_Visible() == true)
		//{
		// ������Ʈ�� ������
		D3DSURFACE_DESC		desc;
		_texture->GetLevelDesc(0, &desc);

		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = desc.Width;
		size.bottom = desc.Height;

		// ������Ʈ�� �������� �޴´�.
		// Radian���� ��ȯ�� ������ ȸ���� ����
		float Degree = D3DXToRadian(_degree);

		// ��Ʈ���� ����
		D3DXMATRIX mat;

		/*
		direction�� false��� ����, True��� �������� �ٶ󺻴�.
		*/
		if (!_direction)
		{
			_posx += 410 * _sizex;
		}
		
		//ȸ��, �̵�, ����, ������
		D3DXMATRIX Rot;
		D3DXMATRIX Trns;
		D3DXMATRIX Center;
		D3DXMATRIX Centerl;
		D3DXMATRIX Scale;

		//������ķ� �ʱ�ȭ
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&Rot);
		D3DXMatrixIdentity(&Trns);
		D3DXMatrixIdentity(&Center);
		D3DXMatrixIdentity(&Centerl);

		 //Z���� �������� Degree�� ��ŭ ȸ��
		D3DXMatrixRotationZ(&Rot, Degree);

		 //����� ����
		D3DXMatrixInverse(&Centerl, NULL, &Center);
		D3DXMatrixTranslation(&Trns, _posx, _posy, 0);

		 //���Ͱ��� �̵�(��ġ)���� ����
		D3DXMatrixTranslation(&Centerl, (-size.right / 2) * _sizex, (-size.bottom / 2) * _sizey, 0);
		D3DXMatrixScaling(&Scale, _sizex, _sizey, 0);

		 //��ü ��Ʈ������ ������
		mat = Scale * Centerl * Rot * Center * Trns;

		if (!_direction)
		{
			//�¿� ����
			mat._11 = -_sizex;
		}

		// ����
		g_pSprite->SetTransform(&mat);

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pSprite->Draw(_texture, &size, NULL, NULL, 0xffffffff);

		g_pSprite->End();
		//}
	}

	//�簢���� �׸� �׸���.
	void GraphicsManager::BoxRender(int _left, int _top, int _right, int _bottom, int _r, int _g, int _b)
	{
		g_pLine->SetWidth(2); // ������ ���⸦ ����

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
		// ������ ����
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
		// ������ ����
		g_pd3dDevice->EndScene();
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	void GraphicsManager::Release()
	{
		// ����̽��� D3D, ��������Ʈ, ��Ʈ ����

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
