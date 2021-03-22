#ifndef DEFINITION_H
#define DEFINITION_H

const int WindowHeight = 1920;
const int WindowWidth = 1080;

//const int WindowHeight =800;
//const int WindowWidth = 600;

const int AnimationMax = 8;

const int PlayerTexture_X = 225;
const int PlayerTexture_Y = 420;

//プレイヤーの高さ固定値
const int  Player_Y = WindowWidth - 700;
//鬼の高さ
const int TUNAGI_Oger_Y = WindowWidth - 750;

enum SceneID
{
	//Title,
	InGame,
	//Result,

	SceneMax,
	Scene_Invalid
};


#endif // !DEFINITION_H

