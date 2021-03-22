#include "Player.h"

Player::Player()
{
	
	inputManager = InputManager::GetInstance();
	m_Posx = 100;
	m_IsRight = true;
	m_IsStop = false;
}

Player::~Player()
{
}

void Player::Exec()
{
	if (inputManager->IsKeyHeld(KEY_INPUT_A))//¶
	{
		m_IsStop = false;
		m_IsRight = false;
		m_Posx -= m_Speed;
	}
	else if (inputManager->IsKeyHeld(KEY_INPUT_D))//‰E
	{
		m_IsStop = false;
		m_IsRight = true;
		m_Posx += m_Speed;
	}
	else
	{
		m_IsStop = true;
	}
}

void Player::Draw()
{
	
}

bool Player::Collision(int x_, int y_)
{
	if ((x_ < m_Posx + PlayerTexture_X || y_ < Player_Y) &&
		(x_ < m_Posx + PlayerTexture_X || y_ + 479 < Player_Y + PlayerTexture_Y) &&
		(x_ + 350 > m_Posx || y_ + 479 < Player_Y + PlayerTexture_Y) &&
		(x_ + 350 > m_Posx || y_ < Player_Y))
	{

		return true;
	}
	return false;
}
