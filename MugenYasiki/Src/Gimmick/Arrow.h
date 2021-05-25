#ifndef ARROW_H
#define ARROW_H

#include"GimmickBase.h"
#include"DxLib.h"
#include"GimmickDefinition.h"
#include"../Definition.h"

class Arrow:public GimmickBase
{
public:
	Arrow();
	~Arrow();

	void Exec(int x_);
	void Draw(int texture);
	bool Collision(int x_,int y_);

private:
	bool IsDraw;
	bool IsMove;

	int m_StopPosX;
	const int m_Speed=10;
};

#endif // !ARROW_H

