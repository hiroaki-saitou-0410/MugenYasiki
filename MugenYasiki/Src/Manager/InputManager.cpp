#include"InputManager.h"

void InputManager::UpdateKeyStatus()
{
	for (int i = 0; i < 256; i++)
	{
		PreviousKeyStatus[i] = KeyStatus[i];
	}

	GetHitKeyStateAll(KeyStatus);
}

bool InputManager::IsKeyPushed(int key)
{
	if(PreviousKeyStatus[key] == 0 && KeyStatus[key]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::IsKeyHeld(int key)
{
	if (PreviousKeyStatus[key] == 1 && KeyStatus[key] == 1)
	{
		return true;
	}
	else
	{
		return false;

	}
}

bool InputManager::IsKeyRelesed(int key)
{
	if (PreviousKeyStatus[key] == 1 && KeyStatus[key] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}