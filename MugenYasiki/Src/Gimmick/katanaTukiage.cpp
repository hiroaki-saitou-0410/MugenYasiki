#include"katanaTukiage.h"

KatanaTukiage::KatanaTukiage()
{
	m_PosY = TextBar_Y+m_TextureY;
	m_TextureX = 25;
	m_TextureY = 225;
	m_MaxPosY = TextBar_Y - m_TextureY + 90;
	m_PosX = TukiagePosX;
}

KatanaTukiage::~KatanaTukiage()
{
}

void KatanaTukiage::Exec(int x_ )
{
	//while (m_PosX <= LeftLimitPosX + 400)		ここはランダムで座標を出すためのコードです
	//{
	//	m_PosX = GetRand(RightLimitPosX - 300);
	//}
	if (m_PosX<= x_+ PlayerTexture_X && m_PosX >= x_ )
	{
		Draw_katana = true;
		IsMove = true;
	}
	if (IsMove == true)
	{
		if (m_MaxPosY <= m_PosY  )
		{
			if (m_PosY <= m_MaxPosY)
			{
				m_PosY = m_MaxPosY;
			}
			else
			{
				m_PosY -= m_UpSpeed;
			}
		}
	}
}

void KatanaTukiage::Draw(int TexMana,float pi)
{
	if (Draw_katana == true)
	{
		DrawRotaGraph2(m_PosX, m_PosY, m_TextureX / 2, m_TextureY, 1.0, pi, TexMana, TRUE);
	}
}

bool KatanaTukiage::Collision(int x_, int y_)
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
