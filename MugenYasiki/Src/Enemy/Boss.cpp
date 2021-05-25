#include "Boss.h"

Boss::Boss()
{
	m_PosY = 120;
	m_TextureX = 408;
	m_TextureY = 534;
}

Boss::~Boss()
{
}

void Boss::Exec()
{
	if (m_IsExec == true)
	{
		Init();
		PlayerKill = true;
	}
}

void Boss::Draw(int texture,int x_)
{
	if (m_IsExec == true)
	{
		DrawExtendGraph(x_, m_PosY, x_ + m_TextureX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void Boss::AfterAction(int texture)
{
	if (AfterAct == true)
	{
		if (m_ActTime <= m_DrawTime)
		{
			DrawExtendGraph(0, 0,WindowWidth,WindowHeight, texture, TRUE);
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

void Boss::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
		m_DrawTime = 45;
		m_ActTime = 0;
	}
}
