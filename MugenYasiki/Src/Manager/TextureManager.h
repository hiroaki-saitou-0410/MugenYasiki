#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Singleton.h"

enum 
{
	Texture,


	textureMax,
};

class TextureManager:public Singleton<TextureManager>
{
public:
	void LoadSceneTexture(SceneID next_);

	void DeleteSceneTexture();

	int GetTextureDate(int num);
private:
	int TextureDate[textureMax];
};

#endif // !TEXTURE_MANAGER_H

