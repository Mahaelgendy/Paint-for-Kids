#include "ActionAddHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "../Figures/CHexagon.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New hexa: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New hexa: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int horLen = abs(topLeft.x - P2.x);
	int verLen = sqrt(pow(horLen, 2) - pow((0.5 * horLen), 2));


	//Step 3 - Create a Square with the parameters read from the user
	CHexagon* H = new CHexagon(topLeft, horLen,verLen, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(H);
}
