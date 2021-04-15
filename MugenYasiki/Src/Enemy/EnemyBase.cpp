#include"EnemyBase.h"

EnemyBase::EnemyBase()
{
	
}

EnemyBase::~EnemyBase()
{

}

void EnemyBase::Exec()
{

}

bool EnemyBase::Collision(int x_, int y_, int EnemyPosY, int EnemyTexture_X, int EnemyTexture_Y, int EnemyPosX)	//y_=Player_Y,eY=EnemyPosY[number],int EnemyTexture_Y
{
	if ((x_ + PlayerTexture_X) > EnemyPosX && x_ < EnemyPosX + EnemyTexture_X)
	{
		if ((y_ + PlayerTexture_Y > EnemyPosY && y_ < EnemyPosY + EnemyTexture_Y))
		{
			return true;
		}
	}
	return false;
}
