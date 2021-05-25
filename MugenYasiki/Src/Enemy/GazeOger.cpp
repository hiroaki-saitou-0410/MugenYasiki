#include "GazeOger.h"

GazeOger::GazeOger()
{
	m_PosY = 330;
	m_TextureX = 198;
	m_TextureY = 278;
}

GazeOger::~GazeOger()
{
}

void GazeOger::Exec()
{
	if (m_IsExec==true)
	{
		Init();
		PlayerKill = true;
	}
}

void GazeOger::Draw(int texture,int x_)
{
	if (m_IsExec==true)
	{
		DrawExtendGraph(x_, m_PosY, x_ + m_TextureX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void GazeOger::AfterAction(int texture)
{
	if (AfterAct == true )
	{
		if (m_ActTime <= m_DrawTime)
		{
			DrawExtendGraph(EyePosX,EyePosY, EyePosX + EyeTextureX, EyePosY+ EyeTextureY, texture, TRUE);
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

void GazeOger::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
		m_DrawTime = 30;
		m_ActTime = 0;
	}
}