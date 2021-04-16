#include "InGameScene.h"

#define PI    3.1415926535897932384626433832795f

float rad90 = (PI / 2);

//この変数は移動の可能性あり
//, deficit = false, fall = false, , trap_katana = true, have_katana = false;
//int katana.GetPosX() = 800, katana.GetPosY() = 0, fall_speed = 5, death_count = 0,
bool push = false;

enum MoveType
{
	stop_R,
	stop_L,
	move_R,
	move_L,
	jamp,
}; MoveType moveType = stop_R;

enum
{
	STEP_EXEC,
	STEP_PAUSE,
	STEP_END
};

bool orc_dead = false;
int orc_x = 1400;
Player player;
TunagiOger tunagi;
BagOger bag;
GazeOger gaze;
OiranOger oiran;
PeepOger peep;
SmallOger small_;
Item item;
ActionMark actionMark;
Katana katana;
EnemyBase Ebase;
Shuriken shuriken;

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
	m_hp = player.GetHP();
	m_OgreNumber = GetRand(8);
	m_ItemNumber = item_candle;
	m_Step = STEP_EXEC;
	m_RoomNumber = BackGround0;
}


InGameScene::~InGameScene()
{
	textureManager->DeleteSceneTexture();
}

void InGameScene::Exec()
{
	switch (m_Step)
	{
	case STEP_EXEC:
		if (inputManager->IsKeyPushed(KEY_INPUT_P))//一時停止
		{
			m_Step = STEP_PAUSE;
		}

		if (dead == false)
		{
			player.Exec();
			Animation();
		}

		if (inputManager->IsKeyPushed(KEY_INPUT_Q))//アイテムランダム生成
		{
			m_ItemNumber = item.RandItem() + item_candle;
		}

		if (inputManager->IsKeyPushed(KEY_INPUT_E))//鬼ランダム生成
		{
			m_OgreNumber = GetRand(8);
		}

		//katana.Exec(player.GetPosX(), player.GetPosY());
		shuriken.Exec(player.GetPosX(), player.GetPosY());

		if (katana.Collision(player.GetPosX(), player.GetPosY()))
		{
			switch (katana.IsFall())
			{
			case true:dead = true;	break;
			case false:if (player.ItemGet()){player.items.have_katana = true;}break;
			}
		}

		if (shuriken.Collision(player.GetPosX(), player.GetPosY()))
		{

		}
		
		if (Ebase.Collision(player.GetPosX(), player.GetPosY(), EnemyPosY[m_OgreNumber], EnemyTexture_X[m_OgreNumber], EnemyTexture_Y[m_OgreNumber], EnemyPosX[m_OgreNumber]))
		{
			switch (player.items.have_katana)
			{
			case true:	orc_dead = true;	break;

			case false:	dead = true;		break;
			}
		}

		Fade(katana);
		
		break;
	case STEP_PAUSE:Step_Pause(); break;
	case STEP_END: Step_Input();
					IsEnd(); break;
	default: break;
	}
	
}

