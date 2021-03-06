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

	int m_AppearPosX;//SÌo»n
	int m_ExtendPosX;//SÌgkX
	int m_ExtendPosY;//SÌgkY
	int m_Drawtimer; //SÌ\¦Ô
};

#endif // !SCARINGOGRE

