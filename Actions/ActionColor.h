#pragma once
#ifndef ACTION_COLOR_H
#define ACTION_COLOR_H

#include "Action.h"

//Chane Current Action class
class ActionColor : public Action
{
public:
	ActionColor(ApplicationManager* pApp);

	//Change Color to the ApplicationManager
	virtual void Execute();

};

#endif