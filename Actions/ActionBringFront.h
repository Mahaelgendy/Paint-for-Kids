#ifndef ACTION_BRING_FRONT_H
#define ACTION_BRING_FRONT_H


#include "Action.h"
class ActionBringFront : public Action {
public:
	ActionBringFront(ApplicationManager* pApp);
	void Execute();

};
#endif
