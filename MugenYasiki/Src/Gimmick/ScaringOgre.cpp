#include "ScaringOgre.h"

ScaringOgre::ScaringOgre()
{
	m_AppearPosX = scaring_ogrePosX;
	m_PosX = UpperLeftPosX;
	m_PosY = UpperLeftPosY;
	m_ExtendPosX = LowerRightPosX;
	m_ExtendPosY = LowerRightPosY;
	m_Drawtimer = 0;

	inputManager = InputManager::GetInstance();
}

ScaringOgre::~ScaringOgre()
{
}

void ScaringOgre::Exec()
{
	if (IsExec ==true)
	{
		if (IsDraw == false)
		{
			IsDraw = true;
		}
	}
	else
	{
		IsDraw = false;
	}
}

void ScaringOgre::Draw(int texture)
{
	DrawFormatString(200, 240, GetColor(255, 255, 255), "%d", m_Drawtimer);
	if (IsDraw ==true)
	{
		DrawExtendGraph(m_PosX, m_PosY, m_ExtendPosX + m_PosX, m_ExtendPosY + m_PosY -200 , texture, TRUE);
	}
}

bool ScaringOgre::Collision(int x_, int y_)
{
	return false;
}
