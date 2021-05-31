#include "Player.h"

Player::Player()
{
	inputManager = InputManager::GetInstance();
	m_PosX = 100;
	m_IsRight = true;
	m_IsStop = false;
	m_HP = 3;
	m_Gravity = 1;
	m_Vector = 10;
	m_PosY = Player_Y;
}

Player::~Player()
{
}

void Player::Exec()
{
	if (inputManager->IsKeyHeld(KEY_INPUT_LEFT) && m_PosX > LeftLimitPosX)//左
	{
		m_IsStop = false;
		m_IsRight = false;
		m_PosX -= m_Speed;
	}
	else if (inputManager->IsKeyHeld(KEY_INPUT_RIGHT) && m_PosX < RightLimitPosX)//右
	{
		m_IsStop = false;
		m_IsRight = true;
		m_PosX += m_Speed;
	}
	else
	{
		m_IsStop = true;
		m_GetItem = false;
	}

	if (inputManager->IsKeyHeld(KEY_INPUT_UP) && m_IsTouchingRoom == true)
	{
		m_IsTouchingRoom = false;
	}

	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))//決定
	{
		m_IsDecision = true;
	}
	else
	{
		m_IsDecision = false;
	}

	if (inputManager->IsKeyPushed(KEY_INPUT_DOWN))//アイテム取得
	{
		m_GetItem = true;
	}
	else
	{
		m_GetItem = false;
	}

	if (inputManager->IsKeyPushed(KEY_INPUT_SPACE))
	{
		m_IsAttack = true;
	}

	if (m_IsTouchingRoom==false)
	{
		Jump();
	}
}

bool Player::Collision(int x_, int y_)
{
	if ((x_ < m_PosX + PlayerTexture_X || y_ < m_PosY) &&
		(x_ < m_PosX + PlayerTexture_X || y_ < m_PosY + PlayerTexture_Y) &&
		(x_ > m_PosX || y_  < m_PosY + PlayerTexture_Y) &&
		(x_ > m_PosX || y_ < m_PosY))
	{

		return true; //(x_ + 112) > m_PosX&& x_ < m_PosX + 300)
	}
	return false;
}

void Player::Jump()
{
	if (m_IsTouchingRoom == false)
	{
		m_Gravity += 0.3;
		int jump = m_Vector - m_Gravity;
		m_PosY -= jump;
		if (m_PosY >= Player_Y)
		{
			m_IsTouchingRoom = true;
			m_PosY = Player_Y;
			m_Gravity = 0;
		}
	}	
}

void Player::Sound()
{
	if (m_IsStop == false)
	{
		soundManager->PlaySceneSound(soundManager->GetSoundDate(tiyo_w), DX_PLAYTYPE_LOOP, TRUE, 255);
	}
	else
	{
		if (CheckSoundMem(soundManager->GetSoundDate(titleSound)) == TRUE)
		{
			StopSoundMem(soundManager->GetSoundDate(titleSound));
		}
	}
}

