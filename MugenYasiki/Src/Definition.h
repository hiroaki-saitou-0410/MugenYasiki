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
static const int ONI_MAX = 8;
//TextBarのY座標
const int TextBar_Y = WindowHeight - 283;
//左右の移動制限
const int RightLimitPosX = 1650;
const int LeftLimitPosX = 100;

const int MarkDrawX = 41;
const int Distance2Gimmick = 250;

const int ItemMax = 4;
const int GimmickMax = 4;
const int EnemyMax = 6;

enum SceneID
{
	Title,
	InGame,
	Result,

	SceneMax,
	Scene_Invalid
};

#endif // !DEFINITION_H

