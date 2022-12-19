#ifndef ACTION_ADD_RECTANGLE_H
#define ACTION_ADD_RECTANGLE_H

#include "Action.h"

//Add Square Action class
class ActionAddRectangle : public Action
{
public:
	ActionAddRectangle(ApplicationManager *pApp);
	
	//Add Square to the ApplicationManager
	virtual void Execute() ;
	
};

#endif