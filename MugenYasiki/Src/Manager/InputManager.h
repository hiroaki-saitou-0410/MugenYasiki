#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include"../Singleton.h"
#include"DxLib.h"
#include"../Definition.h"

class InputManager :public Singleton<InputManager>
{
public:
	void UpdateKeyStatus();

	//�����ꂽ�u��
	bool IsKeyPushed(int key);

	//�����Ă���
	bool IsKeyHeld(int key);

	//�������u��
	bool IsKeyRelesed(int key);
private:
	char KeyStatus[256];
	char PreviousKeyState[256];

};

#endif // !INPUT_MANAGER_H

