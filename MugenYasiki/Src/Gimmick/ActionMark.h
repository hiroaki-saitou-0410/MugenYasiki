#ifndef ACTION_MARK_H
#define ACTION_MARK_H

#include"../Definition.h"

class ActionMark
{
public:
	ActionMark();
	~ActionMark();

	bool CollisionR(int P_Pos,bool IsRight);//�E�����ɔ��肷��֐�
	bool CollisionL(int P_Pos,bool IsRight);//�������ɔ��肷��֐�
	bool Collision(int P_Pos,int Target);//���E�̗L���Ɋւ������肷��֐�
private:
	const int m_SearchRange = 50;
};

#endif // !ACTION_MARK_H

