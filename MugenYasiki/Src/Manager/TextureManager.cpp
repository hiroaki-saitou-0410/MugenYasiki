#include"TextureManager.h"
#include"../Player/Player.h"

static Player player;

void TextureManager::LoadSceneTexture(SceneID sceneid)
{
	switch (sceneid)
	{
	//case Title:
	//	break;

	case InGame:
		TextureDate[texture0] = LoadGraph("Res/Enemy/tunagi_ogre.png");
		TextureDate[texture1] = LoadGraph("Res/BackGround/Background.jpg");
		TextureDate[texture2] = LoadGraph("Res/TextBar/text_bar.png");
		TextureDate[texture3] = LoadGraph("Res/TextBar/bar_normal.png");
		TextureDate[texture4] = LoadGraph("Res/TextBar/bar_frighte.png");
		TextureDate[left_stop] = LoadGraph("Res/Player/character_left_stop.png");//player
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
		break;

	//case Result:
	//	break;

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

