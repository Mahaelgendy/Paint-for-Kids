#pragma once
#include "Action.h"

class ActionSendBack : public Action
{
public:
	ActionSendBack(ApplicationManager* pApp);
	void Execute();

};