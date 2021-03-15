#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "ComboList.h"
#include "BiceFirstAttack.h"

class ComboSystem
{
protected:
	ComboList Combo_Buffer;
	
	int			curKey;
	int			BeforeKey;
	float		sumTime;		//게임 시작시 시간을 저장한다.
	float		delTime;		//버퍼 삭제를 위함

public:
	ComboSystem(); //생성자
	~ComboSystem(); //소멸자
public:
	void	InputCommand(int _key);				//키 입력
	void	ClearQueue(queue<int> &q);		//Queue를 비운다

	virtual void	Init() = 0;
	virtual int		OutputKey() = 0;					//키 출력
	virtual int		CheckCommand() = 0;			//기술을 체크한다.
	virtual void	ComboUpdate(float _fETime) = 0;		//Combo_System Update
	virtual void	Combo_Release() = 0;				//ComboSystem 초기화
};