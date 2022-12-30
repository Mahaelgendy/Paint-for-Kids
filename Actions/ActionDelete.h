#pragma once
#include "Action.h"

class ActionDelete : public Action
{
public:
	ActionDelete(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();
	virtual void DeleteShape();

};
