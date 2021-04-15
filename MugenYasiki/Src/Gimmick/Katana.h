#ifndef KATANA_H
#define KATANA_H

#include"GimmickBase.h"
#include"../Definition.h"

class Katana:public GimmickBase
{
public:
	Katana();
	~Katana();

	void Exec(int x_, int y_);
	bool Collision(int x_,int y_);

	int GetPosX() { return m_PosX; }
	int GetPosY() { return m_PosY; }

	bool AfterAction() { return after_acti; }
	bool IsDraw() { return Draw_katana; }
	bool IsFall() { return fall; }


private:
	bool after_acti = false;
	bool Draw_katana = true;
	bool fall = false;
	int m_PosX= 800;
	int m_PosY= 0;
	int m_fall_speed = 5;
};

#endif // !KATANA_H

