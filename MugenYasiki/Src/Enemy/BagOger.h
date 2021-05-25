#ifndef BAG_OGER_H
#define BAG_OGER_H

#include"EnemyBase.h"
#include"DxLib.h"

class BagOger :public EnemyBase
{
public:
	BagOger();
	~BagOger();

	void Exec(int x_);
	void Draw(int texture);
	void Init();
	bool collision(int x_);
	int GetPosY() { return m_PosY; }
	bool IsPlayerDead() { return PlayerKill; }
	void ResettingKill(bool dead) { PlayerKill = dead; }
	void ResettingExec(bool move) { IsExec = move; }
	int QuakingDisply_X() { return m_DisplyPosX; }

private:
	int m_PosY;
	int m_PosX;
	const int m_Speed = 60;

	int m_DisplyPosX;
	int m_QuakePosX;
	int QuakeStop;
	int QuakeSpeed;

	bool PlayerKill = false;
	bool IsExec = false;
	bool IsInit = false;
};

#endif // !BAG_OGER_H

