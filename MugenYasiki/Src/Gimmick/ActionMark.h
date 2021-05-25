#ifndef ACTION_MARK_H
#define ACTION_MARK_H

#include"../Definition.h"

class ActionMark
{
public:
	ActionMark();
	~ActionMark();

	bool CollisionR(int P_Pos,bool IsRight);//‰EŒü‚«‚É”»’è‚·‚éŠÖ”
	bool CollisionL(int P_Pos,bool IsRight);//¶Œü‚«‚É”»’è‚·‚éŠÖ”
	bool Collision(int P_Pos,int Target);//¶‰E‚Ì—L–³‚ÉŠÖ‚¹‚¸”»’è‚·‚éŠÖ”
private:
	const int m_SearchRange = 50;
};

#endif // !ACTION_MARK_H

