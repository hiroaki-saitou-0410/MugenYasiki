#ifndef SHURIKEN_H
#define SHURIKEN_H

#include"GimmickBase.h"
#include"../Definition.h"

class Shuriken:public GimmickBase
{
public:
	Shuriken();
	~Shuriken();

	void Exec(int x_ ,int y_);
	bool Collision(int x_, int y_);
	int GetPosX() {return m_PosX;}
	int GetPosY() { return m_PosY;}

	bool IsDraw(){ return Draw; };
private:
	bool Draw=true;
	bool IsMove = false;
	const int m_Speed = 10;
};

#endif // !SHURIKEN_H
