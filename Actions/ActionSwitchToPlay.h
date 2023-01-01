#pragma once
#include "Action.h"
class ActionSwitchToPlay : public Action
{
private:
public:
	ActionSwitchToPlay(ApplicationManager* pMan);
	virtual void Execute();
};