void InGameScene::Draw()
{
	//BackGround
	DrawGraph(0, 0, textureManager->GetTextureDate(m_RoomNumber), TRUE);

	//Item
	DrawGraph(400, TextBar_Y-309, textureManager->GetTextureDate(m_ItemNumber), TRUE);

	//Player
	DrawGraph(player.GetPosX(), player.GetPosY(), textureManager->GetTextureDate(m_MoveIndex), TRUE);

	if (actionMark.Collition(player.GetPosX(),player.IsRight()))
	{
		DrawGraph(player.GetPosX()+82, player.GetPosY() - 50, textureManager->GetTextureDate(Mark), TRUE);
	}
	//Trap_Katana
	if (katana.IsDraw()==true &&player.items.have_katana==false)
	{
		if (katana.GetPosX() <= 620 - 58)
		{
			DrawGraph(katana.GetPosX(), katana.GetPosY(), textureManager->GetTextureDate(trap_Katana), TRUE);
		}
		else 
		{
			//刀が床に刺さるようにする
			DrawRectGraph(katana.GetPosX(), katana.GetPosY(), 0, 0, 22, int(787 - katana.GetPosY()), textureManager->GetTextureDate(trap_Katana), TRUE, FALSE);
		}
		//if (katana.AfterAction()==true )
		//{
		//	//刺さったまま固定させる処理
		//	//DrawRectGraph(katana.GetPosX(), katana.GetPosY(), 0, 0, 22, int(787 - katana.GetPosY()), textureManager->GetTextureDate(trap_Katana), TRUE, FALSE);
		//}
	}
	DrawGraph(shuriken.GetPosX(), shuriken.GetPosY(), textureManager->GetTextureDate(trap_Shuriken), TRUE);
	
	//Orc
	if (orc_dead == true)
	{
		
	}
	else
	{//
		DrawExtendGraph(orc_x, EnemyPosY[m_OgreNumber], orc_x+ EnemyTexture_X[m_OgreNumber], EnemyPosY[m_OgreNumber]+ EnemyTexture_Y[m_OgreNumber], textureManager->GetTextureDate(m_OgreNumber), TRUE);
	}
	//Text_Bar
	DrawGraph(8, TextBar_Y, textureManager->GetTextureDate(TextBar), TRUE);
	//Bar_
	DrawGraph(8, TextBar_Y, textureManager->GetTextureDate(CharacterTextBar0), TRUE);

	if (dead || isfade_in || push)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
		DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	if (m_Step == STEP_PAUSE)
	{
		DrawString(960, 100, "Pause", GetColor(255, 255, 255));
	}
	//���񂾉񐔁@Debug�p
	//DrawFormatString(100, 100, GetColor(255, 0, 0), "%d", death_count);

	//Debug�p
	if (Ebase.Collision(player.GetPosX() + 70, player.GetPosY(), EnemyPosY[m_OgreNumber], EnemyTexture_X[m_OgreNumber], EnemyTexture_Y[m_OgreNumber],EnemyPosX[m_OgreNumber]) == true)
	{
		DrawString(100, 100, "HIT", GetColor(255, 255, 255));
	}
	
	if (katana.Collision(player.GetPosX(), player.GetPosY()))
	{
		DrawString(100, 20, "刀:HIT", GetColor(255, 255, 255));
	}
	if (katana.IsFall()==true)
	{
		DrawString(100, 140, "落ちてる", GetColor(255, 255, 255));
	}
	if (player.items.have_katana == true)
	{
		DrawString(100, 160, "刀：持ってる", GetColor(255, 255, 255));
	}
	DrawFormatString(100,120, GetColor(255, 255, 255), "%d", m_RoomNumber);
	DrawFormatString(100,60, GetColor(255, 255, 255), "%d", katana.GetPosY());
	DrawFormatString(100,80, GetColor(255, 255, 255), "P_PosX：%d",player.GetPosX());
	DrawFormatString(100, 40, GetColor(255, 255, 255),"真っ黒まで%d", m_hp);
	//DrawFormatString(100, 120, GetColor(255, 255, 255), "%d < %d", 1400, player.GetPosX() + PlayerTexture_X);
	//DrawFormatString(100, 140, GetColor(255, 255, 255), "%d > %d", 1400 + 350, player.GetPosX());
	
	DrawBox(orc_x, EnemyPosY[m_OgreNumber], orc_x + EnemyTexture_X[m_OgreNumber], EnemyPosY[m_OgreNumber] + EnemyTexture_Y[m_OgreNumber], GetColor(255, 255, 255), FALSE);
	
	DrawBox(player.GetPosX() + 70, player.GetPosY(), player.GetPosX() + PlayerTexture_X, player.GetPosY() + PlayerTexture_Y, GetColor(255, 255, 255), FALSE);
	//*/
}

bool InGameScene::IsEnd() const
{
	return (FinishedScene);
}

void InGameScene::Step_Pause()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_P))
	{
		m_Step = STEP_EXEC;
	}
}

void InGameScene::Step_Input()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(Title);
	}
}

void InGameScene::Fade(Katana katana)
{
	if (inputManager->IsKeyPushed(KEY_INPUT_B))//強制フェードアウト
	{
		push = true;
	}
	//フェードアウト
	if (dead || push )
	{
		m_alpha += m_fade_speed;
		if (m_alpha >= 255)
		{
			isfade_in = true;
			player.SetPosX(100);
			dead = false;
			after_acti = true;
			//katana.SetPosY(FallStopLimit);
			m_OgreNumber = GetRand(8);
			//m_hp--;
			push = false;
			orc_dead = false;
			RoomChange();
		}
		if (m_hp == 0)
		{
			m_Step = STEP_END;
		}

	}
	if (isfade_in && m_hp > 0)
	{
		m_alpha -= m_fade_speed;
		if (m_alpha <= 0)
		{
			isfade_in = false;
		}
	}
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

void InGameScene::RoomChange()
{
	m_RoomNumber++;
	if (m_RoomNumber== trap_Katana)
	{
		m_RoomNumber = BackGround0;
	}
	
}

