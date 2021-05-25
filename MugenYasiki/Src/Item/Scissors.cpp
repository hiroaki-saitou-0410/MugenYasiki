#include "Scissors.h"

Scissors::Scissors()
{
	m_PosX = 1080;
	m_PosY = 680;
}

Scissors::~Scissors()
{
}

void Scissors::Exec(bool itemGet)
{
	if (itemGet == true)
	{
		IsGet = true;
	}
}

void Scissors::ActExec()
{	
	if (m_Time < m_Maxtime)
	{	
		m_Time++;
		IsStopCollision = true;
	}
	else
	{
		m_Time = 0;
		IsStopCollision = false;
	}
}

void Scissors::Draw(int texture, int item,int itemframe,int clearBlack, bool haveScissors)
{
	if (IsGet == true)
	{
		DrawGraph(0, 0, clearBlack, TRUE);
		DrawRotaGraph2(PopItemPosX, PopItemPosY, ItemFrameX / 2, ItemFrameY / 2, 1.0, 0, itemframe, TRUE, TRUE);
		DrawRotaGraph2(PopItemPosX, PopItemPosY, Get_ScissorsTextureX / 2, Get_ScissorsTextureY / 2, 1.0,0, item, TRUE, TRUE);
	}
	else if (haveScissors==false)
	{
		DrawRotaGraph2(m_PosX, m_PosY, ScissorsTextureX / 2, ScissorsTextureY / 2, 1.0, 0, texture, TRUE, TRUE);
	}
	else
	{

	}	
}

void Scissors::ItemBar(int texture, int itemframe, bool haveScissors)
{
	DrawRotaGraph2(166, 65, ItemFrameX / 2, ItemFrameY / 2, 0.2, 0, itemframe, TRUE, TRUE);
	if (haveScissors == true)
	{
		DrawRotaGraph2(166,65, JapaneseDollTextureX / 2, JapaneseDollTextureX / 2, 1.0, 0, texture, TRUE, TRUE);
	}
}
