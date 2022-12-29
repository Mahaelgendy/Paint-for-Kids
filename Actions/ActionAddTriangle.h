#ifndef ACTION_ADD_TRIANGLE_H
#define ACTION_ADD_TRIANGLE_H

#include "Action.h"

//Add Square Action class
class ActionAddTriangle: public Action
{
public:
	ActionAddTriangle(ApplicationManager *pApp);
	
	//Add Square to the ApplicationManager
	virtual void Execute() ;
	
};

#endif