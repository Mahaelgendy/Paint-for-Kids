#include "PickByTypeAndColor.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CEllipse.h"
#include "..\GUI\GUI.h"




void PickByTypeAndColor::PrintScore(int S)
{
	GUI* pGUI = pManager->GetGUI();

	string message;
	if (S == 1)
	{
		numberOfRightFig++;
		message = "Right!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	}
	else 	if (S == 2)
	{
		numberOfWrongFig++;
		message = "Wrong!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(numberOfRightFig) + " Right, and " + to_string(numberOfWrongFig) + " Wrong.";
	pGUI->PrintMessage(message);


}

PickByTypeAndColor::PickByTypeAndColor(ApplicationManager* pApp) :Action(pApp)
{
	figuresNumber = 0;
	numberOfWrongFig = 0;
	numberOfRightFig = 0;
	for (int i = 0;i < 23;i++)
		combinations[i] = 0;
}


PickByTypeAndColor::~PickByTypeAndColor()
{

}

void PickByTypeAndColor::ReadActionParameters()
{
	for (int i = 0; i < *pManager->getFigCount();i++) {
		Fig = pManager->DrawnFigs(i);
		if ((Fig->GetGfxInfo().isFilled) && !(dynamic_cast<CSquare*>(Fig))) //counts combinations occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CEllipse*>(Fig))
					combinations[0]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[1]++;
				else
					combinations[2]++;
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CEllipse*>(Fig))
					combinations[3]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[4]++;
				else
					combinations[5]++;
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CEllipse*>(Fig))
					combinations[6]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[7]++;
				else
					combinations[8]++;
			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CEllipse*>(Fig))
					combinations[9]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[10]++;
				else
					combinations[11]++;
			}
			else
			{
				if (dynamic_cast<CEllipse*>(Fig))
					combinations[12]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[13]++;
				else
					combinations[14]++;
			}
		}
		else {
			if (dynamic_cast<CEllipse*>(Fig))
				combinations[15]++;
			else if (dynamic_cast<CTriangle*>(Fig))
				combinations[16]++;
			else if (dynamic_cast<CHexagon*>(Fig))
				combinations[17]++;
			else
			{

				if (Fig->GetGfxInfo().FillClr == BLACK)
					combinations[18]++;

				else if (Fig->GetGfxInfo().FillClr == WHITE)
					combinations[19]++;

				else if (Fig->GetGfxInfo().FillClr == BLUE)
					combinations[20]++;

				else if (Fig->GetGfxInfo().FillClr == GREEN)
					combinations[21]++;

				else
					combinations[22]++;

			}
		}
	}

	for (int i = 0;i < 23;i++)
		if (combinations[i] != 0)
			figuresNumber++;


}

void PickByTypeAndColor::Execute()
{

	GUI* pGui = pManager->GetGUI();
	//Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (figuresNumber > 1)
	{
		//Figure to be hidden
		CFigure* clickedFig;
		//Randomize
		randomFigNumber = rand() % *pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(randomFigNumber);
		if ((Fig->GetGfxInfo().isFilled) && !(dynamic_cast<CSquare*>(Fig)))
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CEllipse*>(Fig))
				{
					pickedFigNumber = combinations[0];
					pGui->PrintMessage("Pick up all the black ellipses!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					pickedFigNumber = combinations[1];
					pGui->PrintMessage("Pick up all the black triangles!");

				}
				else
				{
					pickedFigNumber = combinations[2];
					pGui->PrintMessage("Pick up all the black hexagons!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CEllipse*>(Fig))
				{
					pickedFigNumber = combinations[3];
					pGui->PrintMessage("Pick up all the white ellipses!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					pickedFigNumber = combinations[4];
					pGui->PrintMessage("Pick up all the white triangles!");

				}
				else
				{
					pickedFigNumber = combinations[5];
					pGui->PrintMessage("Pick up all the white hexagons!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CEllipse*>(Fig))
				{
					pickedFigNumber = combinations[6];
					pGui->PrintMessage("Pick up all the blue ellipses!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					pickedFigNumber = combinations[7];
					pGui->PrintMessage("Pick up all the blue triangles!");

				}
				else
				{
					pickedFigNumber = combinations[8];
					pGui->PrintMessage("Pick up all the blue hexagons!");

				}


			}
			else if (Fig->GetGfxInfo().FillClr == HOTGREEN)
			{
				if (dynamic_cast<CEllipse*>(Fig))
				{
					pickedFigNumber = combinations[9];
					pGui->PrintMessage("Pick up all the green ellipses!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					pickedFigNumber = combinations[10];
					pGui->PrintMessage("Pick up all the green triangles!");

				}
				else
				{
					pickedFigNumber = combinations[11];
					pGui->PrintMessage("Pick up all the green hexagons!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CEllipse*>(Fig))
				{
					pickedFigNumber = combinations[12];
					pGui->PrintMessage("Pick up all the red ellipse!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					pickedFigNumber = combinations[13];
					pGui->PrintMessage("Pick up all the red triangles!");

				}
				else
				{
					pickedFigNumber = combinations[14];
					pGui->PrintMessage("Pick up all the red hexagon!");

				}

			}
		}
		else
		{
			if (dynamic_cast<CEllipse*>(Fig))
			{
				pickedFigNumber = combinations[15];
				pGui->PrintMessage("Pick up all the unfilled ellpises!");

			}
			else if (dynamic_cast<CTriangle*>(Fig))
			{
				pickedFigNumber = combinations[16];
				pGui->PrintMessage("Pick up all the unfilled triangles!");

			}
			else if (dynamic_cast<CHexagon*>(Fig))
			{
				pickedFigNumber = combinations[17];
				pGui->PrintMessage("Pick up all the unfilled hexagons!");

			}
			else
			{
				if (Fig->GetGfxInfo().FillClr == BLACK)
				{
					pickedFigNumber = combinations[18];
					pGui->PrintMessage("Pick up black squares!");
				}
				else if (Fig->GetGfxInfo().FillClr == WHITE)
				{
					pickedFigNumber = combinations[19];
					pGui->PrintMessage("Pick up black white squares!");
				}
				else if (Fig->GetGfxInfo().FillClr == BLUE)
				{
					pickedFigNumber = combinations[20];
					pGui->PrintMessage("Pick up blue squares!");

				}
				else if (Fig->GetGfxInfo().FillClr == GREEN)
				{
					pickedFigNumber = combinations[21];
					pGui->PrintMessage("Pick up green squares!");

				}
				else
				{
					pickedFigNumber = combinations[22];
					pGui->PrintMessage("Pick up red squares!");

				}

			}

		}
		while (pickedFigNumber > 0)
		{

			pGui->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{

					if (dynamic_cast<CSquare*>(Fig) && dynamic_cast<CSquare*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CEllipse*>(Fig) && dynamic_cast<CEllipse*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CHexagon*>(Fig) && dynamic_cast<CHexagon*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrintScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						pickedFigNumber--;
					}
					else if (dynamic_cast<CTriangle*>(Fig) && dynamic_cast<CTriangle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
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
				pGui->PrintMessage("Toolbar clicked, game aborted.");
				pickedFigNumber = -1;
			}
		}

		if (pickedFigNumber == 0)
			PrintScore(3);

	}
	else pGui->PrintMessage("You must have at least two or more combinations to play pick by type and color!");
	for (int i = 0; i < *pManager->getFigCount();i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}
