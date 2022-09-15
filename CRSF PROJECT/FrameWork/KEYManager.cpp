#include "KEYManager.h"


void KEYManager::InputInit()
{
	for (int i = 0; i < KEYMAX; i++)
	{

		SetKeyDown(i, false);

		SetKeyUp(i, true);
	}
}

void KEYManager::InputRelease()
{
}

bool KEYManager::KeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->GetKeyDown()[key])
		{
			this->SetKeyDown(key, true);
			return true;
		}
	}
	else
	{
		this->SetKeyDown(key, false);
	}

	return false;
}

bool KEYManager::KeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		this->SetKeyUp(key, false);
	}
	else
	{
		if (!this->GetKeyUp()[key])
		{
			this->SetKeyUp(key, true);
			return true;
		}
	}
	return false;
}

bool KEYManager::StayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)	return true;

	return false;
}

bool KEYManager::ToggleKey(int key)
{
	if (GetAsyncKeyState(key) & 0x0001) return true;

	return false;
}
