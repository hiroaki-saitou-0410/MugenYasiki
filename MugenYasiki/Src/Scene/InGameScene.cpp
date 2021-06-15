#include "InGameScene.h"

#define PI    3.1415926535897932384626433832795f

float rad90 = (PI / 2);

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
KatanaTukiage tukiage;
ScaringOgre scaringOgre;
SwordRain swordRain;
OgreRain ogreRain;
Scissors scissors;
JapaneseDoll japaneseDoll;
Amulet amulet;
LieOgre lie;
Boss boss;

InGameScene::InGameScene()
{
	//各インスタンス
	gamenManager = GameManager::GetInstance();
	inputManager = InputManager::GetInstance();
	textureManager = TextureManager::GetInstance();
	soundManager = SoundManager::GetInstance();

	SceneManager::GetInstance()->SetNextScene(InGame);
	textureManager->LoadSceneTexture(InGame);
	soundManager->LoadSceneSound(InGame);

	m_RightMotionMax = right_Animation7;
	m_LeftMotionMax = left_Animation7;
	m_ActSpeed = 9;
	m_ActStop= m_ActSpeed;
	m_MoveIndex = right_Animation0;
	m_hp = player.GetHP();
	m_OgreNumber = GetRand(7);
	m_GimmickNumber = GetRand(4);
	m_ItemNumber = item_candle;
	m_Step = STEP_EXEC;
	m_RoomNumber = Hall;

	swordRain.Init();
	ogreRain.Init();
	InitRand();

	Prologue_Run = 0;
	Epilogue_Run = 0;
	FontHandle = CreateFontToHandle(NULL, 40, 3);
}


InGameScene::~InGameScene()
{
	textureManager->DeleteSceneTexture();
	soundManager->DeleteSceneSound();
}

void InGameScene::Exec()
{
	//switch (rooms)
	//{
	//case Strat_Hall:
	//	ItemExec();
	//	GimmickExec();
	//	if (actionMark.CollisionR(player.GetPosX(), player.IsRight())&&player.IsDecision())
	//	{
	//		rooms = Floor2_Corridor;
	//		m_RoomChange = true;
	//	}
	//	break;
	//case Floor2_Hall:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Floor2_Hall1:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Floor2_Hall2:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Floor2_Hall3:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Floor2_Corridor:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		//EnemyExec();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Floor2_Corridor1;
	//			m_RoomChange = true;
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Strat_Hall;
	//			m_RoomChange = true;
	//		}
	//	}
	//	break;
	//case Floor2_Corridor1:
	//	if (m_RoomChange == false)
	//	{
	//		//GimmickExec();
	//		EnemyExec();
	//		//if (actionMark.CollisionR(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		//{
	//		//	rooms = Floor2_Corridor3;
	//		//	m_RoomChange = true;
	//		//}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Floor2_Corridor;
	//			m_RoomChange = true;
	//		}
	//	}
	//	break;
	//case Floor2_Corridor2:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Floor2_Corridor;
	//			m_RoomChange = true;
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Floor2_Corridor3;
	//			m_RoomChange = true;
	//		}
	//	}
	//	break;
	//case Floor2_Corridor3:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Floor2_Corridor2;
	//			m_RoomChange = true;
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()) && player.IsDecision())
	//		{
	//			rooms = Floor2_Corridor1;
	//			m_RoomChange = true;
	//		}
	//	}
	//	break;
	//
	//case Father_room:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Floor1_Corridorl:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Floor1_Hall:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case Workshop:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//case G_Entrance:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickExec();
	//		EnemyExec();
	//	}
	//	break;
	//default:
	//	break;
	//}
		InGameScene::Prologue();
		InGameScene::Epilogue();

		if (Prologue_Run != 1)
		{
			switch (m_Step)
			{
			case STEP_EXEC:
				if (inputManager->IsKeyPushed(KEY_INPUT_P))//一時停止
				{
					m_Step = STEP_PAUSE;
				}

				if (player.items.have_omamori == false)
				{
					GimmickExec();
					EnemyExec();
				}

				if (dead == false)
				{
					if (amulet.IsDraw() == false)
					{
						player.Exec();
						Animation();
					}
					else if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
					{
						player.items.have_omamori = true;
						amulet.ResettingDraw(false);
					}
				}

				if (actionMark.Collision(player.GetPosX(), RightLimitPosX) && player.items.have_omamori == true)
				{
					Step_Input();
				}

				//if (inputManager->IsKeyPushed(KEY_INPUT_1))
				//{
				//	m_GimmickNumber = GetRand(4);
				//}
				Fade();

				//if (inputManager->IsKeyPushed(KEY_INPUT_Q))//アイテムランダム生成
				//{
				//	m_ItemNumber = item.RandItem() + item_candle;
				//}
				//
				//if (inputManager->IsKeyPushed(KEY_INPUT_E))//鬼ランダム生成
				//{
				//	m_OgreNumber = GetRand(7);
				//}

				break;
			case STEP_PAUSE:Step_Pause(); break;
			default: break;
			}
		}
}

