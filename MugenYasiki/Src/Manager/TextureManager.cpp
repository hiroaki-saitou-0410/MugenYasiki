#include"TextureManager.h"

void TextureManager::LoadSceneTexture(SceneID sceneid)
{
	switch (sceneid)
	{
	case Title:
		TextureDate[titleTexture0] = LoadGraph("Res/BackGround/Title1.jpg");
		TextureDate[titleTexture1] = LoadGraph("Res/BackGround/Title2.jpg");
		TextureDate[titleTexture2] = LoadGraph("Res/BackGround/Title3.jpg");
		break;

	case InGame:
		//BackGround
		TextureDate[BackGround0] = LoadGraph("Res/BackGround/Background.jpg");
		TextureDate[Entrance] = LoadGraph("Res/BackGround/Entrance.jpg");//玄関
		TextureDate[Corridor] = LoadGraph("Res/BackGround/Corridor.jpg");//廊下
		TextureDate[Hall] = LoadGraph("Res/BackGround/Hall.jpg");	//広間

		//textBar
		TextureDate[TextBar] = LoadGraph("Res/TextBar/text_bar.png");
		TextureDate[CharacterTextBar0] = LoadGraph("Res/TextBar/bar_normal.png");
		TextureDate[CharacterTextBar1] = LoadGraph("Res/TextBar/bar_frighte.png");
		TextureDate[CharacterTextBar2] = LoadGraph("Res/TextBar/bar_puzzled.png");

		//player
		TextureDate[left_stop] = LoadGraph("Res/Player/character_left_stop.png");
		TextureDate[left_Animation0] = LoadGraph("Res/Player/character_left_1.png");//アニメーション：左
		TextureDate[left_Animation1] = LoadGraph("Res/Player/character_left_2.png");
		TextureDate[left_Animation2] = LoadGraph("Res/Player/character_left_3.png");
		TextureDate[left_Animation3] = LoadGraph("Res/Player/character_left_4.png");
		TextureDate[left_Animation4] = LoadGraph("Res/Player/character_left_5.png");
		TextureDate[left_Animation5] = LoadGraph("Res/Player/character_left_6.png");
		TextureDate[left_Animation6] = LoadGraph("Res/Player/character_left_7.png");
		TextureDate[left_Animation7] = LoadGraph("Res/Player/character_left_8.png");//-------
		TextureDate[right_stop] = LoadGraph("Res/Player/character_right_stop.png");
		TextureDate[right_Animation0] = LoadGraph("Res/Player/character_right_1.png");//アニメーション：右
		TextureDate[right_Animation1] = LoadGraph("Res/Player/character_right_2.png");
		TextureDate[right_Animation2] = LoadGraph("Res/Player/character_right_3.png");
		TextureDate[right_Animation3] = LoadGraph("Res/Player/character_right_4.png");
		TextureDate[right_Animation4] = LoadGraph("Res/Player/character_right_5.png");
		TextureDate[right_Animation5] = LoadGraph("Res/Player/character_right_6.png");
		TextureDate[right_Animation6] = LoadGraph("Res/Player/character_right_7.png");
		TextureDate[right_Animation7] = LoadGraph("Res/Player/character_right_8.png");//------
		TextureDate[Mark] = LoadGraph("Res/Item/ActionMark.png");

		//Trap
		TextureDate[trap_Katana] = LoadGraph("Res/Trap/katana2.png");
		TextureDate[trap_Shuriken] = LoadGraph("Res/Trap/Shuriken.png");
		TextureDate[trap_arrow] = LoadGraph("Res/Trap/arrow.png");
		TextureDate[gaze_eye] = LoadGraph("Res/Enemy/ogre_gimmick/eye.png");
		TextureDate[oiran_smoku] = LoadGraph("Res/Enemy/ogre_gimmick/kemukemu.png");
		TextureDate[lie_wet] = LoadGraph("Res/Enemy/ogre_gimmick/sitosito.png");
		TextureDate[boss_blood] = LoadGraph("Res/Enemy/ogre_gimmick/bosu_blooddroplets.png");
		TextureDate[flontPeepOgre] = LoadGraph("Res/Enemy/ogre_gimmick/PeepOgre2.png");
		TextureDate[flontGazeOgre] = LoadGraph("Res/Enemy/ogre_gimmick/GazeOgrer2.png");


		//Item
		TextureDate[item_candle] = LoadGraph("Res/Item/Candle.png");
		TextureDate[item_hagoromo] = LoadGraph("Res/Item/Hagoromo.png");
		TextureDate[item_Scissors] = LoadGraph("Res/Item/Scissors.png");
		TextureDate[item_Japanese_doll] = LoadGraph("Res/Item/Japanese_doll.png");
		TextureDate[item_Amulet] = LoadGraph("Res/Item/amulet.png");
		TextureDate[item_Amulet_light] = LoadGraph("Res/Item/amulet_light.png");
		TextureDate[item_diary] = LoadGraph ("Res/Item/diary.png");

		//Get Item
		TextureDate[item_Get_Scissors] = LoadGraph("Res/Item/Get_Item/scissors.png");
		TextureDate[item_Get_Japanese_doll] = LoadGraph("Res/Item/Get_Item/japanesedoll.png");
		TextureDate[item_Get_hagoromo] = LoadGraph("Res/Item/Get_Item/cloth.png");
		TextureDate[item_Get_Amulet] = LoadGraph("Res/Item/Get_Item/amulet.png");
		TextureDate[item_Get_diary] = LoadGraph("Res/Item/Get_Item/diary.png");
		TextureDate[item_Get_itemframe] = LoadGraph("Res/Item/Get_Item/itemframe.png");

		TextureDate[ClearBlack] = LoadGraph("Res/Item/Get_Item/ClearBlack.png");

		//Explosion
		TextureDate[explosion1] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion1.png");
		TextureDate[explosion2] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion2.png");
		TextureDate[explosion3] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion3.png");
		TextureDate[explosion4] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion4.png");
		TextureDate[explosion5] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion5.png");
		TextureDate[explosion6] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion6.png");
		TextureDate[explosion7] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion7.png");
		TextureDate[explosion8] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion8.png");
		TextureDate[explosion9] =  LoadGraph("Res/Item/Get_Item/Explosion/explosion9.png");
		TextureDate[explosion10] = LoadGraph("Res/Item/Get_Item/Explosion/explosion10.png");
		TextureDate[explosion11] = LoadGraph("Res/Item/Get_Item/Explosion/explosion11.png");

		//Enemy
		TextureDate[tunagi_Ogre] = LoadGraph("Res/Enemy/tunagi_ogre.png");
		TextureDate[oiran_Ogre] = LoadGraph("Res/Enemy/oiran_ogre.png");  
		TextureDate[bag_Ogre] = LoadGraph("Res/Enemy/Bag_ogre.png");	  
		TextureDate[small_Ogre1] = LoadGraph("Res/Enemy/small_ogre1.png");
		TextureDate[small_Ogre2] = LoadGraph("Res/Enemy/small_ogre2.png");
		TextureDate[peep_Ogre] = LoadGraph("Res/Enemy/Peep_ogre.png");	  
		TextureDate[gaze_Ogre] = LoadGraph("Res/Enemy/Gaze_ogre.png");	  
		TextureDate[lie_Ogre] = LoadGraph("Res/Enemy/Lie_ogre.png");
		TextureDate[crawling_Ogre]= LoadGraph("Res/Enemy/Crawling_Ogre.png");
		TextureDate[boss_Ogre]= LoadGraph("Res/Enemy/boss.png");
		break;
		
	//case Result:
	//	break;
	//
	default:
		break;
	}
}

void TextureManager::DeleteSceneTexture()
{
	for (int i = 0; i < textureMax; i++)
	{
		DeleteGraph(TextureDate[i]);
	}
}

int TextureManager::GetTextureDate(int num)
{
	return TextureDate[num];
}

