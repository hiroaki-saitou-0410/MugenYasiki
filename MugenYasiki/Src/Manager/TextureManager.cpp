#include"TextureManager.h"

void TextureManager::LoadSceneTexture(SceneID sceneid)
{
	switch (sceneid)
	{
	//case Texture:
	//	break;

	case InGame:
		//textureDate[texture] = LoadGraph("ファイルパス");

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