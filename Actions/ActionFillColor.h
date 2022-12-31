#pragma once
#pragma once
#ifndef ACTION_FILL_COLOR_H
#define ACTION_FILL_COLOR_H

#include "Action.h"

//Chane Current Action class
class ActionFillColor : public Action
{
public:
	ActionFillColor(ApplicationManager* pApp);

	//Change Color to the ApplicationManager
	virtual void Execute();

};

#endif