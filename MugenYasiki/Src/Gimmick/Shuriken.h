#ifndef SHURIKEN_H
#define SHURIKEN_H

#include"GimmickBase.h"
#include"../Definition.h"
#include"DxLib.h"

class Shuriken:public GimmickBase
{
public:
	Shuriken();
	~Shuriken();

	void Exec(int x_ ,int y_);

	void Draw(int texture,float pi);

	bool Collision(int x_, int y_);
	int GetPosX() {return m_PosX;}
	int GetPosY() { return m_PosY;}

private:
	int m_DrawTime;

	bool IsDraw = true;
	bool IsMove = false;
	const int m_Speed = 10;
};

#endif // !SHURIKEN_H
