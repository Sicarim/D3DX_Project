#include "BiceDown.h"
#include "AnimationMaker.h"

//������
BiceDown::BiceDown()
{
}

//�Ҹ���
BiceDown::~BiceDown()
{
}
//Init�Լ�(override)
void BiceDown::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Down\\", 3);
}

//Update�Լ�(override)
void BiceDown::Update(string _tag, float _posx, float _posy, bool _direction)
{

}

//���� ���·� ��ȯ(override)
void BiceDown::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceDown::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceDown::Exit()
{
	Delay = 0.0f;
	return true;
}