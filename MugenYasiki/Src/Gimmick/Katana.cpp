#include "Katana.h"

Katana::Katana()
{
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
	if (m_PosX + 25 > x_ + 56 &&
		m_PosX < x_ + 168 )
	{
		if (m_PosY + 225 > y_ &&
			m_PosY < y_ + Player_Y)
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