#pragma once
#include "GlobalDefines.h"
#include "Command.h"

namespace DoEngine
{
	/*
		@brief 캐릭터 움직임에 대해서 관장한다.
		@details 이동, 점프, 총알 발사 등 각종 행동에 대한 구현을 맡는다.
	*/
	//대기 상태
	class StandCommand : public Command
	{
	private:

	public:
		StandCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~StandCommand() {} //소멸자
	};

	//왼쪽으로 이동하기
	class LeftCommand : public Command
	{
	private:

	public:
		LeftCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~LeftCommand() {} //소멸자
	};

	//오른쪽으로 이동하기
	class RightCommand : public Command
	{
	private:
	public:
		RightCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~RightCommand() {} //소멸자
	};

	//왼쪽으로 이동하기
	class LeftKeyUpCommand : public Command
	{
	private:

	public:
		LeftKeyUpCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~LeftKeyUpCommand() {} //소멸자
	};

	//오른쪽으로 이동하기
	class RightKeyUpCommand : public Command
	{
	private:
	public:
		RightKeyUpCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~RightKeyUpCommand() {} //소멸자
	};

	//위로 이동하기
	class UpCommand : public Command
	{
	private:
	public:
		UpCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~UpCommand() {} //소멸자
	};

	//아래로 이동하기
	class DownCommand : public Command
	{
	private:
	public:
		DownCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~DownCommand() {} //소멸자
	};

	//점프
	class JumpCommand : public Command
	{
	private:
	public:
		JumpCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~JumpCommand() {} //소멸자
	};

	//점프
	class AttackCommand : public Command
	{
	private:
	public:
		AttackCommand() {} //생성자

		//행동을 실행하는 함수
		virtual void excute(UserScript& _actor);

		virtual ~AttackCommand() {} //소멸자
	};
}