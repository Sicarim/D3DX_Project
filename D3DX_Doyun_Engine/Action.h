#pragma once
#include "GlobalDefines.h"
#include "Command.h"

namespace DoEngine
{
	/*
		@brief ĳ���� �����ӿ� ���ؼ� �����Ѵ�.
		@details �̵�, ����, �Ѿ� �߻� �� ���� �ൿ�� ���� ������ �ô´�.
	*/
	//��� ����
	class StandCommand : public Command
	{
	private:

	public:
		StandCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~StandCommand() {} //�Ҹ���
	};

	//�������� �̵��ϱ�
	class LeftCommand : public Command
	{
	private:

	public:
		LeftCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~LeftCommand() {} //�Ҹ���
	};

	//���������� �̵��ϱ�
	class RightCommand : public Command
	{
	private:
	public:
		RightCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~RightCommand() {} //�Ҹ���
	};

	//�������� �̵��ϱ�
	class LeftKeyUpCommand : public Command
	{
	private:

	public:
		LeftKeyUpCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~LeftKeyUpCommand() {} //�Ҹ���
	};

	//���������� �̵��ϱ�
	class RightKeyUpCommand : public Command
	{
	private:
	public:
		RightKeyUpCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~RightKeyUpCommand() {} //�Ҹ���
	};

	//���� �̵��ϱ�
	class UpCommand : public Command
	{
	private:
	public:
		UpCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~UpCommand() {} //�Ҹ���
	};

	//�Ʒ��� �̵��ϱ�
	class DownCommand : public Command
	{
	private:
	public:
		DownCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~DownCommand() {} //�Ҹ���
	};

	//����
	class JumpCommand : public Command
	{
	private:
	public:
		JumpCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~JumpCommand() {} //�Ҹ���
	};

	//����
	class AttackCommand : public Command
	{
	private:
	public:
		AttackCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(UserScript& _actor);

		virtual ~AttackCommand() {} //�Ҹ���
	};
}