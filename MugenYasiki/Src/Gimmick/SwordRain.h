#ifndef SWORD_RAIN_H
#define SWORD_RAIN_H

#include"GimmickBase.h"
#include"DxLib.h"
#include"GimmickDefinition.h"
#include"../Definition.h"

class SwordRain:public GimmickBase
{
public:
	SwordRain();
	~SwordRain();

	void Exec();
	void Draw(int texture);
	bool Collision(int x_,int y_);
	void SetPosY(int posy_);
	int AppearancePosX() { return m_Appearance;}
	void ResettingExec(bool move){m_IsExec = move; }
	bool IsExec() { return m_IsExec; }
	void Init();

private:
	static const int MaxNumber = WindowWidth/KatanaTextureX;
	int m_PosX[MaxNumber];
	int m_PosY[MaxNumber];
	int m_Speed = 15;
	int m_CoolTime;
	int m_Timer;
	int m_Appearance;
	bool m_IsExec = false;
	bool IsInit = false;
};

#endif // !SWORD_RAIN_H

