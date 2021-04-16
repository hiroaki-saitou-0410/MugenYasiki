#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Singleton.h"

enum 
{
	tunagi_Ogre,
	oiran_Ogre,
	bag_Ogre,
	small_Ogre1,
	small_Ogre2,
	peep_Ogre,
	gaze_Ogre,
	lie_Ogre,
	crawling_Ogre,

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

	TextBar,
	CharacterTextBar0,
	CharacterTextBar1,
	CharacterTextBar2,
	CharacterTextBar3,

	titleTexture0,
	titleTexture1,
	titleTexture2,

	BackGround0,
	BackGround1,
	BackGround2,
	BackGround3,

	trap_Katana,
	trap_Shuriken,

	item_candle,
	item_hagoromo,
	item_Scissors,
	item_Japanese_doll,

	Mark,

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
	int TextureDateArray[AnimationMax];
};

#endif // !TEXTURE_MANAGER_H

