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
	void Draw(int texture, int item, int itemframe, int clearBlack, bool haveAmulet);
	void ItemBar(int texture, int itemframe, bool haveAmulet);

	int GetPosX() { return m_PosX; }
	void IsExplain(bool explain) { IsGet = explain; }
private:
	bool IsGet = false;
	//bool Righting

	int m_PosX;
	int m_PosY;
};

#endif // !AMULET_H

