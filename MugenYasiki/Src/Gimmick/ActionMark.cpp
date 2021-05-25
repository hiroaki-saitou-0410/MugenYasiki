#include "ActionMark.h"

ActionMark::ActionMark()
{
}

ActionMark::~ActionMark()
{
}

bool ActionMark::CollisionR(int P_Pos,bool IsRight)
{
	if (P_Pos >= RightLimitPosX - m_SearchRange && P_Pos <= RightLimitPosX+10 && IsRight == true)
	{
		return true;
	}
	return false;
}

bool ActionMark::CollisionL(int P_Pos, bool IsRight)
{
	if (P_Pos >= LeftLimitPosX && P_Pos <= LeftLimitPosX + m_SearchRange && IsRight == false)
	{
		return true;
	}
	return false;
}

bool ActionMark::Collision(int P_Pos,int Target)
{
	if (P_Pos >= Target - m_SearchRange && P_Pos <= Target + m_SearchRange)
	{
		return true;
	}
	return false;
}
