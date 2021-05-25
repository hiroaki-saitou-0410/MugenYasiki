#ifndef GAZE_OGER_H
#define GAZE_OGER_H

#include"EnemyBase.h"
#include"DxLib.h"
#include"OgreDefinition.h"

class GazeOger :public EnemyBase
{
public:
	GazeOger();
	~GazeOger();

	void Exec();
	void Draw(int texture,int x_);
	void AfterAction(int texture);
	int GetPosY() { return m_PosY; }
	void Init();
	void ResettingExec(bool move_) { m_IsExec = move_;}
	void ResettingKill(bool dead_){ PlayerKill = dead_;}
	bool IsPlayerDead() { return PlayerKill;}
	void ResettingAction(bool InitAct) { AfterAct = InitAct; }
	bool IsAfterAction() { return AfterAct; }
	bool IsExec() { return m_IsExec; }

private:
	int m_PosY;

	int m_Index;
	int m_ActStop;
	int m_ActSpeed;
	int m_MotionMax;
	int m_ActTime;
	int m_DrawTime;
	bool PlayerKill;
	bool m_IsExec = false;
	bool IsInit = false;
	bool AfterAct = false;
};

#endif // !1