void InGameScene::Draw()
{
	switch (aftMotion)
	{
	case eye:gaze.AfterAction(textureManager->GetTextureDate(gaze_eye)); break;
	case wet:lie.AfterAction(textureManager->GetTextureDate(lie_wet)); break;
	case blood:boss.AfterAction(textureManager->GetTextureDate(boss_blood)); break;
	case normal:
	//	
	//	//BackGround
	//	//DrawGraph(0 + bag.QuakingDisply_X(), 0 + tunagi.QuakingDisply(), textureManager->GetTextureDate(BackGround0), TRUE);
		if (player.items.have_omamori==false)
		{
			DrawExtendGraph(0 + bag.QuakingDisply_X(), 0 + tunagi.QuakingDisply(), bag.QuakingDisply_X() + WindowWidth, tunagi.QuakingDisply() + WindowHeight, textureManager->GetTextureDate(BackGround0), TRUE);
		}
		else
		{
			DrawExtendGraph(0 + bag.QuakingDisply_X(), 0 + tunagi.QuakingDisply(), bag.QuakingDisply_X() + WindowWidth, tunagi.QuakingDisply() + WindowHeight, textureManager->GetTextureDate(GameClearBG), TRUE);
		}
		
		//Player
		DrawGraph(player.GetPosX() + bag.QuakingDisply_X(), player.GetPosY() + tunagi.QuakingDisply(), textureManager->GetTextureDate(m_MoveIndex), TRUE);
	
		if (actionMark.Collision(player.GetPosX(), RightLimitPosX) && player.items.have_omamori == true)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}

		if(player.items.have_omamori == false)
		{
			GimmickDraw();
			EnemyDraw();
		}	
	
	//switch (rooms)
	//{
	//case Strat_Hall:
	//	DrawString(100, 100, "スタートの広間", GetColor(255, 255, 255));
	//	if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//	{
	//		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//	}
	//	//GimmickDraw();
	//	ItemDraw();
	//	break;
	//case Floor2_Hall:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Hall1:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Hall2:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Hall3:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Corridor:
	//	DrawString(100, 100, "2-1廊下", GetColor(255, 255, 255));
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		//EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Corridor1:
	//	DrawString(100, 100, "2-2廊下", GetColor(255, 255, 255));
	//	if (m_RoomChange == false)
	//	{
	//		//GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Corridor2:
	//	DrawString(100, 100, "2-3廊下", GetColor(255, 255, 255));
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Floor2_Corridor3:
	//	DrawString(100, 100, "2-4廊下", GetColor(255, 255, 255));
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Father_room:
	//	GimmickDraw();
	//	EnemyDraw();
	//	if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//	{
	//		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//	}
	//	if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//	{
	//		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//	}
	//	break;
	//case Floor1_Corridorl:
	//	GimmickDraw();
	//	EnemyDraw();
	//	if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//	{
	//		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//	}
	//	if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//	{
	//		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//	}
	//	break;
	//case Floor1_Hall:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case Workshop:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//case G_Entrance:
	//	if (m_RoomChange == false)
	//	{
	//		GimmickDraw();
	//		EnemyDraw();
	//		if (actionMark.CollisionR(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//		if (actionMark.CollisionL(player.GetPosX(), player.IsRight()))
	//		{
	//			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	//		}
	//	}
	//	break;
	//default:
	//	break;
	//}	
	
		if (dead || isfade_in || m_RoomChange)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	
		if (m_Step == STEP_PAUSE)
		{
			DrawString(960, 100, "Pause", GetColor(255, 255, 255));
		}
	
		oiran.AfterAction(textureManager->GetTextureDate(oiran_smoku));
	
		DrawFormatString(100, 120, GetColor(255, 255, 255), "%d", m_AmuletPos); 
		DrawFormatString(100, 100, GetColor(255, 255, 255), "%d", Enemy[5]);
	/*Debag=======================================================
	DrawFormatString(100, 120, GetColor(255, 255, 255), "%d", m_GimmickNumber);
	if (tukiage.Collision(player.GetPosX(), player.GetPosY()))
	{
		DrawString(100, 100, "HIT", GetColor(255, 255, 255));
	}
	DrawFormatString(100, 100, GetColor(255, 0, 0), "%d", death_count);

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
	DrawFormatString(100,120, GetColor(255, 255, 255), "%d", m_GimmickNumber);
	DrawFormatString(100,60, GetColor(255, 255, 255), "%d", katana.GetPosY());
	DrawFormatString(100,80, GetColor(255, 255, 255), "P_PosX：%d",player.GetPosX());
	DrawFormatString(100, 40, GetColor(255, 255, 255),"真っ黒まで%d", m_hp);
	DrawFormatString(100, 120, GetColor(255, 255, 255), "%d", m_OgreNumber);

	//DrawFormatString(100, 120, GetColor(255, 255, 255), "%d < %d", 1400, player.GetPosX() + PlayerTexture_X);
	//DrawFormatString(100, 140, GetColor(255, 255, 255), "%d > %d", 1400 + 350, player.GetPosX());

	DrawBox(orc_x, EnemyPosY[m_OgreNumber], orc_x + EnemyTexture_X[m_OgreNumber], EnemyPosY[m_OgreNumber] + EnemyTexture_Y[m_OgreNumber], GetColor(255, 255, 255), FALSE);

	DrawBox(player.GetPosX() + 70, player.GetPosY(), player.GetPosX() + PlayerTexture_X, player.GetPosY() + PlayerTexture_Y, GetColor(255, 255, 255), FALSE);

	//if (ogreRain.Collision(player.GetPosX(),player.GetPosY()))
	//{
	//	DrawString(300, 100, "HIT",GetColor(255, 255, 255));
	//}
	//=================================================================
	//*/
		break;
	default:
		break;
	}

	if (Prologue_Run == 1)
	{
		DrawWidth1 = GetDrawStringWidthToHandle("目が覚めるとそこは知らない場所だった。", -1, FontHandle);
		DrawWidth2 = GetDrawStringWidthToHandle("あたりを見渡すと どうやら和風の建物のようだが、薄暗くて気味が悪い。", -1, FontHandle);
		DrawWidth3 = GetDrawStringWidthToHandle("外に出ようと襖を開けようとするがなぜか開かない。", -1, FontHandle);
		DrawWidth4 = GetDrawStringWidthToHandle("どうやら鍵が外からかけらているようだ。このままでは出ることが出来ない。", -1, FontHandle);
		DrawWidth5 = GetDrawStringWidthToHandle("千代ちゃんは、部屋になにか扉を開けるものはないか探すことにした...", -1, FontHandle);

		if (Pro_alpha >= 255)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Pro_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 300, "目が覚めるとそこは知らない場所だった。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 400, "あたりを見渡すと どうやら和風の建物のようだが、薄暗くて気味が悪い。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 500, "外に出ようと襖を開けようとするがなぜか開かない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 600, "どうやら鍵が外からかけらているようだ。このままでは出ることが出来ない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 700, "千代ちゃんは、部屋になにか扉を開けるものはないか探すことにした...", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			Pro_alpha += m_fade_speed;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Pro_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 300, "目が覚めるとそこは知らない場所だった。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 400, "あたりを見渡すと どうやら和風の建物のようだが、薄暗くて気味が悪い。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 500, "外に出ようと襖を開けようとするがなぜか開かない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 600, "どうやら鍵が外からかけらているようだ。このままでは出ることが出来ない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 700, "千代ちゃんは、部屋になにか扉を開けるものはないか探すことにした...", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	else if (Prologue_Run == 2)
	{
		if (Pro_alpha <= 0)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Pro_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 300, "目が覚めるとそこは知らない場所だった。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 400, "あたりを見渡すと どうやら和風の建物のようだが、薄暗くて気味が悪い。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 500, "外に出ようと襖を開けようとするがなぜか開かない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 600, "どうやら鍵が外からかけらているようだ。このままでは出ることが出来ない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 700, "千代ちゃんは、部屋になにか扉を開けるものはないか探すことにした...", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			Pro_alpha -= m_fade_speed;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Pro_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 300, "目が覚めるとそこは知らない場所だった。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 400, "あたりを見渡すと どうやら和風の建物のようだが、薄暗くて気味が悪い。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 500, "外に出ようと襖を開けようとするがなぜか開かない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 600, "どうやら鍵が外からかけらているようだ。このままでは出ることが出来ない。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 700, "千代ちゃんは、部屋になにか扉を開けるものはないか探すことにした...", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	if (Epilogue_Run == 1)
	{
		DrawWidth1 = GetDrawStringWidthToHandle("「やっと外に出れた！」しかしなぜかしわがれた声が出る", -1, FontHandle);
		DrawWidth2 = GetDrawStringWidthToHandle("しかもなんだか体がうまく動かない", -1, FontHandle);
		DrawWidth3 = GetDrawStringWidthToHandle("そう思って手をみてみるとしわくちゃの手", -1, FontHandle);
		DrawWidth4 = GetDrawStringWidthToHandle("後ろを振り返るとボロボロになっている屋敷", -1, FontHandle);
		DrawWidth9 = GetDrawStringWidthToHandle("どうやらとてつもない時間が経っているようだ。", -1, FontHandle);
		DrawWidth5 = GetDrawStringWidthToHandle("「なんで？どうなっているの？」", -1, FontHandle);
		DrawWidth6 = GetDrawStringWidthToHandle("とりあえず山を下りようと目の前の鳥居をくぐると", -1, FontHandle);
		DrawWidth7 = GetDrawStringWidthToHandle("「はて？私はなんでここにいたんだったかな？」", -1, FontHandle);
		DrawWidth8 = GetDrawStringWidthToHandle("千代ちゃんは記憶をなくし町に溶け込んでいくのだった…", -1, FontHandle);

		if (Epi_alpha >= 255)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Epi_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 100, "「やっと外に出れた！」しかしなぜかしわがれた声が出る", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 200, "しかもなんだか体がうまく動かない", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 300, "そう思って手をみてみるとしわくちゃの手", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 400, "後ろを振り返るとボロボロになっている屋敷", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth9) / 2, 500, "どうやらとてつもない時間が経っているようだ。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 600, "「なんで？どうなっているの？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth6) / 2, 700, "とりあえず山を下りようと目の前の鳥居をくぐると", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth7) / 2, 800, "「はて？私はなんでここにいたんだったかな？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth8) / 2, 900, "千代ちゃんは記憶をなくし町に溶け込んでいくのだった…", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			Epi_alpha += m_fade_speed;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Epi_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 100, "「やっと外に出れた！」しかしなぜかしわがれた声が出る", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 200, "しかもなんだか体がうまく動かない", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 300, "そう思って手をみてみるとしわくちゃの手", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 400, "後ろを振り返るとボロボロになっている屋敷", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth9) / 2, 500, "どうやらとてつもない時間が経っているようだ。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 600, "「なんで？どうなっているの？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth6) / 2, 700, "とりあえず山を下りようと目の前の鳥居をくぐると", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth7) / 2, 800, "「はて？私はなんでここにいたんだったかな？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth8) / 2, 900, "千代ちゃんは記憶をなくし町に溶け込んでいくのだった…", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	else if (Epilogue_Run == 2)
	{
		if (Epi_alpha <= 0)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Epi_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 100, "「やっと外に出れた！」しかしなぜかしわがれた声が出る", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 200, "しかもなんだか体がうまく動かない", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 300, "そう思って手をみてみるとしわくちゃの手", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 400, "後ろを振り返るとボロボロになっている屋敷", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth9) / 2, 500, "どうやらとてつもない時間が経っているようだ。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 600, "「なんで？どうなっているの？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth6) / 2, 700, "とりあえず山を下りようと目の前の鳥居をくぐると", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth7) / 2, 800, "「はて？私はなんでここにいたんだったかな？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth8) / 2, 900, "千代ちゃんは記憶をなくし町に溶け込んでいくのだった…", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			Epi_alpha -= m_fade_speed;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Epi_alpha);
			DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
			DrawStringToHandle((WindowWidth - DrawWidth1) / 2, 100, "「やっと外に出れた！」しかしなぜかしわがれた声が出る", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth2) / 2, 200, "しかもなんだか体がうまく動かない", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth3) / 2, 300, "そう思って手をみてみるとしわくちゃの手", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth4) / 2, 400, "後ろを振り返るとボロボロになっている屋敷", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth9) / 2, 500, "どうやらとてつもない時間が経っているようだ。", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth5) / 2, 600, "「なんで？どうなっているの？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth6) / 2, 700, "とりあえず山を下りようと目の前の鳥居をくぐると", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth7) / 2, 800, "「はて？私はなんでここにいたんだったかな？」", GetColor(255, 255, 255), FontHandle);
			DrawStringToHandle((WindowWidth - DrawWidth8) / 2, 900, "千代ちゃんは記憶をなくし町に溶け込んでいくのだった…", GetColor(255, 255, 255), FontHandle);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

