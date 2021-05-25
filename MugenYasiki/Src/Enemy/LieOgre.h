#ifndef LIE_OGRE
#define LIE_OGRE

#include"EnemyBase.h"
#include"DxLib.h"

class LieOgre:public EnemyBase
{
public:
	LieOgre();
	~LieOgre();

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

#endif // !LIE_OGRE

