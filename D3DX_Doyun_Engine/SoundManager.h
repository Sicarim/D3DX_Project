#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"

using namespace std;

namespace DoEngine
{
	class SoundManager : public Singleton<SoundManager>
	{
	public:
		SoundManager();
		~SoundManager();

	public:
		// 배경음을 출력하는 메서드
		void Play_Bg(string path);

		// 효과음을 출력하는 메서드
		void Play_Ef(string path);
	};


}

