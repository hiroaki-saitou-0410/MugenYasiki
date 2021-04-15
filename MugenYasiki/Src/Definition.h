#ifndef DEFINITION_H
#define DEFINITION_H

const int WindowHeight = 1920;
const int WindowWidth = 1080;

const int AnimationMax = 8;

const int PlayerTexture_X = 155;
const int PlayerTexture_Y = 420;

//プレイヤーの高さ固定値
const int  Player_Y = WindowWidth - 700;
//鬼の座標最大個数
static const int ONI_MAX = 9;
//TextBarのY座標
const int TextBar_Y = WindowWidth - 283;
//左右の移動制限
const int RightLimitPosX = 1650;
const int LeftLimitPosX = 100;

const int FallStopLimit = 620 - 58;


enum SceneID
{
	Title,
	InGame,
	Result,

	SceneMax,
	Scene_Invalid
};

struct Items
{
	bool have_hagoromo;		//羽衣を持っているか
	bool have_candle;		//ろうそくを持っているか
	bool have_Scissors;		//ハサミを持っているか
	bool have_Japanese_doll;//日本人形を持っているか
	bool have_katana;		//刀を持っているか
	bool have_omamori;		//お守りを持っているか
	bool have_tamatebako;	//玉手箱を持っているか
	bool have_shuriken;		//手裏剣を持っているか
	bool have_bomb_doll;	//爆弾人形を持っているか
};

#endif // !DEFINITION_H

