#pragma once
#ifndef ACTION_SEND_TO_BACK_H
#define ACTION_SEND_TO_BACK_H

#include "Action.h"

//Add Ellipse Action class
class ActionSendToBack : public Action
{
public:
	ActionSendToBack(ApplicationManager* pApp);

	virtual void Execute();

};

#endif