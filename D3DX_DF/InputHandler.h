#pragma once
#include "GlobalDefines.h"
#include "Action.h"
#include "DoEngine.h"
#include "defines.h"

class InputHandler
{
private:
	DoEngine::Command* key_Stand;	//���
	DoEngine::Command* key_Left;	//���� Ŭ��(Key Press)
	DoEngine::Command* key_Right;	//������ Ŭ��(Key Press)
	DoEngine::Command* key_LeftUp;	//���� Ŭ��(Key Up)
	DoEngine::Command* key_RightUp;	//������ Ŭ��(Key Up)
	DoEngine::Command* key_Up;		//���� Ŭ��
	DoEngine::Command* key_Down;	//�Ʒ��� Ŭ��
	DoEngine::Command* Key_Attack;	//���� Ŭ��
public:
	InputHandler();//������

	DoEngine::Command* CommandInput(); //����� ������ �޼����

	~InputHandler();//�Ҹ���
};
