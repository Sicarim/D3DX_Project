#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstdlib>
#include <map>
#include <assert.h>
#include <functional>
#include <list>
#include <queue>
#include <d3d9.h>
#include <d3dx9.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map>

using namespace std;
using namespace stdext;

#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p ); ( p ) = NULL; } }
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

//���� ���¸� ����Ų��
enum CURRENT_STATE
{
	STAND,
	LEFT,
	LEFT_KEYUP,
	RIGHT_KEYUP,
	RIGHT,
	UP,
	DOWN,
	ATTACK
};