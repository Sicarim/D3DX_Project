#include "BiceWork.h"
#include "AnimationMaker.h"

//������
BiceWork::BiceWork()
{
}

//�Ҹ���
BiceWork::~BiceWork()
{
}
//Init�Լ�(override)
void BiceWork::Init()
{
	curAni = DoEngine::AnimationMaker::get_Instance()->Ani_Make("Resource\\Character\\FiendWar\\Bice\\Run\\", 10);
}

//Update�Լ�(override)
void BiceWork::Update(string _tag, float _posx, float _posy, bool _direction)
{
	m_Coll.Init_Collision(_tag, _posx - 80, _posy - 30, 120, 180);
}

//���� ���·� ��ȯ(override)
void BiceWork::Enter()
{
	Delay = 70.0f;
}

//���� ��Ȳ���� �� �ൿ(override)
void BiceWork::Excute()
{
}

//���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)
bool BiceWork::Exit()
{
	Delay = 0.0f;
	return true;
}