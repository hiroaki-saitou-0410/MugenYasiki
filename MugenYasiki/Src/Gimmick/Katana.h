#ifndef KATANA_H
#define KATANA_H

#include"GimmickBase.h"
#include"GimmickDefinition.h"
#include"DxLib.h"
#include"../Definition.h"

class Katana:public GimmickBase
{
public:
	Katana();
	~Katana();

	void Exec(int x_);
	void Draw(int texture);
	void Init(int x_);
	bool Collision(int x_,int y_);

	int GetPosX() { return m_PosX; }
	int GetPosY() { return m_PosY; }
	void SetPosY(int posy_) { m_PosY = posy_; }
	void SetDisplayKatana(bool a) { Draw_katana != a; }

	bool AfterAction() { return after_acti; }
	bool IsDraw() { return Draw_katana; }
	bool IsFall() { return fall; }
	void ResettingExec(bool move) { m_IsExec = move; IsInit != move; }
	int IsExec() { return m_IsExec; }
	void FullReset();

private:
	bool after_acti = false;
	bool Draw_katana = false;
	bool fall = false;
	bool IsInit = false;
	const int m_fall_speed = 25;
	int m_MaxPosY;
	int InitValue;
	bool m_IsExec = false;
};

#endif // !KATANA_H

