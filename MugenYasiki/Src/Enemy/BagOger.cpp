#include"BagOger.h"

BagOger::BagOger()
{
	m_PosX = WindowWidth;
	m_PosY = 390;
	m_TextureX = 432;
	m_TextureY = 510;
}

BagOger::~BagOger()
{
}

void BagOger::Exec(int x_)
{
	if (IsExec == true)
	{
		if (collision(x_) == true)
		{
			Init();
			if (--QuakeStop <= 0)
			{
				QuakeStop = QuakeSpeed;
				if (m_DisplyPosX > 0)
				{
					m_DisplyPosX -= m_QuakePosX;
				}
				if (m_DisplyPosX < 0)
				{
					m_DisplyPosX += m_QuakePosX;
				}
				m_DisplyPosX *= -1;
			}

			if (m_DisplyPosX == 0)
			{
				PlayerKill = true;
				IsInit = false;
				IsExec = false;
			}
			
		}
		else
		{
			m_PosX -= m_Speed;
		}
	}
}

void BagOger::Draw(int texture)
{
	if (IsExec == true)
	{
		DrawExtendGraph(m_PosX+ m_DisplyPosX, m_PosY, m_PosX + m_TextureX + m_DisplyPosX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void BagOger::Init()
{
	if (IsInit==false)
	{
		IsInit = true;
		m_QuakePosX = 4;
		QuakeSpeed = 5;
		QuakeStop = QuakeSpeed;
		m_DisplyPosX = -60;
	}
}

bool BagOger::collision(int x_)
{
	if (m_PosX + m_TextureX > x_ &&
		m_PosX < x_ + PlayerTexture_X)
	{
		return true;
	}
	return false;
}
