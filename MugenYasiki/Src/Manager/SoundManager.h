#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Singleton.h"

enum
{
	titleSound,
	tiyo_w,
	tiyo_r,
	katana_se,
	katana_r,
	hit,
	hit_u,
	down_1,
	down_2,
	down_s,
	doll_e,
	daeki,
	bodyblow,

	mituketa,
	aaaaa,
	asobimasyo,
	asobimasyo2,
	arairasyai,
	arigatou,
	onna,
	kotti,
	nani,
	nannda,
	fufufu,
	are,
	sinitakunai,
	ahaha,
	aha,
	sayo,
	zuttoissyo,
	naa,
	hihi,
	huhuhu,
	iyaa,
	gaa,
	kyaa,
	kyahaha,
	gomenn,
	taa,
	nannda2,
	arigatoyo,
	ittanoni,
	haa,
	hii,
	zuttoissyo2,
	baka,
	fu,
	kyahaha2,
	yaa,
	turetekorareta,
	onikara,
	e,
	masaka,
	sonna,
	sonna2,
	kooni,
	kooni2,

	soundMax,
};

class SoundManager :public Singleton<SoundManager>
{
public:
	void LoadSceneSound(SceneID next_);

	void DeleteSceneSound();

	int GetSoundDate(int num);

	void PlaySceneSound(int num, int playType, int top, int volume);
private:
	int SoundDate[soundMax];
};

#endif // !SOUND_MANAGER_H

