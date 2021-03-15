#include "POINT.h"

namespace DoEngine
{
	POINT::POINT()
	{
		x = 0;
		y = 0;
	}

	POINT::POINT(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	POINT::~POINT()
	{

	}


	POINTF::POINTF()
	{
		x = 0;
		y = 0;
	}

	POINTF::POINTF(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	POINTF::~POINTF()
	{

	}

	DoRECT::DoRECT()
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

	DoRECT::DoRECT(int _left, int _top, int _right, int _bottom)
	{
		left = _left;
		top = _top;
		right = _right;
		bottom = _bottom;
	}

	DoRECT::~DoRECT()
	{

	}

	//충돌 여부 검사(밖에서 부딪치는지 검사, 무언가가 부딪칠때)
	bool DoRECT::isOutCollision(DoRECT _rcOther)
	{
		if (left <= _rcOther.right && top <= _rcOther.bottom && right >= _rcOther.left && bottom >= _rcOther.top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//충돌 여부 검사(안에서 밖으로 부딪치는지 검사, 무언가를 범위 밖으로 나가지 못하게)
	bool DoRECT::isInCollision(DoRECT _rcOther)
	{
		if (right < _rcOther.right && bottom <= _rcOther.bottom && left > _rcOther.left&& top > _rcOther.top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//마우스 포인트가 안에 있는가 검사
	bool DoRECT::isPtin(POINT _ptOther)
	{
		if (left < _ptOther.x && right > _ptOther.x&& top < _ptOther.y && bottom > _ptOther.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
