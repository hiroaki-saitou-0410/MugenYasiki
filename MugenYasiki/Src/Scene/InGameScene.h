#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include"DxLib.h"
#include"SceneBase.h"
#include"../Manager/GameManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/SceneManager.h"
#include"../Manager/TextureManager.h"
#include"../Manager/SoundManager.h"

#include"../Player/Player.h"

#include"../Enemy/EnemyBase.h"
#include"../Enemy/TunagiOger.h"
#include"../Enemy/BagOger.h"
#include"../Enemy/GazeOger.h"
#include"../Enemy/OiranOger.h"
#include"../Enemy/PeepOger.h"
#include"../Enemy/SmallOger.h"

#include"../Item/Item.h"

#include"../Gimmick/ActionMark.h"
#include"../Gimmick/Katana.h"
#include"../Gimmick/Shuriken.h"
#include"../Gimmick/katanaTukiage.h"

enum MoveType
{
	stop_R,
	stop_L,
	move_R,
	move_L,
	jamp,
}; 

enum Rooms
{
	Strat_Hall = 10,
	Floor2_Hall,
	Floor2_Hall1,
	Floor2_Hall2,
	Floor2_Hall3,
	Floor2_Corridor,
	Floor2_Corridor1,
	Floor2_Corridor2,
	Floor2_Corridor3,

	Father_room = 20,
	Floor1_Corridorl,
	Floor1_Hall,
	Workshop,
	G_Entrance,

};

class InGameScene :public SceneBase
{
public:
	InGameScene();
	~InGameScene();

public:
	void Exec();
	void Draw();
	void GimmickExec();
	void EnemyExec();

	void GimmickDraw();
	void EnemyDraw();

	virtual bool IsEnd()const;

	void Step_Pause();
	void Step_Input();
	void Fade(Katana katana);
	void Animation();
	void RoomChange();

private:
	GameManager* gamenManager = nullptr;
	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;
	SoundManager* soundManager = nullptr;
	MoveType moveType = stop_R;
	Rooms rooms = Strat_Hall;
	//bool IsCollision(int Aposx_, int Aposy_, int Bposx_, int Bposy_, int Awidth, int Aheight, int Bwidth, int Bheight);

	bool FinishedScene =false;
	bool Pause;
	bool isfade_in = false;
	bool after_acti = false;
	bool dead = false;
	bool m_RoomChange = false;

	int m_hp;
	int m_alpha = 0;
	int m_fade_speed = 2;
	int m_RoomNumber;
	int m_ActStop;
	int m_MoveIndex;
	int m_ActSpeed;
	int m_RightMotionMax;
	int m_LeftMotionMax;
	int m_OgreNumber;
	int m_ItemNumber;
	int EnemyPosX[ONI_MAX] = { 1400,1400,1400,1400,1400,1400,1400,1400,1400};
	int EnemyPosY[ONI_MAX] = {122,220,290,517,517,525,525,275,285};
	int EnemyTexture_X[ONI_MAX] = {491,408,432,198,198,198,198,758,411};
	int EnemyTexture_Y[ONI_MAX] = {673,578,510,278,278,278,278,523,514};
};

#endif // !INGAMESCENE_H
