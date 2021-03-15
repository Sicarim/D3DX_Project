#pragma once
//////////////////////////////////////////////////////////////
//////////////////////  ĳ���� Ŭ����  ///////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "Object.h"
#include "defines.h"

class O_Char : public DoEngine::Object	// ���� ������Ʈ�� ��ӹ޴´�.
{
private:
	vector<LPDIRECT3DTEXTURE9> stand;
public:
	O_Char();
	virtual  ~O_Char();

	// Key�� üũ�ϴ� �޼���
	virtual void Init(string _Tag = NULL, float _x = 0, float _y = 0, bool _direction = 0);	//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)
	virtual bool Input(int _state = 0);
	virtual void Update(float _fETime, float _posx, float _posy, bool _direction, float _degree = 0, float _sizex = 1.0f, float _sizey = 1.0f);			//Update�Լ�
	virtual void Render();						//Draw �Լ�(overloding)
};

