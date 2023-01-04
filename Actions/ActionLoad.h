#ifndef Action_Load_H
#define Action_Load_H
#include "Action.h"
class ActionLoad : public Action
{
private:
	string FileName;       

public:

	ActionLoad(ApplicationManager* pApp);

	//Reads ellipse parameter

	//Add ellipse to the ApplicationManager
	virtual void Execute();
};
#endif
