#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"
#include "Object.h"

//using namespace std;
namespace DoEngine
{
	/**
	* @brief 엔진의 그래픽을 담당하는 클래스
	* @details 엔진의 InitD3D, Render, Release등을 담당한다.
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
		ID3DXLine*			g_pLine; //Line그리기

		// 초기화와 생성, Render, 해제
		void Init(HWND hWnd, int _framex, int _framey);	//D3D Init, 클래스에서 각종 필요한 변수 초기화
		void RenderStart();		//그림을 그리기전에 해야할 행동을 정의
		void RenderEnd();		//그림을 끝내고 해제

		void Create_Sprite();	//스프라이트 생성
		void Create_Font();		//폰트 생성

		//void Render(Object* obj);	//그림을 그린다.
		void TextureRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction = true, float _sizex = 1.0f, float _sizey = 1.0f, int _alph = 255); //단순 텍스쳐를 그린다.
		void ObjectRender(LPDIRECT3DTEXTURE9 _texture, int _posx, int _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);//오브젝트그림을 그린다.
		void BoxRender(int _left, int _top, int _right, int _bottom, int _r, int _g, int _b);															//사각형의 네모를 그린다.
		void Draw_Text(string Text, int x, int y, D3DXCOLOR color);

		void Release();			//Release함수
	};
}