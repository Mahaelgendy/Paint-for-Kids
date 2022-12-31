#include "ActionResize.h"
#include "..\ApplicationManager.h"
#include <iostream>

ActionResize::ActionResize(ApplicationManager* pApp, CFigure* selected) :Action(pApp), Selected(selected)
{

}
void ActionResize::Execute()
{
	GUI* pGui = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedFigure();
	if (selectedIndex != -1)
	{
		pGui->ClearToolBar();
		pGui->CreateResizeToolBar();
		ActionType pAct = pGui->MapInputToActionType();
		Selected = pManager->GetSelectedFigure();
		if (pAct == HALF)
		{
			Selected->Resize(.5);
		}
		else if (pAct == QUARTER)
		{
			Selected->Resize(.25);
		}
		else if (pAct == DOUBLE1)
		{
			Selected->Resize(2.0);
		}
		else if (pAct == QUADRUPLE)
		{
			Selected->Resize(4);
		}
		else if (pAct == BACK2)
		{
			Action* act = pManager->CreateAction(GO_BACK);
			act->Execute();
			return;
		}
		pGui->ClearDrawArea();
		pManager->UpdateInterface();
		Execute(); //recursion
	}
	else
		pGui->PrintMessage("Select a shape before you can perform this action");
}
