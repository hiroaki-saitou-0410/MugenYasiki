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
		TextureDate[BackGround1] = LoadGraph("Res/BackGround/Entrance.jpg");
		TextureDate[BackGround2] = LoadGraph("Res/BackGround/Corridor.jpg");
		TextureDate[BackGround3] = LoadGraph("Res/BackGround/Hall.jpg");

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

		//Item
		TextureDate[item_candle] = LoadGraph("Res/Item/Candle.png");
		TextureDate[item_hagoromo] = LoadGraph("Res/Item/Hagoromo.png");
		TextureDate[item_Scissors] = LoadGraph("Res/Item/Scissors.png");
		TextureDate[item_Japanese_doll] = LoadGraph("Res/Item/Japanese_doll.png");

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

