#ifndef ACTION_MARK_H
#define ACTION_MARK_H

#include"../Definition.h"

class ActionMark
{
public:
	ActionMark();
	~ActionMark();

	bool CollisionR(int P_Pos,bool IsRight);//右向きに判定する関数
	bool CollisionL(int P_Pos,bool IsRight);//左向きに判定する関数
	bool Collision(int P_Pos,int Target);//左右の有無に関せず判定する関数
private:
	const int m_SearchRange = 50;
};

#endif // !ACTION_MARK_H

