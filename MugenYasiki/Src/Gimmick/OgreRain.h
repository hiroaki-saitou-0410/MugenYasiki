#ifndef OGRE_RAIN_H
#define OGRE_RAIN_H

#include"GimmickDefinition.h"
#include"DxLib.h"
#include"GimmickBase.h"
#include"../Definition.h"

class OgreRain:public GimmickBase
{
public:
	OgreRain();
	~OgreRain();

	void Exec();
	void Draw(int texture);
	bool Collision(int x_,int y_);
	void SetPosY(int posy_);
	int AppearancePosX() { return m_Appearance; }
	bool IsExec(){ return m_IsExec; }
	void ResettingExec(bool move) { m_IsExec = move; }
	void Init();

private:
	static const int MaxNumber = WindowWidth/ OgreRainTextureX + 1;
	int m_PosX[MaxNumber];
	int m_PosY[MaxNumber];
	int m_Appearance;
	const int m_Speed = 15;
	bool m_IsExec=false;
	int IsInit = false;
};

#endif // !OGRE_RAIN_H

