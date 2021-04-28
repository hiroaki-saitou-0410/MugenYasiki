#include "ActionMark.h"

ActionMark::ActionMark()
{
}

ActionMark::~ActionMark()
{
}

bool ActionMark::CollitionR(int P_Pos,bool IsRight)
{
	if (P_Pos >= RightLimitPosX - 50 && P_Pos <= RightLimitPosX+10 && IsRight == true)
	{
		return true;
	}
	return false;
}

bool ActionMark::CollitionL(int P_Pos, bool IsRight)
{
	if (P_Pos >= LeftLimitPosX && P_Pos <= LeftLimitPosX + 50 && IsRight == false)
	{
		return true;
	}
	return false;
}
