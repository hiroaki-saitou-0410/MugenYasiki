#ifndef SCARINGOGRE
#define SCARINGOGRE

#include"GimmickBase.h"
//#include"ActionMark.h"
#include"DxLib.h"
#include"GimmickDefinition.h"
#include"../Manager/InputManager.h"

class ScaringOgre:public GimmickBase
{
public:
	ScaringOgre();
	~ScaringOgre();

	void Exec();
	void Draw(int texture);
	bool Collision(int x_,int y_);
	int GetAppearPosX() {return  m_AppearPosX; }
	void ResettingExec(bool a) { IsExec = a; }

private:
	InputManager* inputManager = nullptr;
	bool IsDraw = false;
	bool IsExec = false;

	int m_AppearPosX;//ãSÇÃèoåªín
	int m_ExtendPosX;//ãSÇÃägèkX
	int m_ExtendPosY;//ãSÇÃägèkY
	int m_Drawtimer; //ãSÇÃï\é¶éûä‘
};

#endif // !SCARINGOGRE

