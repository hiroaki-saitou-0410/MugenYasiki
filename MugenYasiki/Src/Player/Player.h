#ifndef PLAYER_H
#define PLAYER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Manager/InputManager.h"
#include"../Scene/InGameScene.h"
#include"../Base.h"
#include"../Manager/SoundManager.h"

struct Items
{
public:
	bool have_hagoromo=false;		//�H�߂������Ă��邩
	bool have_candle = false;		//�낤�����������Ă��邩
	bool have_Scissors = false;		//�n�T�~�������Ă��邩
	bool have_Japanese_doll = false;//���{�l�`�������Ă��邩
	bool have_katana = false;		//���������Ă��邩
	bool have_omamori = false;		//�����������Ă��邩
	bool have_tamatebako = false;	//�ʎ蔠�������Ă��邩
	bool have_shuriken = false;		//�藠���������Ă��邩
	bool have_bomb_doll = false;	//���e�l�`�������Ă��邩
};

class Player:public Base
{
public:
	Player();
	~Player();

	void Exec();
	bool Collision(int x_, int y_);
	void Jump();

	int GetPosX() {return m_PosX; }
	int GetPosY() { return m_PosY;}
	int GetHP() { return m_HP; }
	void SetPosX(int x) { m_PosX = x; }
	bool IsStop() { return m_IsStop; }
	bool IsRight() { return m_IsRight; }
	void SetIsRight(bool isRught) { m_IsRight = isRught; }
	bool ItemGet() { return m_GetItem; }
	bool IsDecision() { return m_IsDecision; }

	void Sound();

	Items items;
private:
	InputManager* inputManager = nullptr;
	SoundManager* soundManager = nullptr;

	int m_PosX;
	int m_PosY;
	int m_HP;
	float m_Gravity;
	int m_Vector;
	const int m_Speed = 4;

	bool m_IsDecision = false;
	bool m_IsTouchingRoom = true;
	bool m_IsAttack = false;
	bool m_GetItem = false;
	bool m_IsRight = true;
	bool m_IsStop = true;
};

#endif // !PLAYER_H

