#ifndef TUNAGI_OGER_H
#define TUNAGI_OGER_H

#include"EnemyBase.h"
#include"../Definition.h"

class TunagiOger:public EnemyBase
{
public:
	TunagiOger();
	~TunagiOger();

	void Exec();
	int GetPosY() { return m_PosY; }
private:
	int m_PosY;
	int m_PosX;
};

#endif
