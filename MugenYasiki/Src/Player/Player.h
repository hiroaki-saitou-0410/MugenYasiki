#ifndef PLAYER_H
#define PLAYER_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Manager/InputManager.h"
#include"../Scene/InGameScene.h"

//struct Items
//{
//	bool have_hagoromo;		//羽衣を持っているか
//	bool have_candle;		//ろうそくを持っているか
//	bool have_Scissors;		//ハサミを持っているか
//	bool have_Japanese_doll;//日本人形を持っているか
//	bool have_katana;		//刀を持っているか
//	bool have_omamori;		//お守りを持っているか
//	bool have_tamatebako;	//玉手箱を持っているか
//	bool have_shuriken;		//手裏剣を持っているか
//	bool have_bomb_doll;	//爆弾人形を持っているか
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

