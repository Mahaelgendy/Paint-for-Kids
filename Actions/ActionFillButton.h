#pragma once
#pragma once
#pragma once
#ifndef ACTION_FILL_BUTTON_H
#define ACTION_FILL_BUTTON_H

#include "Action.h"

//Chane Current Action class
class ActionFillButton : public Action
{
public:
	ActionFillButton(ApplicationManager* pApp);

	//Change Color to the ApplicationManager
	virtual void Execute();

};

#endif