#ifndef DEFINITION_H
#define DEFINITION_H

const int WindowHeight = 1080;
const int WindowWidth = 1920;

const int AnimationMax = 8;

const int PlayerTexture_X = 155;
const int PlayerTexture_Y = 420;

//プレイヤーの高さ固定値
const int  Player_Y = WindowHeight - 700;
//鬼の座標最大個数
static const int ONI_MAX = 9;
//TextBarのY座標
const int TextBar_Y = WindowHeight - 283;
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

#endif // !DEFINITION_H

