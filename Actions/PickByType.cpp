#include "PickByType.h"
#include "../ApplicationManager.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CSquare.h"

PickByType::PickByType(ApplicationManager* pApp) :Action(pApp)
{
	figuresNumber = 0;
	numberOfRightFig = 0;
	numberOfWrongFig = 0;
	for (int i = 0; i < 4; i++)
		FigsList[i] = 0;
}

void PickByType::PrintScore(int score)
{
	GUI* pGUI = pManager->GetGUI();
	string message;

	if (score == 1) 
	{
		numberOfRightFig++;
		message = "Right!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";

	}
	else if (score == 2)
	{
		numberOfWrongFig++;
		message = "Wrong!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	}
	else
	{
		message = "YOU WIN!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	}
	pGUI->PrintMessage(message);
}

void PickByType::ReadActionParameters()
{
	for (int i = 0; i < *pManager->getFigCount(); i++)
	{
		Fig = pManager->DrawnFigs(i);

		if (dynamic_cast<CEllipse*>(Fig))
			FigsList[0]++;

		else if (dynamic_cast<CHexagon*>(Fig))
			FigsList[1]++;

		else if (dynamic_cast<CTriangle*>(Fig))
			FigsList[2]++;

		else FigsList[3]++;
	}

	for (int i = 0; i < 4; i++)
		if (FigsList[i] != 0)figuresNumber++;
}

void PickByType::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();
	if (figuresNumber > 1)
	{
		CFigure* clickedFig;
		randomFigNumber = rand() % *pManager->getFigCount();

		Fig = pManager->DrawnFigs(randomFigNumber);
		if (dynamic_cast<CEllipse*>(Fig))
		{
			pickedFigNumber = FigsList[0];
			pGUI->PrintMessage("Pick all Ellips");
		}
		else if (dynamic_cast<CHexagon*>(Fig))
		{
			pickedFigNumber = FigsList[1];
			pGUI->PrintMessage("Pick all Hexagons");
		}
		else if (dynamic_cast<CTriangle*>(Fig))
		{
			pickedFigNumber = FigsList[2];
			pGUI->PrintMessage("Pick all Triangles");
		}
		else
		{
			pickedFigNumber = FigsList[3];
			pGUI->PrintMessage("Pick all Squares");
		}

		while (pickedFigNumber > 0)
		{
			pGUI->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{
					if (dynamic_cast<CEllipse*>(Fig) && dynamic_cast<CEllipse*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CHexagon*>(Fig) && dynamic_cast<CHexagon*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CTriangle*>(Fig) && dynamic_cast<CTriangle*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CSquare*>(Fig) && dynamic_cast<CSquare*>(clickedFig))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else 
					{
						PrintScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				pickedFigNumber = -1;
			}
			if (pickedFigNumber == 0)
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
}