#include "ActionFillButton.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionFillButton::ActionFillButton(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionFillButton::Execute()
{
	Point P1;
	color newFillColor;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();




	//Step 1 - Read Square data from the user
	pGUI->PrintMessage("Click Button: T o active Fill Color");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	
	pManager->setFillColor(!pManager->getFillColor());


	pGUI->ClearStatusBar();




}
