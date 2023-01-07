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
		int resized;
		if (pAct == HALF)
		{
			resized=Selected->Resize(.5);
			if (resized == 0) {
				pGui->PrintMessage("Figure Resized :");
			}
			else {
				pGui->PrintMessage("Can't Resize :");
			}
		}
		else if (pAct == QUARTER)
		{
			resized=Selected->Resize(.25);
			if (resized == 0) {
				pGui->PrintMessage("Figure Resized :");
			}
			else {
				pGui->PrintMessage("Can't Resize :");
			}
		}
		else if (pAct == DOUBLE1)
		{
			resized=Selected->Resize(2.0);
			if (resized == 0) {
				pGui->PrintMessage("Figure Resized :");
			}
			else {
				pGui->PrintMessage("Can't Resize :");
			}
		}
		else if (pAct == QUADRUPLE)
		{
			resized=Selected->Resize(4);
			if (resized == 0) {
				pGui->PrintMessage("Figure Resized");
			}
			else {
				pGui->PrintMessage("Can't Resize");
			}
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
