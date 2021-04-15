#ifndef BAG_OGER_H
#define BAG_OGER_H

#include"EnemyBase.h"

class BagOger :public EnemyBase
{
public:
	BagOger();
	~BagOger();

	void Exec();
	int GetPosY() { return m_PosY; }
private:
	int m_PosY;
	int m_PosX;
};

#endif // !BAG_OGER_H

