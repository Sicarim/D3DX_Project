#include "InputHandler.h"
#include "InputManager.h"

//생성자
InputHandler::InputHandler()
{
	key_Stand	= NULL;
	key_Left	= NULL;
	key_Right	= NULL;
	key_LeftUp = NULL;
	key_RightUp = NULL;
	key_Up		= NULL;
	key_Down	= NULL;
	Key_Attack	= NULL;
}

//명령을 실행할 메서드들
DoEngine::Command* InputHandler::CommandInput()
{
	//왼쪽
	if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_LEFT))
	{
		if (key_Left == NULL)
		{
			key_Left = new DoEngine::LeftCommand;
		}
		return key_Left;
	}
	//오른쪽
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_RIGHT))
	{
		if (key_Right == NULL)
		{
			key_Right = new DoEngine::RightCommand;
		}
		return key_Right;
	}

	//왼쪽(KeyUp)
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_LEFT))
	{
		if (key_LeftUp == NULL)
		{
			key_LeftUp = new DoEngine::LeftKeyUpCommand;
		}
		return key_LeftUp;
	}

	//오른쪽(KeyUp)
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RIGHT))
	{
		if (key_RightUp == NULL)
		{
			key_RightUp = new DoEngine::RightKeyUpCommand;
		}
		return key_RightUp;
	}

	//위쪽
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_UP))
	{
		if (key_Up == NULL)
		{
			key_Up = new DoEngine::UpCommand;
		}
		return key_Up;
	}
	//아래쪽
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_DOWN))
	{
		if (key_Down == NULL)
		{
			key_Down = new DoEngine::DownCommand;
		}
		return key_Down;
	}
	//공격 버튼
	else if (DoEngine::InputManager::get_Instance()->isKeyDown(BUTTON_X))
	{
		if (Key_Attack == NULL)
		{
			Key_Attack = new DoEngine::AttackCommand;
		}
		return Key_Attack;
	}
	else
	{
		if (key_Stand == NULL)
		{
			key_Stand = new DoEngine::StandCommand;
		}
		return key_Stand;
	}

	return NULL;
}

//소멸자
InputHandler::~InputHandler()
{

}