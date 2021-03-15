#include "Player.h"
#include "UIManager.h"

//생성자
Player::Player()
{

}

//소멸자
Player::~Player()
{

}

void Player::Init(string _Tag, float _x, float _y, bool _direction)
{
	//캐릭터 초기 정보 삽입
	Tag			= _Tag;
	m_Pos.x		= _x;
	m_Pos.y		= _y;
	Direction	= _direction;
	Degree		= 0;

	//플레이어 체력
	Player_HP = MAX_HP;

	//플레이어 체력

	//플레이어의 캐릭터 생성
	Player_Charecter = GameManager::get_Instance()->get_PlayerSelect();
	//캐릭터 정보 초기화
	Player_Charecter->Init(Tag, m_Pos.x, m_Pos.y, Direction);
}

bool Player::Input(int _state)
{
	// 벡터를 선언하고 정규화이후 일정한 속도로 오브젝트의 각도의 방향으로 이동
	D3DXVECTOR2 vec = D3DXVECTOR2(cos(D3DXToRadian(Degree)), sin(D3DXToRadian(Degree)));

	//시작시, 가장 먼저 캐릭터 탄생 모션 실행
	if (!UIManager::get_Instance()->get_IsCharBirth(Tag))
	{
		Player_Charecter->Input(STATE_BIRTH);
	}
	else
	{
		//오른쪽
		if (_state == RIGHT)
		{
			Direction = true;
			D3DXVec2Normalize(&vec, &vec);
			m_Pos += vec * 6;
		}
		//왼쪽
		else if (_state == LEFT)
		{
			Direction = false;
			D3DXVec2Normalize(&vec, &vec);
			m_Pos -= vec * 6;
		}

		//현재 상태를 Object에 입력
		Player_Charecter->Input(_state);
	}

	return false;
}

void Player::Update(float _fETime)
{
	Player_Charecter->Update(_fETime, m_Pos.x, m_Pos.y, Direction);
	//죽음 상태 확인
	isDie = GameManager::get_Instance()->get_IsPlayerDie();

	//캐릭터의 HP가 0이라면
	if (isDie)
	{
		Player_Charecter->Input(BICE_DIE);
	}
}

void Player::Render()
{
	Player_Charecter->Render();
}

void Player::Release()
{

}

DoEngine::Object* Player::ReturnObject()
{
	return Player_Charecter;
}