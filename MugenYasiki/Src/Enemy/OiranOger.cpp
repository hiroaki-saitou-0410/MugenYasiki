#include"OiranOger.h"

OiranOger::OiranOger()
{
	m_TextureX = 408;
	m_TextureY = 578;
	m_PosY = TextBar_Y-m_TextureY;
}

OiranOger::~OiranOger()
{
}

void OiranOger::Exec()
{
	if (m_IsExec == true)
	{
		Init();
		PlayerKill = true;
	}
}

void OiranOger::Draw(int texture,int x_)
{
	if (m_IsExec == true)
	{
		DrawExtendGraph(x_, m_PosY, x_ + m_TextureX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void OiranOger::AfterAction(int texture)
{
	if (AfterAct == true)
	{
		if (m_ActTime <= m_DrawTime)
		{
			DrawGraph(0,0, texture, TRUE);
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

void OiranOger::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
		m_DrawTime = 120;
		m_ActTime = 0;
	}
}
