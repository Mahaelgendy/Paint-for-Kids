#pragma once
#ifndef ACTION_BRING_FRONT_H
#define ACTION_BRING_FRONT_H

#include "Action.h"

//Add Ellipse Action class
class ActionBringToFront : public Action
{
public:
	ActionBringToFront(ApplicationManager* pApp);

	virtual void Execute();

};

#endif