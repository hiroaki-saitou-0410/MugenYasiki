#ifndef PEEP_OGER_H
#define PEEP_OGER_H

#include"EnemyBase.h"
#include"DxLib.h"

class PeepOger :public EnemyBase
{
public:
	PeepOger();
	~PeepOger();

	void Exec();
	void Draw(int texture,int x_);
	void Init();
	int GetPosY() { return m_PosY; }
	void ResettingExec(bool move) { IsExec = move; }

private:
	int m_PosY;

	int m_Index;
	int m_ActStop;
	int m_ActSpeed;
	int m_MotionMax;
	const int ShiftPosX = 150;

	bool IsExec = false;
	bool IsInit = false;
};

#endif // !PEEP_OGER_H

