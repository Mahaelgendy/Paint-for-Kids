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
	bool flag = true;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	do {
		//Read 1st point to pick border color
		pGUI->PrintMessage("Pick Color: Click at Color");
		//Get 1st point and store it in color
		pGUI->GetPointClicked(P1.x, P1.y);
		newColor = pGUI->pWind->GetColor(P1.x, P1.y);
		if (newColor == BLACK || newColor == HOTRED || newColor == WHITE || newColor == HOTBLUE || newColor == HOTGREEN || newColor == HOTYELLOW)
			flag = false;
	} while (flag);
	
	//check if there is a figure selected to change border color
	CFigure* fig = pManager->GetSelectedFigure();
	if (fig != NULL && fig->IsSelected())
	{
		fig->ChngDrawClr(newColor);
		fig->SetSelected(false);

	}
	//case there is not any figure selected to change border color
	else
	{
		pGUI->setCrntDrawColor(newColor);
	}
	

	pGUI->ClearStatusBar();



	
}
