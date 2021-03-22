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

	int GetPosX() {return m_Posx; }
	void SetPosX(int x) { m_Posx = x; }
	bool IsStop() { return m_IsStop; }
	bool IsRight() { return m_IsRight; }
	bool Collision(int x_, int y_);

private:
	InputManager* inputManager = nullptr;

	int m_Posx;
	const int m_Speed = 2;

	bool m_IsRight = true;
	bool m_IsStop = true;
};

#endif // !PLAYER_H

