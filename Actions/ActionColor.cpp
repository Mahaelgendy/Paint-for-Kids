#include "ActionColor.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionColor::ActionColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionColor::Execute()
{
	Point P1;
	color newColor;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	
	//Step 1 - Read Square data from the user
	//pGUI->PrintMessage("You Pick Color");
	pGUI->PrintMessage("Pick Color: Click at Color");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	newColor = pGUI->pWind->GetColor(P1.x, P1.y);
	pGUI->setCrntDrawColor(newColor);
	
	
	

	pGUI->ClearStatusBar();



	
}
