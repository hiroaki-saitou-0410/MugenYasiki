#include"TunagiOger.h"

TunagiOger::TunagiOger()
{
	m_QuakePosY = 3;
	m_TextureX = 491;
	m_TextureY = 673;
	m_PosY = TextBar_Y-m_TextureY;
}

TunagiOger::~TunagiOger()
{
}

void TunagiOger::Exec()
{
	if (IsExec==true)
	{
		Init();
		//Animation();
		if (--QuakeStop <= 0)
		{
			QuakeStop = QuakeSpeed;
			if (m_DisplyPosY < 0)
			{
				m_DisplyPosY += m_QuakePosY;
			}
			if (m_DisplyPosY > 0)
			{
				m_DisplyPosY -= m_QuakePosY;
			}
			m_DisplyPosY *= -1;
		}
		
		if (m_DisplyPosY == 0)
		{
			m_QuakePosY = 3;
			PlayerKill = true;
			IsExec = false;
			IsInit = false;
		}
	}
}

void TunagiOger::Draw(int texture,int x_)
{
	if (IsExec==true)
	{
		DrawExtendGraph(x_, m_PosY+ m_DisplyPosY, x_+ m_TextureX, m_PosY + m_TextureY+ m_DisplyPosY, texture, TRUE);
	}
}

void TunagiOger::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
		QuakeSpeed = 5;
		QuakeStop = QuakeSpeed;
		m_DisplyPosY = 60;
		//m_Index = explosion1;
		//m_MotionMax=
		//m_ActSpeed=
	}
}

void TunagiOger::Animation()
{
	if (--m_ActStop <= 0)
	{
		m_Index++;
		m_ActStop = m_ActSpeed;
		m_Index %= m_MotionMax;
		if (m_Index == 0)
		{
			//m_Index = explosion1;
		}
	}
}
