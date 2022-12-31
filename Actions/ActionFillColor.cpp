#include "ActionFillColor.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionFillColor::ActionFillColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionFillColor::Execute()
{
	Point P1;
	color newFillColor;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	
	

	
	//Step 1 - Read Square data from the user
	pGUI->PrintMessage("Pick Fill Color: Click at Color");
	pGUI->GetPointClicked(P1.x, P1.y);

	newFillColor = pGUI->pWind->GetColor(P1.x, P1.y);
	
	
	
	
	CFigure* figSelected = pManager->GetSelectedFigure();
	CFigure* figNotSelected = pManager->GetNotSelectedFigure();
	bool fillColor = pManager->getFillColor();
	/*if (fig == NULL || fig->IsSelected())
	{
	pGUI->setBackgroundColor(newFillColor);
	pGUI->ClearDrawArea();
	}*/
	if (figSelected != NULL)
	{
		figSelected->ChngFillClr(newFillColor);
		figSelected->SetSelected(false);
	}
	else
	{
		
		if (figNotSelected != NULL && fillColor == false)
		{
			pGUI->setBackgroundColor(newFillColor);
			pGUI->ClearDrawArea();
		}
		pGUI->setCrntFillColor(newFillColor);
	}


	pGUI->ClearStatusBar();




}
