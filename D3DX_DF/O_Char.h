#pragma once
//////////////////////////////////////////////////////////////
//////////////////////  캐릭터 클래스  ///////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "Object.h"
#include "defines.h"

class O_Char : public DoEngine::Object	// 게임 오브젝트를 상속받는다.
{
private:
	vector<LPDIRECT3DTEXTURE9> stand;
public:
	O_Char();
	virtual  ~O_Char();

	// Key를 체크하는 메서드
	virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);	//초기화(시작 위치 초기화 가능)
	virtual bool Input(int _state = 0);
	virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);			//Update함수
	virtual void Render();						//Draw 함수(overloding)
};

