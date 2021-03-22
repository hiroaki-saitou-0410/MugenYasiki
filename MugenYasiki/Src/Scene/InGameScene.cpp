#include "InGameScene.h"

#define PI    3.1415926535897932384626433832795f

float rad90 = (PI / 2);

//この変数は移動の可能性あり
bool after_acti = false, deficit = false, fall = false, dead = false, isfade_in = false, trap_katana = true, have_katana = false;
int katana_x = 800, katana_y = 0, fall_speed = 10, death_count = 0, alpha = 0, fade_speed = 2;;

enum MoveType
{
	stop_R,
	stop_L,
	move_R,
	move_L,
	jamp,
}; MoveType moveType = stop_R;

bool orc_dead = false;
int orc_x = 1400, orc_y = WindowWidth - 750;
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
	m_LeftMotionMax = left_Animation7;
	m_ActSpeed=9;
	m_ActStop= m_ActSpeed;
	m_MoveIndex = right_Animation0;
}

InGameScene::~InGameScene()
{
	textureManager->DeleteSceneTexture();
}

void InGameScene::Exec()
{
	player.Exec();

	//刀の落下
	if ((katana_x - 40) <= player.GetPosX() + 112)
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
	if (katana_x + 11 > player.GetPosX() + 56 && katana_x + 11 < player.GetPosX() + 168 && !after_acti && !dead)
	{
		if (katana_y + 225 > WindowWidth - 700)
		{
			death_count++;
			dead = true;
		}
	}
	if (katana_x + 11 > player.GetPosX() + 56 && katana_x + 11 < player.GetPosX() + 168 && after_acti && !dead)
	{
		have_katana = true;
		trap_katana = false;
	}
	
	// プレイヤーと鬼の当たり判定
	if ((player.GetPosX() + 112) > orc_x &&
		player.GetPosX() < orc_x + 300)
	{
		switch (have_katana)
		{
		case true:	orc_dead = true;	break;

		case false:	dead = true;		break;
		}
	}

	//フェードアウト
	if (dead)
	{
		alpha += fade_speed;
		if (alpha >= 255)
		{
			isfade_in = true;
			player.SetPosX(100);
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
	DrawGraph(player.GetPosX(), WindowWidth - 700, textureManager->GetTextureDate(m_MoveIndex), TRUE);
	//Player�A�j���[�V�����֐�
	Animation();

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
	if (orc_dead == true){}
	else
	{
		DrawGraph(orc_x, orc_y, textureManager->GetTextureDate(texture0), TRUE);
	}
	//Text_Bar
	DrawGraph(0, WindowWidth - 283, textureManager->GetTextureDate(texture2), TRUE);
	//Bar_
	DrawGraph(0, WindowWidth-283, textureManager->GetTextureDate(texture3), TRUE);

	

	if (dead || isfade_in)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	//���񂾉񐔁@Debug�p
	//DrawFormatString(100, 100, GetColor(255, 0, 0), "%d", death_count);

	//Debug�p
	/*if (player.Collision(1400, TUNAGI_Oger_Y) == true)
	//{
	//	DrawString(100, 100, "HIT", GetColor(255, 255, 255));
	//}
	//
	//DrawFormatString(100, 120, GetColor(255, 255, 255), "���F%d < %d", 1400, player.GetPosX() + PlayerTexture_X);
	//DrawFormatString(100, 140, GetColor(255, 255, 255), "�E�F%d > %d", 1400 + 350, player.GetPosX());
	//
	//DrawBox(1400, TUNAGI_Oger_Y, 1400 + 350, TUNAGI_Oger_Y + 479, GetColor(255, 255, 255), FALSE);
	//
	//DrawBox(player.GetPosX(), Player_Y, player.GetPosX() + PlayerTexture_X, Player_Y + PlayerTexture_Y, GetColor(255, 255, 255), FALSE);*/
}

bool InGameScene::IsEnd() const
{
	return (FinishedScene);
}

void InGameScene::Animation()
{
	switch (moveType)// && player.IsStop() == false
	{
	case stop_R:
		if (player.IsStop() == true)
		{
			if (player.IsRight() == true)
			{
				m_MoveIndex = right_stop;
			}
			else
			{
				moveType = stop_L;
				m_MoveIndex = left_stop;
			}
		}
		else
		{
			moveType = move_R;
			m_MoveIndex = right_Animation0;
			if (player.IsRight() == false)
			{
				moveType = move_L;
				m_MoveIndex = left_Animation0;
			}
		}
		break;

	case stop_L:
		if (player.IsStop() == true)
		{
			if (player.IsRight() == false)
			{
				m_MoveIndex = left_stop;
			}
			else
			{
				moveType = stop_R;
				m_MoveIndex = right_stop;
			}
		}
		else
		{
			moveType = move_L;
			m_MoveIndex = left_Animation0;
			if (player.IsRight() == true)
			{
				moveType = move_R;
				m_MoveIndex = right_Animation0;
			}
		}
		break;

	case move_R:
		if (--m_ActStop <= 0 && player.IsStop() == false && player.IsRight() == true)
		{
			m_MoveIndex++;
			m_ActStop = m_ActSpeed;
			m_MoveIndex %= m_RightMotionMax;
			if (m_MoveIndex == 0)
			{
				m_MoveIndex = right_Animation0;
			}
		}

		if (player.IsStop() == true)
		{
			moveType = stop_R;
		}
		break;
	case move_L:
		if (--m_ActStop <= 0 && player.IsStop() == false && player.IsRight() == false)
		{
			m_MoveIndex++;
			m_ActStop = m_ActSpeed;
			m_MoveIndex %= m_LeftMotionMax;
			if (m_MoveIndex == 0)
			{
				m_MoveIndex = left_Animation0;
			}
		}
		if (player.IsStop() == true)
		{
			moveType = stop_L;
		}
		break;
	}
}
