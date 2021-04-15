#ifndef DEFINITION_H
#define DEFINITION_H

const int WindowHeight = 1920;
const int WindowWidth = 1080;

const int AnimationMax = 8;

const int PlayerTexture_X = 155;
const int PlayerTexture_Y = 420;

//�v���C���[�̍����Œ�l
const int  Player_Y = WindowWidth - 700;
//�S�̍��W�ő��
static const int ONI_MAX = 9;
//TextBar��Y���W
const int TextBar_Y = WindowWidth - 283;
//���E�̈ړ�����
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
	bool have_hagoromo;		//�H�߂������Ă��邩
	bool have_candle;		//�낤�����������Ă��邩
	bool have_Scissors;		//�n�T�~�������Ă��邩
	bool have_Japanese_doll;//���{�l�`�������Ă��邩
	bool have_katana;		//���������Ă��邩
	bool have_omamori;		//�����������Ă��邩
	bool have_tamatebako;	//�ʎ蔠�������Ă��邩
	bool have_shuriken;		//�藠���������Ă��邩
	bool have_bomb_doll;	//���e�l�`�������Ă��邩
};

#endif // !DEFINITION_H

