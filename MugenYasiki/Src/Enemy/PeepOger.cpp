#include"PeepOger.h"

PeepOger::PeepOger()
{
	m_TextureX = 198;
	m_TextureY = 278;
	m_PosY = TextBar_Y-m_TextureY;
}

PeepOger::~PeepOger()
{
}

void PeepOger::Exec()
{
	if (IsExec == true)
	{
		Init();

	}
}

void PeepOger::Draw(int texture,int x_)
{
	if (IsExec == true)
	{
		DrawExtendGraph(x_ + ShiftPosX, m_PosY, x_ + m_TextureX + ShiftPosX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void PeepOger::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
	}
}
