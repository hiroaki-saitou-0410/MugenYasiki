#include "ActionMark.h"

ActionMark::ActionMark()
{
}

ActionMark::~ActionMark()
{
}

bool ActionMark::Collition(int P_Pos,int IsRight)
{
	if (P_Pos >= LeftLimitPosX && P_Pos <= LeftLimitPosX + 50 && IsRight == false)
	{
		return true;
	}
	else if (P_Pos >= RightLimitPosX - 50 && P_Pos <= RightLimitPosX+10 && IsRight == true)
	{
		return true;
	}
	return false;
}
