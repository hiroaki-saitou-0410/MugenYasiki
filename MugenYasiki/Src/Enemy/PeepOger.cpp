#include"PeepOger.h"

PeepOger::PeepOger()
{
	m_PosY = 269;
	m_TextureX = 198;
	m_TextureY = 278;
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
		DrawExtendGraph(x_, m_PosY, x_ + m_TextureX, m_PosY + m_TextureY, texture, TRUE);
	}
}

void PeepOger::Init()
{
	if (IsInit == false)
	{
		IsInit = true;
	}
}
