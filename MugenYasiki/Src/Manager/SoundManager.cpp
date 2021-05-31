#include "SoundManager.h"

void SoundManager::LoadSceneSound(SceneID sceneid)
{
	switch (sceneid)
	{
	case Title:
		SoundDate[titleSound] = LoadSoundMem("Res/Sound/title.mp3");
		break;

	case InGame:
		SoundDate[tiyo_w] = LoadSoundMem("Res/Sound/SE/tiyo_w.mp3");
		SoundDate[tiyo_r] = LoadSoundMem("Res/Sound/SE/tiyo_r.mp3");
		SoundDate[katana_se] = LoadSoundMem("Res/Sound/SE/katana.mp3");
		SoundDate[katana_r] = LoadSoundMem("Res/Sound/SE/katana_r.mp3");
		SoundDate[hit] = LoadSoundMem("Res/Sound/SE/hit.mp3");
		SoundDate[hit_u] = LoadSoundMem("Res/Sound/SE/hit_u.mp3");
		SoundDate[down_1] = LoadSoundMem("Res/Sound/SE/down_1.mp3");
		SoundDate[down_2] = LoadSoundMem("Res/Sound/SE/down_2.mp3");
		SoundDate[down_s] = LoadSoundMem("Res/Sound/SE/down_3.mp3");
		SoundDate[doll_e] = LoadSoundMem("Res/Sound/SE/doll_e.mp3");
		SoundDate[daeki] = LoadSoundMem("Res/Sound/SE/daeki.mp3");
		SoundDate[bodyblow] = LoadSoundMem("Res/Sound/SE/bodyblow.mp3");

		SoundDate[mituketa] = LoadSoundMem("1.あ、見つけた.wav");
		SoundDate[aaaaa] = LoadSoundMem("1.ああああああ！！！！.wav");
		SoundDate[asobimasyo] = LoadSoundMem("1.あーそーびーまーしょー？.wav");
		SoundDate[asobimasyo2] = LoadSoundMem("1.あーそーびーまーしょー？(2).wav");
		SoundDate[arairasyai] = LoadSoundMem("1.あら、いらっしゃい.wav");
		SoundDate[arigatou] = LoadSoundMem("1.ありがとう.wav");
		SoundDate[onna] = LoadSoundMem("1.おんなああああああああ.wav");
		SoundDate[kotti] = LoadSoundMem("1.こっちだよ.wav");
		SoundDate[nani] = LoadSoundMem("1.なに？.wav");
		SoundDate[nannda] = LoadSoundMem("1.なんだ、また俺の餌が来たのか.wav");
		SoundDate[fufufu] = LoadSoundMem("1.ふふふ♡.wav");
		SoundDate[are] = LoadSoundMem("2. あれ？.wav");
		SoundDate[sinitakunai] = LoadSoundMem("2.・・・死にたくない.wav");
		SoundDate[ahaha] = LoadSoundMem("2.あっはっはっはっは！！.wav");
		SoundDate[aha] = LoadSoundMem("2.あはっ.wav");
		SoundDate[sayo] = LoadSoundMem("2.さよ....wav");
		SoundDate[zuttoissyo] = LoadSoundMem("2.ずっと一緒だよ....wav");
		SoundDate[naa] = LoadSoundMem("2.な、なあ！オレ屋敷の出口知ってる！教えてやるから！だから、命だけは！.wav	  ");
		SoundDate[hihi] = LoadSoundMem("2.ひっひ.wav");
		SoundDate[huhuhu] = LoadSoundMem("2.ふふふふふ.wav");
		SoundDate[iyaa] = LoadSoundMem("3.いやああああああ！.wav");
		SoundDate[gaa] = LoadSoundMem("3.がぁっ....wav");
		SoundDate[kyaa] = LoadSoundMem("3.きゃあ！.wav");
		SoundDate[kyahaha] = LoadSoundMem("3.きゃはははは！.wav");
		SoundDate[gomenn] = LoadSoundMem("3.ごめんね.wav");
		SoundDate[taa] = LoadSoundMem("3.たあっ！.wav");
		SoundDate[nannda2] = LoadSoundMem("3.なーんだ.wav");
		SoundDate[arigatoyo] = LoadSoundMem("4.ありがとよ、...ばああか！.wav");
		SoundDate[ittanoni] = LoadSoundMem("4.ずっと一緒だと言ったのに....wav");
		SoundDate[haa] = LoadSoundMem("4.はあっ！.wav");
		SoundDate[hii] = LoadSoundMem("4.ひぃっ.wav");
		SoundDate[zuttoissyo2] = LoadSoundMem("5.ずっと一緒だよ.wav");
		SoundDate[baka] = LoadSoundMem("5.ばああか！.wav");
		SoundDate[fu] = LoadSoundMem("5.ふっ.wav");
		SoundDate[kyahaha2] = LoadSoundMem("6.きゃはははははは！.wav");
		SoundDate[yaa] = LoadSoundMem("6.やあ！.wav");
		SoundDate[turetekorareta] = LoadSoundMem("7.連れてこられた...？.wav");
		SoundDate[onikara] = LoadSoundMem("8.鬼...から.wav");
		SoundDate[e] = LoadSoundMem("9.え....wav");
		SoundDate[masaka] = LoadSoundMem("10.ま、まさか.wav");
		SoundDate[sonna] = LoadSoundMem("11.そんな.wav");
		SoundDate[sonna2] = LoadSoundMem("11.そんな_Ver2.wav");
		SoundDate[kooni] = LoadSoundMem("小鬼（男）パターン１.wav");
		SoundDate[kooni2] = LoadSoundMem("小鬼（男）パターン２.wav");

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
	ChangeVolumeSoundMem(volume, num);
	PlaySoundMem(num, playType, top);
}
