#include "S_Game.h"
#include "InputManager.h"
#include "O_Char.h"


S_Game::S_Game()
{
}


S_Game::~S_Game()
{
}

// 초기화 함수
void S_Game::Init()
{
	// 배경음 출력
	DoEngine::SoundManager::get_Instance()->Play_Bg("Resource/bg.mp3");

	// 캐릭터를 메모리 할당이후 텍스쳐를 불러오고, 크기, 위치값을 준다.
	m_Char2 = new O_Char();

	m_Char2->Init();


	// 오브젝트 벡터에 캐릭터를 넣는다.
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

// 업데이트, 매 프레임마다 호출된다.
void S_Game::Update(float _fETime)
{
	// 충돌체크를 하고싶다면 충돌체크 메서드들의 반환값이 bool 값이므로
	// if를 써서 출동체크 확인을 할 수 있다.
	// 예를들어 
	//
	//if (CollisionManager::get_Instance()->Circle_Check(m_Char->GetPos().x, m_Char->GetPos().y, m_Enemy->GetPos().x, m_Enemy->GetPos().y, 200))
	//{
	//	//m_Enemy라는 오브젝트를 생성해서 캐릭터의 x, y값, 적의 x, y값을 넘겨주고 충돌체크 사이즈를 주고
	//	//충돌체크 메서드의 반환값이 true 면 충돌이 된것 이기 때문에 충돌이 된다면 밑에 효과음이 출력될것이다.
	//
	//	//효과음 출력
	//	SoundManager::get_Instance()->Play_Ef("Resource/ex.wav");
	//}
	//m_Char2->Update(_fETime);
}

// 그리기
void S_Game::Render()
{
	// 캐릭터 그리기
	m_Char2->Render();
}