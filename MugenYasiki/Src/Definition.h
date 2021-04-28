#ifndef DEFINITION_H
#define DEFINITION_H

const int WindowHeight = 1000;
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

//ここを変更すると最初の初期座標を変えれます

const int TukiagePosX = 700;		//刀突き上げの初期座標
const int Otiru_katana = 800;		//刀落下の初期座標
const int Shuriken_MoveStart = 900; //手裏剣が動き出す座標
const int ShurikenPosX = 1920;		//手裏剣の初期座標
const int ArrowStartPos = 1920;		//矢の初期スタート値
const int ArrowHeight = 100;		//矢の高さ




//============================

enum SceneID
{
	Title,
	InGame,
	Result,

	SceneMax,
	Scene_Invalid
};

#endif // !DEFINITION_H

