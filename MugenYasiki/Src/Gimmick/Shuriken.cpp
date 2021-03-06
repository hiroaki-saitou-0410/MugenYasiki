#include"Shuriken.h"

Shuriken::Shuriken()
{
	//m_PosX = WindowWidth;
	m_PosX = ShurikenPosX;
	m_PosY = TextBar_Y - ShurikenTextureX *2;
	m_DrawTime = 0;
}

Shuriken::~Shuriken()
{
}

void Shuriken::Exec(int x_,int y_)
{
	if (x_ == Shuriken_MoveStart)
	{
		IsMove = true;
		IsDraw = true;
	}
	if (IsMove == true && IsDraw==true)
	{
		m_PosX -= m_Speed;
	}

	if (m_PosX <= 0)
	{
		m_DrawTime++;
		IsMove = false;
	}
	if (IsDraw==true && m_DrawTime==60)
	{
		m_DrawTime = 0;
		IsDraw = false;
		m_PosX = ShurikenPosX;
	}	
}

void Shuriken::Draw(int texture,float pi)
{
	if (IsDraw == true)
	{
		DrawRotaGraph2(m_PosX, m_PosY, ShurikenTextureX / 2, ShurikenTextureY / 2, 1.0, pi, texture, true);
	}
}

bool Shuriken::Collision(int x_, int y_)
{
	if (m_PosX + ShurikenTextureX > x_ + 56 &&
		m_PosX < x_ + 168)
	{
		if (m_PosY + ShurikenTextureY > y_ &&
			m_PosY < y_ + PlayerTexture_Y)
		{
			return true;
		}
	}
	return false;
}
