#include "ActionAddTriangle.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddTriangle::ActionAddTriangle(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Square: Click at first point");	
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Square: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->PrintMessage("New Square: Click at third point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P3.x, P3.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates

		
	//Step 3 - Create a Square with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2,P3,SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}

