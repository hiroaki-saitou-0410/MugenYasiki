#ifndef AMULET_H
#define AMULET_H

#include"DxLib.h"
#include"Item_Definition.h"

class Amulet
{
public:
	Amulet();
	~Amulet();

	void Exec(bool itemGet);
	void ActExec();
	void Draw(int texture, int item, int itemframe, int clearBlack);
	bool Status() { return m_IsGet; }
	bool IsDraw() { return m_IsDraw; }

	void ItemBar(int texture, int itemframe, bool haveAmulet);
	int GetPosX() { return m_PosX; }
	void IsExplain(bool explain) { m_IsGet = explain; }
	void ResettingDraw(bool draw) { m_IsDraw = draw; }
private:
	bool m_IsGet = false;
	bool m_IsDraw = false;
	//bool Righting

	int m_PosX;
	int m_PosY;
};

#endif // !AMULET_H

