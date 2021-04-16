#include"Shuriken.h"

Shuriken::Shuriken()
{
	m_TextureX = 36;
	m_TextureY = 35;
	m_PosX = WindowWidth;
	m_PosY = TextBar_Y - m_TextureX*2;
}

Shuriken::~Shuriken()
{
}

void Shuriken::Exec(int x_,int y_)
{
	if (x_ == 900)
	{
		IsMove = true;
		Draw = true;
	}
	if (IsMove == true && Draw==true)
	{
		m_PosX -= m_Speed;
	}



	if (m_PosX <= 0)
	{
		IsMove = false;
		Draw = true;
	}
	
}

bool Shuriken::Collision(int x_, int y_)
{
	if (m_PosX + m_TextureX > x_ + 56 &&
		m_PosX < x_ + 168)
	{
		if (m_PosY + m_TextureY > y_ &&
			m_PosY < y_ + PlayerTexture_Y)
		{
			return true;
		}
	}
	return false;
}
