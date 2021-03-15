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
		// ������� ����ϴ� �޼���
		void Play_Bg(string path);

		// ȿ������ ����ϴ� �޼���
		void Play_Ef(string path);
	};


}

