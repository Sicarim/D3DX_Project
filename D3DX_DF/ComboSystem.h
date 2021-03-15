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
	float		sumTime;		//���� ���۽� �ð��� �����Ѵ�.
	float		delTime;		//���� ������ ����

public:
	ComboSystem(); //������
	~ComboSystem(); //�Ҹ���
public:
	void	InputCommand(int _key);				//Ű �Է�
	void	ClearQueue(queue<int> &q);		//Queue�� ����

	virtual void	Init() = 0;
	virtual int		OutputKey() = 0;					//Ű ���
	virtual int		CheckCommand() = 0;			//����� üũ�Ѵ�.
	virtual void	ComboUpdate(float _fETime) = 0;		//Combo_System Update
	virtual void	Combo_Release() = 0;				//ComboSystem �ʱ�ȭ
};