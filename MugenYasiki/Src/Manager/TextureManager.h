#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Singleton.h"

enum 
{
	texture0,
	texture1,
	texture2,
	texture3,
	texture4,
	left_stop,
	left_Animation0,
	left_Animation1,
	left_Animation2,
	left_Animation3,
	left_Animation4,
	left_Animation5,
	left_Animation6,
	left_Animation7,
	right_stop,
	right_Animation0,
	right_Animation1,
	right_Animation2,
	right_Animation3,
	right_Animation4,
	right_Animation5,
	right_Animation6,
	right_Animation7,

	textureMax,
};

class TextureManager:public Singleton<TextureManager>
{
public:
	void LoadSceneTexture(SceneID next_);

	void DeleteSceneTexture();

	int GetTextureDate(int num);
	int GetTextureDateArray(int num[]);
private:
	int TextureDate[textureMax];
	int TextureDateArray[AnimationMax];
};

#endif // !TEXTURE_MANAGER_H

