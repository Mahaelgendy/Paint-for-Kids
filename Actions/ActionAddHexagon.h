#ifndef ACTION_ADD_HEXAGON_H
#define ACTION_ADD_HEXAGON_H

#include "Action.h"

//Add Hexagon Action class
class ActionAddHexagon : public Action
{
public:
	ActionAddHexagon(ApplicationManager *pApp);
	
	//Add Hexagon to the ApplicationManager
	virtual void Execute() ;
	
};

#endif