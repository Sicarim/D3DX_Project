#include "Action.h"

namespace DoEngine
{
	//대기 자세
	void StandCommand::excute(UserScript& _actor)
	{
		_actor.Input(STAND);
	}

	//왼쪽으로 이동하기
	void LeftCommand::excute(UserScript& _actor)
	{
		_actor.Input(LEFT);
	}

	//오른쪽으로 이동하기
	void RightCommand::excute(UserScript& _actor)
	{
		_actor.Input(RIGHT);
	}

	//왼쪽으로 이동하기(KeyUp)
	void LeftKeyUpCommand::excute(UserScript& _actor)
	{
		_actor.Input(LEFT_KEYUP);
	}

	//오른쪽으로 이동하기(KeyUp)
	void RightKeyUpCommand::excute(UserScript& _actor)
	{
		_actor.Input(RIGHT_KEYUP);
	}

	//위로 이동하기
	void UpCommand::excute(UserScript& _actor)
	{
		_actor.Input(UP);
	}

	//아래로 이동하기
	void DownCommand::excute(UserScript& _actor)
	{
		_actor.Input(DOWN);
	}

	//점프하기
	void JumpCommand::excute(UserScript& _actor)
	{

	}

	//공격하기
	void AttackCommand::excute(UserScript& _actor)
	{
		_actor.Input(ATTACK);
	}
}
