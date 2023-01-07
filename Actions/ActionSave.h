
#ifndef Action_Save_H
#define Action_Save_H

#include "Action.h"

class ActionSave : public Action
{
private:
	string FileName;
	int FigerCount;
public:
	ActionSave(ApplicationManager* pApp, int _FigerCount);
	ActionSave(ApplicationManager* pApp);

	virtual void Execute();
};

#endif