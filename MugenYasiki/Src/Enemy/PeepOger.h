#ifndef PEEP_OGER_H
#define PEEP_OGER_H

#include"EnemyBase.h"

class PeepOger :public EnemyBase
{
public:
	PeepOger();
	~PeepOger();

	void Exec();
	int GetPosY() { return m_PosY; }
private:
	int m_PosY;
	int m_PosX;
};

#endif // !PEEP_OGER_H

