#include "Player.h"

Player::Player()
{
	
	inputManager = InputManager::GetInstance();
	m_Posx = 100;
	m_IsRight = true;
}

Player::~Player()
{
}

void Player::Exec()
{
	//if (inputManager->IsKeyHeld(KEY_INPUT_A))//¶
	//{
	//	m_IsRight = false;
	//	m_Posx -= m_Speed;
	//}
	//if (inputManager->IsKeyHeld(KEY_INPUT_D))//‰E
	//{
	//	m_IsRight = true;
	//	m_Posx += m_Speed;
	//}
}

void Player::Draw()
{
	
}

