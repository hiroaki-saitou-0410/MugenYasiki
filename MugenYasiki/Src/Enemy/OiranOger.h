#ifndef OIRAN_OGER_H
#define OIRAN_OGER_H

#include"EnemyBase.h"

class OiranOger :public EnemyBase
{
public:
	OiranOger();
	~OiranOger();

	void Exec();
	int GetPosY() { return m_PosY; }
private:
	int m_PosY;
	int m_PosX;
};
#endif // !OIRAN_ogeR_H

