#pragma once
#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class ActionColorMenu :public Action
{

public:
	ActionColorMenu(ApplicationManager* pApp);
	virtual void Execute();
};
