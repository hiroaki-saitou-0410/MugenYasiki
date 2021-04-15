#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include"../Definition.h"

class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	virtual void Exec();

	virtual bool Collision(int x_, int y_, int EnemyPosY, int EnemyTexture_X, int EnemyTexture_Y,int EnemyPosX);

private:
	int m_PosX;

};

#endif // !ENEMY_BASE_H

