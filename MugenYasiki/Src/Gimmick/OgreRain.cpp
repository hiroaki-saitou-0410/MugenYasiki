#include "OgreRain.h"

OgreRain::OgreRain()
{
	m_Appearance = 1000;
}

OgreRain::~OgreRain()
{
}

void OgreRain::Exec()
{
	if (m_IsExec == true)
	{
		Init();
		for (int i = 0; i < MaxNumber; i++)
		{
			m_PosY[i] += m_Speed;
			if (m_PosY[i] >= WindowWidth)
			{
				IsInit = false;
			}
		}
	}
}

void OgreRain::Draw(int texture)
{
	if (m_IsExec == true)
	{
		for (int i = 0; i < MaxNumber; i++)
		{
			DrawExtendGraph(m_PosX[i], m_PosY[i], m_PosX[i] + OgreRainTextureX, m_PosY[i] + OgreRainTextureY, texture, TRUE);
		}
	}
}

bool OgreRain::Collision(int x_, int y_)
{
	for (int i = 0; i < MaxNumber; i++)
	{
		if (m_PosX[i]+ OgreRainTextureX > x_ &&
			m_PosX[i] < x_ + PlayerTexture_X)
		{
			if (m_PosY[i]+ OgreRainTextureY > y_ &&
				m_PosY[i] < y_ + PlayerTexture_Y)
			{
				return true;
			}
		}
	}
	return false;
}

void OgreRain::SetPosY(int posy_)
{
	for (int i = 0; i < MaxNumber; i++)
	{
		m_PosY[i] = posy_;
	}
}

void OgreRain::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
		for (int i = 0; i < MaxNumber; i++)
		{
			m_PosX[i] = OgreRainTextureX * i;
			m_PosY[i] = -1000 + GetRand(1000) - 1000;
		}
	}
}
