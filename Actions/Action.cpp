#include "Action.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

Point Action::GetPoint()
{
	//Function to get a Valid Point in Drowing Area
	Point P1;
	GUI* pGUI = pManager->GetGUI();
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
	return P1;
}
