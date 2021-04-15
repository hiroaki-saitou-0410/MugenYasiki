#ifndef SMALL_OGER_H
#define SMALL_OGER_H

#include"EnemyBase.h"

class SmallOger :public EnemyBase
{
public:
	SmallOger();
	~SmallOger();

	void Exec();
	int GetPosY() { return m_PosY; }
private:
	int m_PosY;
	int m_PosX;
};

#endif // !SMALL_OGER_H

