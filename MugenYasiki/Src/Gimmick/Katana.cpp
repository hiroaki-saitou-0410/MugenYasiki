#include "Katana.h"

Katana::Katana()
{
	m_PosX = 800;
	m_TextureX = 25;
	m_TextureY = 225;
}

Katana::~Katana()
{
}

void Katana::Exec(int x_,int y_)
{
	//—Ž‰º
	if ((m_PosX - 40) <= x_ + 112)//GimmickPosX
	{
		fall = true;
		Draw_katana = true;
	}
	if(fall==true)
	{
		if (m_PosY <= 620)//845-225	225-(58(283-225))=167
		{
			m_PosY += m_fall_speed;
			if (m_PosY >= 562)
			{
				after_acti = true;
			}
		}
		else
		{
			fall = false;
		}
	}
}

bool Katana::Collision(int x_,int y_)
{	
	//“‚Ì“–‚½‚è”»’è
	if (m_PosX + m_TextureX > x_ + 56 &&
		m_PosX < x_ + 168 )
	{
		if (m_PosY + m_TextureY > y_ &&
			m_PosY < y_ + PlayerTexture_Y)
		{
			return true;
		}
	}	
	return false;
	
	//if ((x_ + PlayerTexture_X) > m_PosX + 9 && x_ < m_PosX + 13 && after_acti == true)
	//{
	//	if ((y_ + PlayerTexture_Y > m_PosY && y_ < m_PosY + 168))
	//	{
	//		return true;
	//	}
	//}
	//return false;
}