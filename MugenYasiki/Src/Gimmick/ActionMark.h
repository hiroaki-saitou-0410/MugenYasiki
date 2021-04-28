#ifndef ACTION_MARK_H
#define ACTION_MARK_H

#include"../Definition.h"

class ActionMark
{
public:
	ActionMark();
	~ActionMark();

	bool CollitionR(int P_Pos,bool IsRight);
	bool CollitionL(int P_Pos,bool IsRight);
private:

};

#endif // !ACTION_MARK_H

