#include "ActionAddRectangle.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddRectangle::ActionAddRectangle(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddRectangle::Execute()
{
	Point P1,P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Rectangle: Click at first point");	
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Rectangle: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft ;
	topLeft.x = P1.x<P2.x? P1.x: P2.x;
	topLeft.y = P1.y<P2.y? P1.y: P2.y;

	Point lowerRight;
	lowerRight.x = P1.x < P2.x ? P1.x : P2.x;
	lowerRight.y = P1.y < P2.y ? P1.y : P2.y;

		
	//Step 3 - Create a Square with the parameters read from the user
	CRectangle *R=new CRectangle(topLeft, lowerRight, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}
