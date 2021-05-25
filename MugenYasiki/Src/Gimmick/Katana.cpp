#include "Katana.h"

Katana::Katana()
{
	m_MaxPosY = 562;
}

Katana::~Katana()
{
}

void Katana::Exec(int x_)
{
	//—Ž‰º
	if (m_IsExec == true)
	{
		Init(x_);
		fall = true;
		Draw_katana = true;
	}
	if (fall == true)
	{
		if (m_PosY <= 620)//845-225	225-(58(283-225))=167
		{
			m_PosY += m_fall_speed;
		}
		else
		{
			fall = false;
		}
	}
}

void Katana::Draw(int texture)
{
	if (Draw_katana == true)
	{
		DrawRectGraph(m_PosX, m_PosY, 0, 0, 22, int(787 - m_PosY), texture, TRUE, FALSE);
	}
}

void Katana::Init(int x_)
{
	if (IsInit == false)
	{
		if (m_IsExec==true)
		{
			IsInit = true;
			InitValue = x_ + PlayerTexture_X / 2;
			m_PosX = InitValue;
		}
	}
}

bool Katana::Collision(int x_,int y_)
{	
	//“‚Ì“–‚½‚è”»’è
	if (m_PosX + KatanaTextureX > x_ + 56 &&
		m_PosX < x_ + 168 )
	{
		if (m_PosY + KatanaTextureY > y_ &&
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

void Katana::FullReset()
{
	after_acti = false;
	Draw_katana = false;
	fall = false;
	m_IsExec = false;
	IsInit = false;
	m_PosY = 0;
}
