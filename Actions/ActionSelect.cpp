#include "ActionSelect.h"
#include"..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}


//Execute the action
void ActionSelect::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//Step 1 - Read click from user the user
	pGUI->PrintMessage("Select Any figure.... ");
	//Read  point and store in point P1
	P1 = GetPoint();
	
	pGUI->ClearStatusBar();

	//Step 2 - Get the The Selecterd Figer Address
	CFigure* fig= pManager->GetFigure(P1.x, P1.y);
	 

	//Step 3 - If The Point Exist in The Figure List
	//Switch from Selected to UnSelected or vice versa
	if (fig != NULL)
	{
		if (fig->IsSelected())
		{
			fig->SetSelected(false);
			
		}
		else
		{
			fig->SetSelected(true);
			fig->PrintInfo(pGUI);
		}
	}

}

