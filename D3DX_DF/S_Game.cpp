#include "S_Game.h"
#include "InputManager.h"
#include "O_Char.h"


S_Game::S_Game()
{
}


S_Game::~S_Game()
{
}

// �ʱ�ȭ �Լ�
void S_Game::Init()
{
	// ����� ���
	DoEngine::SoundManager::get_Instance()->Play_Bg("Resource/bg.mp3");

	// ĳ���͸� �޸� �Ҵ����� �ؽ��ĸ� �ҷ�����, ũ��, ��ġ���� �ش�.
	m_Char2 = new O_Char();

	m_Char2->Init();


	// ������Ʈ ���Ϳ� ĳ���͸� �ִ´�.
	obj.Add_Object(m_Char2);
}

bool S_Game::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	m_Char2->Input();
	return false;
}

// ������Ʈ, �� �����Ӹ��� ȣ��ȴ�.
void S_Game::Update(float _fETime)
{
	// �浹üũ�� �ϰ�ʹٸ� �浹üũ �޼������ ��ȯ���� bool ���̹Ƿ�
	// if�� �Ἥ �⵿üũ Ȯ���� �� �� �ִ�.
	// ������� 
	//
	//if (CollisionManager::get_Instance()->Circle_Check(m_Char->GetPos().x, m_Char->GetPos().y, m_Enemy->GetPos().x, m_Enemy->GetPos().y, 200))
	//{
	//	//m_Enemy��� ������Ʈ�� �����ؼ� ĳ������ x, y��, ���� x, y���� �Ѱ��ְ� �浹üũ ����� �ְ�
	//	//�浹üũ �޼����� ��ȯ���� true �� �浹�� �Ȱ� �̱� ������ �浹�� �ȴٸ� �ؿ� ȿ������ ��µɰ��̴�.
	//
	//	//ȿ���� ���
	//	SoundManager::get_Instance()->Play_Ef("Resource/ex.wav");
	//}
	//m_Char2->Update(_fETime);
}

// �׸���
void S_Game::Render()
{
	// ĳ���� �׸���
	m_Char2->Render();
}