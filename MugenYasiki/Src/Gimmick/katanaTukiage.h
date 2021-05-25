#ifndef KATANA_TUKIAGE_H
#define KATANA_TUKIAGE_H

#include"GimmickDefinition.h"
#include"GimmickBase.h"
#include"DxLib.h"
#include"../Definition.h"

class KatanaTukiage: public GimmickBase
{
public:
	KatanaTukiage();
	~KatanaTukiage();

	void Exec(int x_);
	void Draw(int TexMana, float pi);
	void Init(int x_);
	void IsInit(bool init) { m_PosX = TukiagePosX; m_IsInit = init; }
	int GetPosX() { return m_PosX; }
	bool Collision(int x_,int y_);
	void SetPosY(int posy_) { m_PosY = posy_; }
	void ResettingExec(bool move) { m_IsExec = move; m_IsInit != move; }
	int IsExec() { return m_IsExec; }
	int PushUp() { return IsPushUp; }
	void SetDraw(bool draw) { Draw_katana = draw; }
	

private:
	bool Draw_katana = false;
	bool IsMove = false;
	int m_Appearance;
	const int m_UpSpeed = 25;
	int m_MaxPosY = TextBar_Y - KatanaTextureY + 90;
	bool m_IsExec = false;
	bool m_IsInit = false;
	int InitValue;
	bool IsPushUp = false;

};

#endif // !KATANA_TUKIAGE_H