void InGameScene::GimmickExec()
{
	if (actionMark.Collision(player.GetPosX(),Gimmick[0] ))
	{
		if (player.IsDecision()==true)
		{
			ogreRain.ResettingExec(player.IsDecision());
		}
	}
	ogreRain.Exec();
	if (ogreRain.IsExec() == true)
	{
		if (ogreRain.Collision(player.GetPosX(), player.GetPosY()) == true)
		{
			dead = true;
		}
	}

	if (actionMark.Collision(player.GetPosX(),Gimmick[1] ))
	{
		if (player.IsDecision()==true)
		{
			swordRain.ResettingExec(player.IsDecision());
		}
	}
	swordRain.Exec();
	if (swordRain.IsExec() == true)
	{

		if (swordRain.Collision(player.GetPosX(), player.GetPosY()) == true)
		{
			dead = true;
		}
	}
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[2]))
	{
		if (player.items.have_katana == false && player.IsDecision() == true)
		{
			katana.ResettingExec(player.IsDecision() == true);
		}
	}
	katana.Exec(player.GetPosX());
	if (katana.Collision(player.GetPosX(), player.GetPosY()))
	{
		switch (katana.IsFall())
		{
		case true:dead = true;	break;
		case false:if (player.ItemGet()) { player.items.have_katana = true; }break;
		}
	}
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[3]))
	{
		if (player.IsDecision() == true)
		{
			tukiage.ResettingExec(player.IsDecision());
		}
	}
	tukiage.Exec(player.GetPosX());
	if (tukiage.Collision(player.GetPosX(), player.GetPosY()))
	{
		switch (tukiage.PushUp())
		{
		case true:dead = true; break;
		case false:break;
		default:
			break;
		}
	}
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[4]))
	{
		if (player.IsDecision() == true)
		{
			scaringOgre.ResettingExec(player.IsDecision());
			dead = true;
		}
	}
	scaringOgre.Exec();
	
	//shuriken.Exec(player.GetPosX(), player.GetPosY());
	
	if (actionMark.Collision(player.GetPosX(), m_AmuletPos))
	{
		if (player.IsDecision()==true && amulet.Status()==false)
		{
			amulet.Exec(player.IsDecision());
			itemCodePasses.Amulet = true;
		}
	}
	
}

