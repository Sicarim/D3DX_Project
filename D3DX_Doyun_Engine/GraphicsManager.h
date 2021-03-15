#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"
#include "Object.h"

//using namespace std;
namespace DoEngine
{
	/**
	* @brief ������ �׷����� ����ϴ� Ŭ����
	* @details ������ InitD3D, Render, Release���� ����Ѵ�.
	*/
	class GraphicsManager : public Singleton<GraphicsManager>
	{
	public:
		GraphicsManager();
		~GraphicsManager();

	public:
		LPDIRECT3D9         g_pD3D;
		LPDIRECT3DDEVICE9   g_pd3dDevice;
		LPD3DXSPRITE		g_pSprite;
		LPD3DXFONT			g_pFont;
		WNDCLASSEX			wc;
		HWND				hWnd;

		//D3DSURFACE_DESC		desc;
		ID3DXLine*			g_pLine; //Line�׸���

		// �ʱ�ȭ�� ����, Render, ����
		void Init(HWND hWnd, int _framex, int _framey);	//D3D Init, Ŭ�������� ���� �ʿ��� ���� �ʱ�ȭ
		void RenderStart();		//�׸��� �׸������� �ؾ��� �ൿ�� ����
		void RenderEnd();		//�׸��� ������ ����

		void Create_Sprite();	//��������Ʈ ����
		void Create_Font();		//��Ʈ ����

		//void Render(Object* obj);	//�׸��� �׸���.
		void TextureRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction = true, float _sizex = 1.0f, float _sizey = 1.0f, int _alph = 255); //�ܼ� �ؽ��ĸ� �׸���.
		void ObjectRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);//������Ʈ�׸��� �׸���.
		void BoxRender(int _left, int _top, int _right, int _bottom, int _r, int _g, int _b);															//�簢���� �׸� �׸���.
		void Draw_Text(string Text, int x, int y, D3DXCOLOR color);

		void Release();			//Release�Լ�
	};
}