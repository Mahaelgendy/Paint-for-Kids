#include "Action.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

bool Action::isPointvalid(Point P1)
{
	bool flag = true;
	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false;
	}
    return flag;
}
