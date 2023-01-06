#ifndef Action_Load_H
#define Action_Load_H
#include "Action.h"
class ActionLoad : public Action
{
private:
	string FileName;       

public:

	ActionLoad(ApplicationManager* pApp);

	virtual void Execute();
};
#endif
