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
	
	

	
	//Read 1st point to pick fill color
	pGUI->PrintMessage("Pick Fill Color: Click at Color");
	//Get 1st point and store it in color
	pGUI->GetPointClicked(P1.x, P1.y);
	newFillColor = pGUI->pWind->GetColor(P1.x, P1.y);
	
	
	CFigure* figSelected = pManager->GetSelectedFigure();
	CFigure* figNotSelected = pManager->GetNotSelectedFigure();
	bool fillColor = pManager->getFillColor();
	

	//check if there is a figure selected to change fill color
	if (figSelected != NULL)
	{
		figSelected->ChngFillClr(newFillColor);
		figSelected->SetSelected(false);
	}
	//case there is not a figure selected
	else
	{
		//case change background color
		if (fillColor == false)
		{
			pGUI->setBackgroundColor(newFillColor);
			pGUI->ClearDrawArea();
		}
		//case change fill color for new figure
		else
			pGUI->setCrntFillColor(newFillColor);
	}




	pGUI->ClearStatusBar();




}