void InGameScene::GimmickDraw()
{
	if (actionMark.Collision(player.GetPosX(), Gimmick[0]))
	{
		if (ogreRain.IsExec()==false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark),TRUE);
		}
	}
	ogreRain.Draw(textureManager->GetTextureDate(small_Ogre1));
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[1]))
	{
		if (swordRain.IsExec()==false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
			
		}
	}
	swordRain.Draw(textureManager->GetTextureDate(trap_Katana));
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[2]))
	{
		if (katana.IsExec()==false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}		
	}
	if (player.items.have_katana == false )
	{
		katana.Draw(textureManager->GetTextureDate(trap_Katana));
	}
	katana.SetDisplayKatana(player.items.have_katana);
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[3]))
	{
		if (tukiage.IsExec()==false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}
	}
	tukiage.Draw(textureManager->GetTextureDate(trap_Katana), PI);
	
	if (actionMark.Collision(player.GetPosX(), Gimmick[4]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	scaringOgre.Draw(textureManager->GetTextureDate(crawling_Ogre));
	
	//shuriken.Draw(textureManager->GetTextureDate(trap_Shuriken), PI);

	if (actionMark.Collision(player.GetPosX(), m_AmuletPos))
	{
		if (itemCodePasses.Amulet == false)
		{
			//DrawString(player.GetPosX() + MarkDrawX, player.GetPosY()-50, "!!", GetColor(255, 255, 255));
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}
	}
	if (itemCodePasses.Amulet == true)
	{
		amulet.Draw(textureManager->GetTextureDate(item_Amulet), textureManager->GetTextureDate(item_Get_Amulet), textureManager->GetTextureDate(item_Get_itemframe), textureManager->GetTextureDate(ClearBlack));
	}
}

void InGameScene::EnemyExec()
{
	if (actionMark.Collision(player.GetPosX(), Enemy[0]))
	{
		if (player.IsDecision()==true)
		{
			tunagi.ResettingExec(player.IsDecision());
		}
	}
	if (tunagi.IsPlayerDead() == true)
	{
		dead = true;
	}
	tunagi.Exec();

	if (actionMark.Collision(player.GetPosX(), Enemy[1]))
	{
		if (player.IsDecision() == true)
		{
			gaze.ResettingExec(player.IsDecision());
			peep.ResettingExec(player.IsDecision());
		}
	}
	if (gaze.IsPlayerDead() == true)
	{
		dead = true;
	}
	gaze.Exec();
	peep.Exec();

	if (actionMark.Collision(player.GetPosX(), Enemy[2]))
	{
		if (player.IsDecision() == true)
		{
			bag.ResettingExec(player.IsDecision());
		}
	}
	if (bag.IsPlayerDead() == true)
	{
		dead = true;
	}
	bag.Exec(player.GetPosX());

	if (actionMark.Collision(player.GetPosX(), Enemy[3]))
	{
		if (player.IsDecision() == true)
		{
			oiran.ResettingExec(player.IsDecision());
		}
	}
	if (oiran.IsPlayerDead() == true)
	{
		dead = true;
	}
	oiran.Exec();
	if (oiran.IsExec() == true)
	{
		oiran.ResettingAction(true);
		//aftMotion = smoke;
	}

	if (actionMark.Collision(player.GetPosX(), Enemy[4]))
	{
		if (player.IsDecision() == true)
		{
			lie.ResettingExec(player.IsDecision());
		}
	}
	if (lie.IsPlayerDead()==true)
	{
		dead = true;
	}
	lie.Exec();

	if (actionMark.Collision(player.GetPosX(), Enemy[5]))
	{
		if (player.IsDecision() == true)
		{
			boss.ResettingExec(player.IsDecision());
		}
	}
	if (boss.IsPlayerDead() == true)
	{
		dead = true;
	}
	boss.Exec();

	//if (rooms != Strat_Hall)
	//{
	//	if (player.items.have_Scissors == true)
	//	{
	//		scissors.ActExec();
	//	}
	//	if (scissors.StopCollision()==false)
	//	{
	//		if (Ebase.Collision(player.GetPosX(), player.GetPosY(), EnemyPosY[m_OgreNumber], EnemyTexture_X[m_OgreNumber], EnemyTexture_Y[m_OgreNumber], EnemyPosX[m_OgreNumber]))
	//		{
	//			switch (player.items.have_katana)
	//			{
	//			case true:	orc_dead = true;	break;
	//
	//			case false:	dead = true;		break;
	//			}
	//		}
	//	}
	//}
}

void InGameScene::EnemyDraw()
{
	if (actionMark.Collision(player.GetPosX(), Enemy[0]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	tunagi.Draw(textureManager->GetTextureDate(tunagi_Ogre), Enemy[0]);

	if (actionMark.Collision(player.GetPosX(), Enemy[1]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	gaze.Draw(textureManager->GetTextureDate(flontGazeOgre),Enemy[1]);
	peep.Draw(textureManager->GetTextureDate(flontPeepOgre),Enemy[1]);

	if (actionMark.Collision(player.GetPosX(), Enemy[2]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	bag.Draw(textureManager->GetTextureDate(bag_Ogre));

	if (actionMark.Collision(player.GetPosX(), Enemy[3]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	oiran.Draw(textureManager->GetTextureDate(oiran_Ogre), Enemy[3]);

	if (actionMark.Collision(player.GetPosX(), Enemy[4]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	lie.Draw(textureManager->GetTextureDate(lie_Ogre), Enemy[4]);

	if (actionMark.Collision(player.GetPosX(), Enemy[5]))
	{
		DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
	}
	boss.Draw(textureManager->GetTextureDate(boss_Ogre), Enemy[5]);

	////Orc
	//if (orc_dead == true)
	//{
	//
	//}
	//else
	//{//
	//	DrawExtendGraph(orc_x, EnemyPosY[m_OgreNumber], orc_x + EnemyTexture_X[m_OgreNumber], EnemyPosY[m_OgreNumber] + EnemyTexture_Y[m_OgreNumber], textureManager->GetTextureDate(m_OgreNumber), TRUE);
	//}
}

void InGameScene::ItemExec()
{
	if(itemCodePasses.Scissors == false)
	{
		if (actionMark.Collision(player.GetPosX(), scissors.GetPosX()))
		{
			if (player.ItemGet() == true)
			{
				scissors.Exec(player.ItemGet());
				scissors.IsExplain(player.ItemGet());
				player.items.have_Scissors = player.ItemGet();
			}
		}
	}
	
	if (actionMark.Collision(player.GetPosX(), japaneseDoll.GetPosX()))
	{
		if (itemCodePasses.Japan_Doll == false)
		{
			if (player.ItemGet() == true)
			{
				japaneseDoll.Exec(player.ItemGet());
				japaneseDoll.IsExplain(player.ItemGet());
				player.items.have_Japanese_doll = player.ItemGet();
			}
		}
	}	
}

void InGameScene::ItemDraw()
{
	scissors.ItemBar(textureManager->GetTextureDate(item_Scissors), textureManager->GetTextureDate(item_Get_itemframe), player.items.have_Scissors);
	japaneseDoll.ItemBar(textureManager->GetTextureDate(item_Japanese_doll), textureManager->GetTextureDate(item_Get_itemframe), player.items.have_Japanese_doll);

	//Scissors
	if (actionMark.Collision(player.GetPosX(), scissors.GetPosX()))
	{
		if (itemCodePasses.Scissors == false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}
	}
	if (itemCodePasses.Scissors == false)
	{
		scissors.Draw(textureManager->GetTextureDate(item_Scissors), textureManager->GetTextureDate(item_Get_Scissors), textureManager->GetTextureDate(item_Get_itemframe), textureManager->GetTextureDate(ClearBlack), player.items.have_Scissors);
		if (player.IsDecision() == true && player.items.have_Scissors==true)
		{
			scissors.IsExplain(false);
			itemCodePasses.Scissors = true;
		}
	}
	
	//JapaneseDoll
	if (actionMark.Collision(player.GetPosX(), japaneseDoll.GetPosX()))
	{
		if (itemCodePasses.Japan_Doll == false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}
	}
	if (itemCodePasses.Japan_Doll == false)
	{
		japaneseDoll.Draw(textureManager->GetTextureDate(item_Japanese_doll), textureManager->GetTextureDate(item_Get_Japanese_doll), textureManager->GetTextureDate(item_Get_itemframe), textureManager->GetTextureDate(ClearBlack), player.items.have_Japanese_doll);
		if (player.IsDecision() == true && player.items.have_Japanese_doll==true)
		{
			japaneseDoll.IsExplain(false);
			itemCodePasses.Japan_Doll = true;
		}
	}
	if (japaneseDoll.IsExplosion() == true)
	{
		DrawRotaGraph2(japaneseDoll.GetPosX(), japaneseDoll.GetPosY(), ExplosionTexture / 2, ExplosionTexture / 2, 1.3, 0, textureManager->GetTextureDate(japaneseDoll.TextureNumber()), TRUE, TRUE);
	}

	//Amulet
	if (actionMark.Collision(player.GetPosX(), amulet.GetPosX()))
	{
		if (itemCodePasses.Amulet == false)
		{
			DrawGraph(player.GetPosX() + MarkDrawX, player.GetPosY(), textureManager->GetTextureDate(Mark), TRUE);
		}
	}
	if (itemCodePasses.Amulet == false)
	{
		//amulet.Draw(textureManager->GetTextureDate(item_Amulet), textureManager->GetTextureDate(item_Get_Amulet), textureManager->GetTextureDate(item_Get_itemframe), textureManager->GetTextureDate(ClearBlack), player.items.have_omamori);
		if (player.IsDecision() == true && player.items.have_omamori == true)
		{
			amulet.IsExplain(false);
			itemCodePasses.Amulet = true;
		}
	}

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
	if (Epilogue_Run == 0)
	{
		Epilogue_Run = 1;
	}
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN) && Epilogue_Run == 2)
	{
		FinishedScene = true;
		amulet.IsExplain(false);
		player.items.have_omamori = false;
		itemCodePasses.Amulet = false;
		player.SetPosX(LeftLimitPosX);
		katana.FullReset();
		SceneManager::GetInstance()->SetNextScene(Title);
	}
}

void InGameScene::Fade()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_B))//強制フェードアウト
	{
		dead = true;
	}
	//フェードアウト
	if (dead || m_RoomChange)
	{
		m_alpha += m_fade_speed;
		if (m_alpha >= 255)
		{
			if (gaze.IsExec() == true)
			{
				gaze.ResettingAction(true);
				aftMotion = eye;
			}
			if (lie.IsExec()==true)
			{
				lie.ResettingAction(true);
				aftMotion = wet;
			}
			if (boss.IsExec()==true)
			{
				boss.ResettingAction(true);
				aftMotion = blood;
			}

			isfade_in = true;
			dead = false;
			after_acti = true;
			orc_dead = false;
			ogreRain.ResettingExec(false);
			tukiage.ResettingExec(false);
			scaringOgre.ResettingExec(false);
			swordRain.ResettingExec(false);
			tukiage.SetDraw(false);

			swordRain.Init();
			ogreRain.Init();
			tukiage.IsInit(false);
			tunagi.ResettingKill(false);
			gaze.ResettingKill(false);
			peep.ResettingExec(false);
			bag.ResettingKill(false);
			oiran.ResettingExec(false);
			oiran.ResettingKill(false);
			lie.ResettingExec(false);
			lie.ResettingKill(false);
			boss.ResettingExec(false);
			boss.ResettingKill(false);

			tukiage.SetPosY(TextBar_Y + KatanaTextureY);
			RoomChange();
			InitRand();

			if (m_RoomChange==true)
			{
				m_OgreNumber = GetRand(7);
				m_GimmickNumber = GetRand(4);
			}
			if (player.items.have_katana == true)
			{
				katana.SetPosY(0);
			}
			player.SetPosX(LeftLimitPosX);
			player.SetIsRight(true);
			m_RoomChange = false;
		}
		if (m_hp == 0)
		{
			m_Step = STEP_END;
		}
	}
	if (isfade_in && m_hp > 0 && gaze.IsAfterAction()==false 
		&& oiran.IsAfterAction()==false && lie.IsAfterAction()==false && boss.IsAfterAction()==false)
	{
		m_alpha -= m_fade_speed;
		aftMotion = normal;
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
	switch (rooms)
	{
	case Strat_Hall:m_RoomNumber = Hall;
		break;
	case Floor2_Hall:m_RoomNumber = Hall;
		break;
	case Floor2_Hall1:m_RoomNumber = Hall;
		break;
	case Floor2_Hall2:m_RoomNumber = Hall;
		break;
	case Floor2_Hall3:m_RoomNumber = Hall;
		break;
	case Floor2_Corridor:m_RoomNumber = Corridor;
		break;
	case Floor2_Corridor1:m_RoomNumber = Corridor;
		break;
	case Floor2_Corridor2:m_RoomNumber = Corridor;
		break;
	case Floor2_Corridor3:m_RoomNumber = Corridor;
		break;
	case Father_room:
		break;
	case Floor1_Corridorl:m_RoomNumber = Corridor;
		break;
	case Floor1_Hall:m_RoomNumber = Hall;
		break;
	case Workshop:
		break;
	case G_Entrance:m_RoomNumber = Entrance;
		break;
	default:
		break;
	}
}

void InGameScene::InitRand()
{
	int a, b, c, Clear = 0;
	for (int i = 0; i < EnemyMax; i++)
	{
		Gimmick[i] = 0;
		Enemy[i] = 0;
	}
	for (int i = 1; i < 7; i++)
	{
		a = GetRand(GimmickMax);
		b = GetRand(EnemyMax-1);
		c = GetRand(2);
		switch (c)
		{
			case 0:
				if (Gimmick[a] == 0)
				{
					Gimmick[a] = Distance2Gimmick * i;
				}
				else
				{
					i--;
				}
				break;
			case 1:
				if (Enemy[b] == 0)
				{
					Enemy[b] = Distance2Gimmick * i;
				}
				else
				{
					i--;
				}
				break;
			case 2:
				if (Clear == 0)
				{
					m_AmuletPos = Distance2Gimmick * i;
					Clear++;
				}
				else
				{
					i--;
				}
				break;
		default:
			break;
		}
	}
}

void InGameScene::Prologue()
{
	if (Prologue_Run == 0)
	{
		Prologue_Run = 1;
	}
	if (Prologue_Run == 1)
	{
		if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
		{
			Prologue_Run = 2;
		}
	}
}

void InGameScene::Epilogue()
{
	/*if (Epilogue_Run == 0)
	{
		if (inputManager->IsKeyPushed(KEY_INPUT_E))
		{
			Epilogue_Run = 1;
		}
	}*/
	if (Epilogue_Run == 1)
	{
		if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
		{
			Epilogue_Run = 2;
		}
	}
}
