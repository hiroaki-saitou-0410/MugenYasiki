#include"katanaTukiage.h"

KatanaTukiage::KatanaTukiage()
{
	m_PosY = WindowHeight + KatanaTextureY;
	m_MaxPosY = TextBar_Y - KatanaTextureY + 90;
}

KatanaTukiage::~KatanaTukiage()
{
}

void KatanaTukiage::Exec(int x_ )
{
	//while (m_PosX <= LeftLimitPosX + 400)		ここはランダムで座標を出すためのコード
	//{
	//	m_PosX = GetRand(RightLimitPosX - 300);
	//}
	if (m_IsExec==true)
	{
		Init(x_);
		Draw_katana = true;
		IsMove = true;
	}
	if (IsMove == true)
	{
		if (m_MaxPosY <= m_PosY  )
		{
			IsPushUp = true;
			m_PosY -= m_UpSpeed;
		}
		if (m_PosY <= m_MaxPosY)
		{
			IsPushUp = false;
			m_PosY = m_MaxPosY;
			IsMove = false;
		}
	}
}

void KatanaTukiage::Draw(int TexMana,float pi)
{
	if (Draw_katana == true)
	{
		DrawRotaGraph2(m_PosX, m_PosY, KatanaTextureX / 2, KatanaTextureY, 1.0, pi, TexMana, TRUE);
	}
}

void KatanaTukiage::Init(int x_)
{
	if (m_IsInit == false)
	{
		if (m_IsExec == true)
		{
			m_IsInit = true;
			InitValue = x_ + PlayerTexture_X / 2 +40;
			m_PosX = InitValue;
		}
	}
}

bool KatanaTukiage::Collision(int x_, int y_)
{
	if (m_PosX + KatanaTextureX > x_ + 56 &&
		m_PosX < x_ + 168)
	{
		if (m_PosY + KatanaTextureY > y_ &&
			m_PosY < y_ + PlayerTexture_Y)
		{
			return true;
		}
	}
	return false;
}
