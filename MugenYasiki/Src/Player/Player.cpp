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

