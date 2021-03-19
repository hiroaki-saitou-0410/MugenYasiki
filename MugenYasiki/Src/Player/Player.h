#ifndef PLAYER_H
#define PLAYER_H

#include"DxLib.h"
#include"../Manager/InputManager.h"
#include"../Scene/InGameScene.h"

class Player
{
public:
	Player();
	~Player();

	void Exec();
	void Draw();

	int SetPosX() {return m_Posx; }
	bool IsStop() { return m_IsStop; }
private:
	InputManager* inputManager = nullptr;

	int m_Posx;
	const int m_Speed = 2;

	bool m_IsRight;
	bool m_IsStop;
};

#endif // !PLAYER_H

