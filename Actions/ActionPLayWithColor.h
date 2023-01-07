#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class ActionPLayWithColors :
    public Action
{
protected:
    static int randomColorsGenerator;
    static int wrong;
    static int right;
    Point p1;
public:
    ActionPLayWithColors(ApplicationManager* pApp);
    void Execute();
    void ExecuteSelected(CFigure*);
};

