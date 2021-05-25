#include "JapaneseDoll.h"

JapaneseDoll::JapaneseDoll()
{
	textureManager = TextureManager::GetInstance();
	m_Index = explosion1;
	m_PosX = 600;
	m_PosY = 575;
}

JapaneseDoll::~JapaneseDoll()
{
}

void JapaneseDoll::Exec(bool itemGet)
{
	if (itemGet == true)
	{
		m_IsGet = true;
	}
}

void JapaneseDoll::ActExec(int m_IsDecision)
{
	if (m_IsDecision==false)
	{
		m_IsExplosion = true;
	}
	if (m_IsExplosion == true)
	{
		Explosion();
	}
}

void JapaneseDoll::Draw(int texture, int item, int itemframe,int clearBlack,bool haveDoll)
{
	if (m_IsGet == true)
	{
		DrawGraph(0,0, clearBlack, TRUE);
		DrawRotaGraph2(PopItemPosX, PopItemPosY, ItemFrameX / 2, ItemFrameY / 2, 1.0, 0, itemframe, TRUE, TRUE);
		DrawRotaGraph2(PopItemPosX, PopItemPosY, Get_JapaneseDollTextureX / 2, Get_JapaneseDollTextureY / 2, 1.0, 0, item, TRUE, TRUE);
	}
	else if (haveDoll==false)
	{
		DrawRotaGraph2(m_PosX, m_PosY, JapaneseDollTextureX / 2, JapaneseDollTextureY / 2, 1.0, 0, texture, TRUE, TRUE);
	}
	else
	{

	}
}

void JapaneseDoll::ItemBar(int texture, int itemframe, bool haveDoll)
{
	DrawRotaGraph2(65, 65, ItemFrameX / 2, ItemFrameY / 2, 0.2, 0, itemframe, TRUE, TRUE);
	if (haveDoll == true)
	{
		DrawRotaGraph2(65, 65, JapaneseDollTextureX / 2, JapaneseDollTextureY / 2, 1.0, 0, texture, TRUE, TRUE);
	}
}

void JapaneseDoll::Explosion()
{
	if (--m_ActStop <= 0)
	{
		m_Index++;
		m_ActStop = m_ActSpeed;
		m_Index %= m_MotionMax;
		if (m_Index == 0)
		{
			if (m_Index == explosion11)
			{
				m_IsExplosion = false;
			}
			m_Index = explosion1;
			
		}
	}
}
