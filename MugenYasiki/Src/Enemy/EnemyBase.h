#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include"../Definition.h"
#include"../Base.h"

class EnemyBase:public Base
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	virtual void Exec();

	virtual bool Collision(int x_, int y_, int EnemyPosY, int EnemyTexture_X, int EnemyTexture_Y,int EnemyPosX);

protected:
	int m_PosX;
	int m_TextureX;
	int m_TextureY;
};

#endif // !ENEMY_BASE_H

