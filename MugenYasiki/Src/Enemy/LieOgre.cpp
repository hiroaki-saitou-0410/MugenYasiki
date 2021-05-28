#include "LieOgre.h"

LieOgre::LieOgre()
{
	m_TextureX = 758;
	m_TextureY = 523;
	m_PosY = TextBar_Y-m_TextureY;
}

LieOgre::~LieOgre()
{
}

void LieOgre::Exec()
{
	if (m_IsExec == true)
	{
		Init();
		PlayerKill = true;
	}
}

void LieOgre::Draw(int texture,int x_)
{
	if (m_IsExec == true)
	{
		DrawExtendGraph(x_, m_PosY, x_ + m_TextureX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void LieOgre::AfterAction(int texture)
{
	if (AfterAct == true)
	{
		if (m_ActTime <= m_DrawTime)
		{
			DrawGraph(0, 0, texture, TRUE);
			m_ActTime++;
		}
		else
		{
			AfterAct = false;
			m_IsExec = false;
			IsInit = false;
		}

	}
}

void LieOgre::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
		m_DrawTime = 30;
		m_ActTime = 0;
	}
}
