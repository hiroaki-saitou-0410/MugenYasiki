#include "SoundManager.h"

void SoundManager::LoadSceneSound(SceneID sceneid)
{
	switch (sceneid)
	{
	case Title:
		SoundDate[titleSound] = LoadSoundMem("Res/BackGround/Title.mp3");
		break;

	case InGame:
		
		break;

		//case Result:
		//	break;
		//
	default:
		break;
	}
}

void SoundManager::DeleteSceneSound()
{
	for (int i = 0; i < soundMax; i++)
	{
		DeleteSoundMem(SoundDate[i]);
	}
}

int SoundManager::GetSoundDate(int num)
{
	return SoundDate[num];
}

void SoundManager::PlaySceneSound(int num, int playType, int top, int volume)
{
	ChangeNextPlayVolumeSoundMem(volume, num);
	PlaySoundMem(num, playType, top);
}
