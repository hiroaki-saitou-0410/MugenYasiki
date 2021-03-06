#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include"../Singleton.h"
#include"DxLib.h"
#include"../Definition.h"

class InputManager :public Singleton<InputManager>
{
public:
	void UpdateKeyStatus();

	//押された瞬間
	bool IsKeyPushed(int key);

	//押している
	bool IsKeyHeld(int key);

	//離した瞬間
	bool IsKeyRelesed(int key);
private:

};

#endif // !INPUT_MANAGER_H

