#pragma once
#include "GlobalDefines.h"
#include "Singleton.h"

namespace DoEngine
{
	class AnimationMaker : public Singleton<AnimationMaker>
	{
	private:
		// �ִϸ��̼��� ���� ��
		// ���� �� ����������, üũ�� ���� �ð�
		float						Ani_Time;
		string						Save_Path; //ù ��θ� ����
		vector<LPDIRECT3DTEXTURE9>	m_AniVector;
	public:
		AnimationMaker(); //������
		~AnimationMaker(); //�Ҹ���
	public:
		void Ani_Init(); //Maker �ʱ�ȭ
		vector<LPDIRECT3DTEXTURE9> Ani_Make(std::string path, int Frame); //�ִϸ��̼� �����
		LPDIRECT3DTEXTURE9 get_Texture(string path); //�ִϸ��̼� ����
	};
}