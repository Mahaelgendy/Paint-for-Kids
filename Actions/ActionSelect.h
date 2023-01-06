
#ifndef Action_Select_H
#define Action_Select_H

#include "Action.h"

//Add Select Action class
class ActionSelect : public Action
{
public:
	ActionSelect(ApplicationManager* pApp);

	virtual void Execute();
};

#endif