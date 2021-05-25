#include "SwordRain.h"

SwordRain::SwordRain()
{
	m_Appearance = 1400;
	m_CoolTime = 0;
	m_Timer = 0;
}

SwordRain::~SwordRain()
{
}

void SwordRain::Exec()
{
	if (m_IsExec == true)
	{
		Init();
		for (int i = 0; i < MaxNumber; i++)
		{
			m_PosY[i] += m_Speed;
			if (m_PosY[i] >= WindowHeight+150)
			{
				IsInit = false;
			}
		}
	}
}

void SwordRain::Draw(int texture)
{
	if (m_IsExec == true)
	{
		for (int i = 0; i < MaxNumber; i++)
		{
			DrawRectGraph(m_PosX[i], m_PosY[i], 0, 0, 22, int(787 - m_PosY[i]), texture, TRUE, FALSE);
		}
	}
}

bool SwordRain::Collision(int x_, int y_)
{
	for (int i = 0; i < MaxNumber; i++)
	{
		if (m_PosX[i] + KatanaTextureX > x_ + 56 &&
			m_PosX[i] < x_ + 168)
		{
			if (m_PosY[i] + KatanaTextureY > y_ &&
				m_PosY[i] < y_ + PlayerTexture_Y)
			{
				return true;
			}
		}
		
	}
	return false;
}

void SwordRain::SetPosY(int posy_)
{
	for (int i = 0; i < MaxNumber; i++)
	{
		m_PosY[i] = posy_;
	}
}

void SwordRain::Init()
{
	if (IsInit==false)
	{
		IsInit = true;
		for (int i = 0; i < MaxNumber; i++)
		{
			m_PosX[i] = KatanaTextureX * i;

			m_PosY[i] = -1000 + GetRand(750) - 1000;
		}
	}
}