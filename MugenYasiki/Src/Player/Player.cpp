#include "Player.h"

Player::Player()
{
	
	inputManager = InputManager::GetInstance();
	m_Posx = 100;
	m_IsRight = true;
	m_IsStop = false;
	m_HP = 3;
}

Player::~Player()
{
}

void Player::Exec()
{
	if (inputManager->IsKeyHeld(KEY_INPUT_LEFT) && m_Posx > LeftLimitPosX)//左
	{
		m_IsStop = false;
		m_IsRight = false;
		m_Posx -= m_Speed;
	}
	else if (inputManager->IsKeyHeld(KEY_INPUT_RIGHT) && m_Posx < RightLimitPosX)//右
	{
		m_IsStop = false;
		m_IsRight = true;
		m_Posx += m_Speed;
	}
	else
	{
		m_IsStop = true;
		m_GetItem = false;
	}

	if (inputManager->IsKeyPushed(KEY_INPUT_DOWN))//アイテム取得
	{
		m_GetItem = true;
	}
	else
	{
		m_GetItem = false;
	}
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{

	}
	if (inputManager->IsKeyPushed(KEY_INPUT_SPACE))
	{
		m_IsAttack = true;
	}
}

bool Player::Collision(int x_, int y_)
{
	if ((x_ < m_Posx + PlayerTexture_X || y_ < Player_Y) &&
		(x_ < m_Posx + PlayerTexture_X || y_ + 479 < Player_Y + PlayerTexture_Y) &&
		(x_ + 112 > m_Posx || y_ + 479 < Player_Y + PlayerTexture_Y) &&
		(x_ + 112 > m_Posx || y_ < Player_Y))
	{

		return true; //(x_ + 112) > m_PosX&& x_ < m_PosX + 300)
	}
	return false;
}
