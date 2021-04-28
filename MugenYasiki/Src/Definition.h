#ifndef DEFINITION_H
#define DEFINITION_H

const int WindowHeight = 1000;
const int WindowWidth = 1920;

const int AnimationMax = 8;

const int PlayerTexture_X = 155;
const int PlayerTexture_Y = 420;

//�v���C���[�̍����Œ�l
const int  Player_Y = WindowHeight - 700;
//�S�̍��W�ő��
static const int ONI_MAX = 9;
//TextBar��Y���W
const int TextBar_Y = WindowHeight - 283;
//���E�̈ړ�����
const int RightLimitPosX = 1650;
const int LeftLimitPosX = 100;

const int FallStopLimit = 620 - 58;

//������ύX����ƍŏ��̏������W��ς���܂�

const int TukiagePosX = 700;		//���˂��グ�̏������W
const int Otiru_katana = 800;		//�������̏������W
const int Shuriken_MoveStart = 900; //�藠���������o�����W
const int ShurikenPosX = 1920;		//�藠���̏������W
const int ArrowStartPos = 1920;		//��̏����X�^�[�g�l
const int ArrowHeight = 100;		//��̍���




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

