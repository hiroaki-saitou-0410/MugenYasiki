#ifndef OIRAN_OGER_H
#define OIRAN_OGER_H

#include"EnemyBase.h"
#include"DxLib.h"

class OiranOger :public EnemyBase
{
public:
	OiranOger();
	~OiranOger();

	void Exec();
	void Draw(int texture,int x_);
	void AfterAction(int texture);
	void Init();
	void ResettingExec(bool move) { m_IsExec = move; }
	void ResettingKill(bool dead) { PlayerKill = dead; }
	bool IsPlayerDead() { return PlayerKill; }
	int GetPosY() { return m_PosY; }
	void ResettingAction(bool InitAct) { AfterAct = InitAct; }
	bool IsAfterAction() { return AfterAct; }
	bool IsExec() { return m_IsExec; }
private:

	bool PlayerKill = false;
	bool m_IsExec = false;
	bool IsInit = false;
	bool AfterAct = false;
	int m_DrawTime;
	int m_ActTime;
};
#endif // !OIRAN_ogeR_H

