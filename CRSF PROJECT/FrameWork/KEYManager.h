#pragma once
#include "singleton.h"

#include <bitset>
#include <Windows.h>

#define KEYMAX 256

using namespace std;

class KEYManager : public singleton<KEYManager>
{
private:
	bitset<KEYMAX> keyUP;
	bitset<KEYMAX> keyDown;

public:
	void InputInit();
	void InputRelease();

	bool KeyDown(int key);	// Ű�� �ѹ��� ������ ��
	bool KeyUp(int key);		// Ű�� ������ ���� ��
	bool StayKeyDown(int key);	// Ű�� ������ ���� ��
	bool ToggleKey(int key);		// Ű�� ��Ÿ�� ��

	// Getter, Setter
	bitset<KEYMAX>	GetKeyUp() { return keyUP; }
	bitset<KEYMAX>	GetKeyDown() { return keyDown; }

	void SetKeyUp(int key, bool state) { keyUP.set(key, state); }
	void SetKeyDown(int key, bool state) { keyDown.set(key, state); }

};

