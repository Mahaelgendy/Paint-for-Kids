#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class ActionResize :public Action
{
	CFigure* Selected = NULL;

public:
	ActionResize(ApplicationManager* pApp, CFigure*);
	virtual void Execute();
};
