#include "ActionFillButton.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionFillButton::ActionFillButton(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionFillButton::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();



	//message switch for  fill color
	pGUI->PrintMessage("Click Button: To active switch Fill Color between background and fill figure (default background)");
	//Active switch for  fill color
	pManager->setFillColor(!pManager->getFillColor());


	pGUI->ClearStatusBar();




}
