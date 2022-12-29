
#ifndef Action_Select_H
#define Action_Select_H

#include "Action.h"

//Add Square Action class
class ActionSelect : public Action
{
private:
	Point P;
public:
	ActionSelect(ApplicationManager* pApp);

	virtual void Execute();
};

#endif