#include "InGameScene.h"

#define PI    3.1415926535897932384626433832795f

float rad90 = (PI / 2);

//この変数は移動の可能性あり
bool after_acti = false, deficit = false, fall = false, dead = false, isfade_in = false, trap_katana = true, have_katana = false;
int katana_x = 800, katana_y = 0, fall_speed = 10, death_count = 0, alpha = 0, fade_speed = 2;;

Player player;

InGameScene::InGameScene()
{
	//各インスタンス
	gamenManager = GameManager::GetInstance();
	inputManager = InputManager::GetInstance();
	textureManager = TextureManager::GetInstance();

	SceneManager::GetInstance()->SetNextScene(InGame);
	textureManager->LoadSceneTexture(InGame);

	m_RightMotionMax = right_Animation7;
	m_ActSpeed=9;
	m_ActStop= m_ActSpeed;
	m_WaitIndex= right_Animation0;
}

InGameScene::~InGameScene()
{
	textureManager->DeleteSceneTexture();
}

void InGameScene::Exec()
{
	player.Exec();

	//刀の落下
	if ((katana_x - 40) <= player.SetPosX() + 112)
	{
		fall = true;
	}
	if (fall)
	{
		if (katana_y <= 620)	//845-225	225-(58(283-225))=167
		{
			katana_y += fall_speed;
			if (katana_y >= 620 - 58)
			{
				after_acti = true;
			}
		}
	}

	//刀の当たり判定
	if (katana_x + 11 > player.SetPosX() + 56 && katana_x + 11 < player.SetPosX() + 168 && !after_acti && !dead)
	{
		if (katana_y + 225 > WindowWidth - 700)
		{
			death_count++;
			dead = true;
		}
	}
	if (katana_x + 11 > player.SetPosX() + 56 && katana_x + 11 < player.SetPosX() + 168 && after_acti && !dead)
	{
		have_katana = true;
		trap_katana = false;
	}

	//フェードアウト
	if (dead)
	{
		alpha += fade_speed;
		if (alpha >= 255)
		{
			isfade_in = true;
			player.GetPosX(100);
			dead = false;
			after_acti = true;
			katana_y = 620 - 58;
		}
	}
	if (isfade_in)
	{
		alpha -= fade_speed;
		if (alpha <= 0)
		{
			isfade_in = false;
		}
	}
}

void InGameScene::Draw()
{
	//BackGround
	DrawGraph(0, 0, textureManager->GetTextureDate(texture1), TRUE);

	//Player
	DrawGraph(player.SetPosX(), WindowWidth - 700, textureManager->GetTextureDate(m_WaitIndex), TRUE);
	
	if (--m_ActStop <= 0 && player.IsStop()== false)
	{
		m_WaitIndex++;
		m_ActStop = m_ActSpeed;
		m_WaitIndex %= m_RightMotionMax;
		if (m_WaitIndex == 0)
		{
			m_WaitIndex = right_Animation0;
		}
	}

	//Trap_Katana
	if (trap_katana)
	{
		if (katana_y <= 620 - 58)
		{
			DrawGraph(katana_x, katana_y, textureManager->GetTextureDate(trap_Katana), TRUE);
		}
		else
		{
			//刀が床に刺さるようにする
			DrawRectGraph(katana_x, katana_y, 0, 0, 22, int(845 - katana_y - 58), textureManager->GetTextureDate(trap_Katana), TRUE, FALSE);
		}
		if (after_acti)
		{
			//刺さったまま固定させる処理
			DrawRectGraph(katana_x, katana_y, 0, 0, 22, int(845 - 620 - 58), textureManager->GetTextureDate(trap_Katana), TRUE, FALSE);
		}
	}


	//Orc
	DrawGraph(1400, WindowWidth-750, textureManager->GetTextureDate(texture0), TRUE);

	//Text_Bar
	DrawGraph(0, WindowWidth - 283, textureManager->GetTextureDate(texture2), TRUE);
	//Bar_
	DrawGraph(0, WindowWidth-283, textureManager->GetTextureDate(texture3), TRUE);

	//DrawGraph(0, 0, textureManager->GetTextureDate(texture5), TRUE);

	/*if (katana_x + 11 > player.SetPosX() + 56 && katana_x + 11 < player.SetPosX() + 168)
	{
		if (katana_y + 225 > WindowWidth - 700)
		{
			DrawString(0, 0, "HIT", GetColor(0, 0, 0));
		}
	}*/
	if (dead || isfade_in)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawFormatString(100, 100, GetColor(255, 0, 0), "%d", death_count);
}

bool InGameScene::IsEnd() const
{
	return (FinishedScene);
}
