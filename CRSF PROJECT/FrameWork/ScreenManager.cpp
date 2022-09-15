#include "ScreenManager.h"
#include "../CSGPFrameWork.h"

void ScreenManager::ScreenInit()
{
	g_nScreenIndex = 0;

	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT * 2;
	// 커서 정보
	CONSOLE_CURSOR_INFO cursorInfo;

	// 화면 버퍼를 생성
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

	// 커서 제어
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cursorInfo);
	SetConsoleCursorInfo(g_hScreen[1], &cursorInfo);
}

void ScreenManager::ScreenInit(int width, int height)
{
	this->width = width;
	this->height = height;

	CONSOLE_CURSOR_INFO cursorInfo;

	// 화면 버퍼를 생성
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

	// 커서 제어
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cursorInfo);
	SetConsoleCursorInfo(g_hScreen[1], &cursorInfo);
}

void ScreenManager::ScreenClear()
{
	COORD cor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', width * height, cor, &dw);

}

void ScreenManager::ScreenFliping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void ScreenManager::ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

// 
bool ScreenManager::ScreenCollider(int x, int y, bool sp)
{
	if (x > 0 && y > 0 && x < SCREEN_WIDTH/(sp * 2) - 1 && y < SCREEN_HEIGHT - 1)
	{
		return false;
	}
	return true;
}

void ScreenManager::OnDrawText(int x, int y, const char* msg)
{
	DWORD dw;
	COORD cor = { (short)x,(short)y };

	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], cor);

	WriteFile(g_hScreen[g_nScreenIndex], msg, (DWORD)strlen(msg), &dw, nullptr);
}

void ScreenManager::OnDrawSetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void ScreenManager::OnDrawTextColor(int x, int y, const char* msg, unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);

	DWORD dw;
	COORD cor = { (short)x,(short)y };

	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], cor);
	WriteFile(g_hScreen[g_nScreenIndex], msg, (DWORD)strlen(msg), &dw, nullptr);

	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], 0);
}