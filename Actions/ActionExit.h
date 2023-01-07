#pragma once
#include "Action.h"
class ActionExit :
    public Action
{
public:
    ActionExit(ApplicationManager* pMan);
    virtual void ReadActionParameters();
    virtual void Execute();

};

