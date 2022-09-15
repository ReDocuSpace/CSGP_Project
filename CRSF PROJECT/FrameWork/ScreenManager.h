#pragma once

#include "singleton.h"
#include <Windows.h>

class ScreenManager : public singleton<ScreenManager>
{

private:
	int g_nScreenIndex;
	HANDLE g_hScreen[2];
	// 해상도 80 X 50 [ 실제 적용 해상도 40 X 25 ]
	int width;
	int height;

public:
	int ScreenWidth() { return width; }
	int ScreenHeight() { return height; }

	// main에서 출력하는 단계 및 더블버퍼링 적용
	void ScreenInit();
	void ScreenInit(int width, int height);
	void ScreenClear();
	void ScreenFliping();
	void ScreenRelease();

	bool ScreenCollider(int x, int y, bool sp = false /*Special Characters */);

	// 색깔을 조정
	void OnDrawText(int x, int y, const char* msg);
	void OnDrawSetColor(unsigned short color);
	void OnDrawTextColor(int x, int y, const char* msg, unsigned short color);

};

