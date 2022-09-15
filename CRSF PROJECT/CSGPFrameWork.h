#pragma once
#include <iostream>
#include <string>
#include <utility>

#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include <Windows.h>

using namespace std;

// 해상도 
// 영어 80 X 25
// 한글 or 특수문자 40X25로 계산
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define FRAME 30

#define SAFE_DELETE(p)			{ if(p)	{ delete p;	p = nullptr; } }
#define SAFE_DELETE_ARRAY(p)	{ if(p)	{ delete[] p;	p = nullptr; } }

#pragma region [ SingletonBase ]

// SingleTon Manager
#include "FrameWork/KEYManager.h"
#include "FrameWork/ScreenManager.h"
#include "FrameWork/TimerManager.h"
#include "FrameWork/ContentManager.h"
#include "FrameWork/ColliderManager.h"

#define INPUT KEYManager::GetSingleton()
#define SCREEN ScreenManager::GetSingleton()
#define TIMER TimerManager::GetSingleton()
#define CONTENTS ContentManager::GetSingleton()
#define COLLIDER ColliderManager::GetSingleton()

#pragma endregion

#pragma region [ Library ]
#include "Library/ColliderLib.h"

#pragma endregion

#pragma region [ Color ]
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};
#pragma endregion