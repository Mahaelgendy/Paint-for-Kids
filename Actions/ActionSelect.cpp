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
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P1.x, P1.y); //Get Pasting Point
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}

	pGUI->ClearStatusBar();


	CFigure* fig= pManager->GetFigure(P1.x, P1.y);
	 

	

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

