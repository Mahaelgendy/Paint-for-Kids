#include "ActionPickByColor.h"
#include "..\CMUgraphicsLib\colors.cpp" 
#include "..\ApplicationManager.h"

ActionPickByColor::ActionPickByColor(ApplicationManager* pApp) : Action(pApp)
{
	numberOfWrongColor = 0;
	numberOfRightColor = 0;
	ColorsNumber = 0;
	for (int i = 0; i <7; i++)
	{
		ColorsList[i] = 0;
	}

};
color ActionPickByColor::AssignColor(CFigure* Fig)
{
	if (Fig->GetGfxInfo().FillClr == BLACK)
		return BLACK;
	else if (Fig->GetGfxInfo().FillClr == WHITE)
		return WHITE;
	else if (Fig->GetGfxInfo().FillClr == HOTBLUE)
		return HOTBLUE;
	else if (Fig->GetGfxInfo().FillClr == HOTGREEN)
		return HOTGREEN;
	else if (Fig->GetGfxInfo().FillClr == HOTRED)
		return HOTRED;
	else if (Fig->GetGfxInfo().FillClr == HOTYELLOW)
		return HOTYELLOW;
}
void ActionPickByColor::PrintScore(int score)
{
	GUI* pGUI = pManager->GetGUI();
	string message;

	if (score == 1)
	{
		numberOfRightColor++;
		message = "Right!, Your score is: " + to_string(numberOfRightColor) + " Right, and " + to_string(numberOfWrongColor) + " Wrong.";

	}
	else if (score == 2)
	{
		numberOfWrongColor++;
		message = "Wrong!, Your score is: " + to_string(numberOfRightColor) + " Right, and " + to_string(numberOfWrongColor) + " Wrong.";
	}
	else
	{
		message = "YOU WIN!, Your score is: " + to_string(numberOfRightColor) + " Right, and " + to_string(numberOfWrongColor) + " Wrong.";
	}
	pGUI->PrintMessage(message);
}
void ActionPickByColor::ReadActionParameters()
{
	for (int i = 0; i < *pManager->getFigCount(); i++)
	{
		Fig = pManager->DrawnFigs(i);
		if (Fig->GetGfxInfo().isFilled)
		{
			if(Fig->GetGfxInfo().FillClr == BLACK)
				ColorsList[0]++;
			else if (Fig->GetGfxInfo().FillClr == HOTBLUE)
				ColorsList[1]++;
			else if (Fig->GetGfxInfo().FillClr == WHITE)
				ColorsList[2]++;
			else if (Fig->GetGfxInfo().FillClr == HOTRED)
				ColorsList[3]++;
			else if (Fig->GetGfxInfo().FillClr == HOTYELLOW)
				ColorsList[4]++;
			else if (Fig->GetGfxInfo().FillClr == HOTGREEN)
				ColorsList[5]++;
		}
		else
			ColorsList[6]++;
	}

	for (int i = 0; i < 7; i++)
		if (ColorsList[i] != 0) ColorsNumber++;
}
void ActionPickByColor::Execute()
{
	CFigure* clickedFig;
	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();
	if (ColorsNumber > 1)
	{
		randomFigNumber = rand() % *pManager->getFigCount();
		Fig = pManager->DrawnFigs(randomFigNumber);
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				pickedColorNumber = ColorsList[0];
				pGUI->PrintMessage("Pick Black Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == HOTBLUE)
			{
				pickedColorNumber = ColorsList[1];
				pGUI->PrintMessage("Pick Blue Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				pickedColorNumber = ColorsList[2];
				pGUI->PrintMessage("Pick WHITE Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == HOTRED)
			{
				pickedColorNumber = ColorsList[3];
				pGUI->PrintMessage("Pick RED Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == HOTYELLOW)
			{
				pickedColorNumber = ColorsList[4];
				pGUI->PrintMessage("Pick YELLOW Shapes");
			}
			else if (Fig->GetGfxInfo().FillClr == HOTGREEN)
			{
				pickedColorNumber = ColorsList[5];
				pGUI->PrintMessage("Pick GREEN Shapes");
			}
		}
		else {
			pickedColorNumber = ColorsList[6];
			pGUI->PrintMessage("Pick Shapes which are not filled");

		}
		while (pickedColorNumber > 0)
		{
			pGUI->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{
					if (!(Fig->GetGfxInfo().isFilled) && !(clickedFig->GetGfxInfo().isFilled))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedColorNumber--;
					}
					else if ((clickedFig->GetGfxInfo().isFilled && Fig->GetGfxInfo().isFilled) && clickedFig->GetGfxInfo().FillClr == AssignColor(Fig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedColorNumber--;
					}
					else {
						PrintScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				pickedColorNumber = -1;
			}
			if (pickedColorNumber == 0)
				PrintScore(3);
		}
	}
	else
	{
		pGUI->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	}
	for (int i = 0; i < *pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
};

