#ifndef TUNAGI_OGER_H
#define TUNAGI_OGER_H

#include"EnemyBase.h"
#include"../Definition.h"
#include"DxLib.h"

class TunagiOger:public EnemyBase
{
public:
	TunagiOger();
	~TunagiOger();

	void Exec();
	void Draw(int texture,int x_);
	void Init();
	void Animation();
	int GetPosY() { return m_PosY; }
	int GetIndex() { return m_Index; }
	int QuakingDisply() { return m_DisplyPosY; }
	void ResettingExec(bool move) { IsExec = move;}
	void ResettingKill(bool dead) { PlayerKill = dead; }
	int GetMotionIndex() { return m_Index; }
	bool IsPlayerDead() { return PlayerKill; }
	
private:
	int m_PosY;
	int m_PosX;

	int m_Index;
	int m_ActStop;
	int m_ActSpeed;
	int m_MotionMax;
	int m_DisplyPosY;
	int m_QuakePosY;
	int QuakeStop;
	int QuakeSpeed;
	bool PlayerKill = false;
	bool IsExec =false;
	bool IsInit = false;
};

#endif
