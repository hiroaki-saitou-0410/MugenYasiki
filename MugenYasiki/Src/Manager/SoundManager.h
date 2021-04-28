#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Singleton.h"

enum
{
	titleSound,

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

