#ifndef SCISSORS_H
#define SCISSORS_H

#include"DxLib.h"
#include"Item_Definition.h"

class Scissors
{
public:
	Scissors();
	~Scissors();

	void Exec(bool itemGet);
	void ActExec();
	void Draw(int texture,int item,int itemframe,int clearBlack,bool haveScissors);
	void ItemBar(int texture, int itemframe, bool haveScissors);

	int GetPosX() { return m_PosX; }
	void IsExplain(bool explain) { IsGet = explain; }
	int  StopCollision() {return IsStopCollision;}
private:
	bool IsGet = false;
	bool IsStopCollision = false;
	int m_PosX;
	int m_PosY;
	int m_Time;
	const int m_Maxtime=120;
};
#endif // !SCISSORS_H

