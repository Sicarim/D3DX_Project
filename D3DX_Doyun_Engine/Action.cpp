#include "Action.h"

namespace DoEngine
{
	//��� �ڼ�
	void StandCommand::excute(UserScript& _actor)
	{
		_actor.Input(STAND);
	}

	//�������� �̵��ϱ�
	void LeftCommand::excute(UserScript& _actor)
	{
		_actor.Input(LEFT);
	}

	//���������� �̵��ϱ�
	void RightCommand::excute(UserScript& _actor)
	{
		_actor.Input(RIGHT);
	}

	//�������� �̵��ϱ�(KeyUp)
	void LeftKeyUpCommand::excute(UserScript& _actor)
	{
		_actor.Input(LEFT_KEYUP);
	}

	//���������� �̵��ϱ�(KeyUp)
	void RightKeyUpCommand::excute(UserScript& _actor)
	{
		_actor.Input(RIGHT_KEYUP);
	}

	//���� �̵��ϱ�
	void UpCommand::excute(UserScript& _actor)
	{
		_actor.Input(UP);
	}

	//�Ʒ��� �̵��ϱ�
	void DownCommand::excute(UserScript& _actor)
	{
		_actor.Input(DOWN);
	}

	//�����ϱ�
	void JumpCommand::excute(UserScript& _actor)
	{

	}

	//�����ϱ�
	void AttackCommand::excute(UserScript& _actor)
	{
		_actor.Input(ATTACK);
	}
}
