#include "Arrow.h"

Arrow::Arrow()
{
	m_PosX = ArrowStartPos;
	m_PosY = ArrowHeight;
}

Arrow::~Arrow()
{
}

void Arrow::Exec(int x_)
{
	if (x_ ==500)
	{
		IsDraw = true;
		IsMove = true;
	}
	if (IsMove ==true && m_PosX >= 0)
	{
		m_PosX -= m_Speed;
	}
	else
	{
		m_PosX = ArrowStartPos;
	}

}

void Arrow::Draw(int texture)
{
	if(IsDraw)
	{
		DrawGraph(m_PosX, m_PosY, texture, TRUE);
	}
	
}

bool Arrow::Collision(int x_, int y_)
{
	
		
	if (m_PosX + ArrowTextureX > x_ &&
		m_PosX < x_ + PlayerTexture_X)
	{
		if (m_PosY + ArrowTextureY > y_ &&
			m_PosY < y_ + PlayerTexture_Y)
		{
			return true;
		}
	}
	return false;
}
