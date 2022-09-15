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

	bool KeyDown(int key);	// 키를 한번만 눌렀을 때
	bool KeyUp(int key);		// 키를 눌렀다 뗐을 때
	bool StayKeyDown(int key);	// 키를 누르고 있을 때
	bool ToggleKey(int key);		// 키를 연타할 때

	// Getter, Setter
	bitset<KEYMAX>	GetKeyUp() { return keyUP; }
	bitset<KEYMAX>	GetKeyDown() { return keyDown; }

	void SetKeyUp(int key, bool state) { keyUP.set(key, state); }
	void SetKeyDown(int key, bool state) { keyDown.set(key, state); }

};

