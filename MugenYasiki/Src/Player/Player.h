#ifndef PLAYER_H
#define PLAYER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Manager/InputManager.h"
#include"../Scene/InGameScene.h"

//struct Items
//{
//	bool have_hagoromo;		//�H�߂������Ă��邩
//	bool have_candle;		//�낤�����������Ă��邩
//	bool have_Scissors;		//�n�T�~�������Ă��邩
//	bool have_Japanese_doll;//���{�l�`�������Ă��邩
//	bool have_katana;		//���������Ă��邩
//	bool have_omamori;		//�����������Ă��邩
//	bool have_tamatebako;	//�ʎ蔠�������Ă��邩
//	bool have_shuriken;		//�藠���������Ă��邩
//	bool have_bomb_doll;	//���e�l�`�������Ă��邩
//};
//

class Player
{
public:
	Player();
	~Player();

	void Exec();

	int GetPosX() {return m_Posx; }
	int GetHP() { return m_HP; }
	void SetPosX(int x) { m_Posx = x; }
	bool IsStop() { return m_IsStop; }
	bool IsRight() { return m_IsRight; }
	bool ItemGet() { return m_GetItem; }

	bool Collision(int x_, int y_);

private:
	InputManager* inputManager = nullptr;

	int m_Posx;
	int m_HP;
	const int m_Speed = 4;

	bool m_IsAttack = false;
	bool m_GetItem = false;
	bool m_IsRight = true;
	bool m_IsStop = true;
	//bool have_katana = false;
};

#endif // !PLAYER_H

