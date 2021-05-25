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
	boss_Ogre,

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
	Entrance,
	Corridor,
	Hall,

	trap_Katana,
	trap_Shuriken,
	trap_arrow,
	gaze_eye,
	oiran_smoku,
	lie_wet,
	boss_blood,
	flontPeepOgre,
	flontGazeOgre,


	item_candle,
	item_hagoromo,
	item_Scissors,
	item_Japanese_doll,
	item_Amulet,
	item_Amulet_light,
	item_diary,

	item_Get_Scissors,
	item_Get_Japanese_doll,
	item_Get_hagoromo,
	item_Get_Amulet,
	item_Get_diary,
	item_Get_itemframe,

	explosion1,
	explosion2,
	explosion3,
	explosion4,
	explosion5,
	explosion6,
	explosion7,
	explosion8,
	explosion9,
	explosion10,
	explosion11,

	Mark,
	ClearBlack,

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

