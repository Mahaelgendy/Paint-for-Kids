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
	
	//Active switch for  fill color
	pManager->setFillColor(!pManager->getFillColor());

	pGUI->ClearStatusBar();
	//message switch for  fill color
	pGUI->PrintMessage("Pick Fill Button Icon: Switch between Fill figure Color and background color (default background)");




}
