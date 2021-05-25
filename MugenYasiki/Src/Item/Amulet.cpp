#include"Amulet.h"

Amulet::Amulet()
{
	m_PosX =1500;
	m_PosY =700;
}

Amulet::~Amulet()
{
}

void Amulet::Exec(bool itemGet)
{
	if (itemGet == true)
	{
		IsGet = true;
	}
}

void Amulet::ActExec()
{
}

void Amulet::Draw(int texture, int item, int itemframe, int clearBlack, bool haveAmulet)
{
	if (IsGet == true)
	{
		DrawGraph(0, 0, clearBlack, TRUE);
		DrawRotaGraph2(PopItemPosX, PopItemPosY, ItemFrameX / 2, ItemFrameY / 2, 1.0, 0, itemframe, TRUE, TRUE);
		DrawRotaGraph2(PopItemPosX, PopItemPosY, Get_AmuletTextureX / 2, Get_AmuletTextureY / 2, 1.0, 0, item, TRUE, TRUE);
	}
	else if (haveAmulet == false)
	{
		DrawRotaGraph2(m_PosX, m_PosY, AmuletTextureX / 2, AmuletTextureY / 2, 1.0, 0, texture, TRUE, TRUE);
	}
	else
	{

	}
}

void Amulet::ItemBar(int texture, int itemframe, bool haveAmulet)
{
	DrawRotaGraph2(65, 65, ItemFrameX / 2, ItemFrameY / 2, 0.2, 0, itemframe, TRUE, TRUE);
	if (haveAmulet == true)
	{
		DrawRotaGraph2(65, 65, JapaneseDollTextureX / 2, JapaneseDollTextureY / 2, 1.0, 0, texture, TRUE, TRUE);
	}
}
