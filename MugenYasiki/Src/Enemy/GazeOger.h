#ifndef GAZE_OGER_H
#define GAZE_OGER_H

#include"EnemyBase.h"

class GazeOger :public EnemyBase
{
public:
	GazeOger();
	~GazeOger();

	void Exec();
	int GetPosY() { return m_PosY; }

private:
	int m_PosY;
	int m_PosX;
};

#endif // !1
