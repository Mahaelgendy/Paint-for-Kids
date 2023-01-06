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
	SqrGfxInfo.isFilled = pManager->getFillColor();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Triangle data from the user

	pGUI->PrintMessage("New Triangle: Click at first point");	
	//Read 1st point and store in point P1
	P1 = GetPoint();
	

	pGUI->PrintMessage("New Triangle: Click at second point");
	//Read 2nd point and store in point P2
	P2 = GetPoint();

	pGUI->PrintMessage("New Triangle: Click at third point");
	//Read 2nd point and store in point P2
	P3 = GetPoint();

	pGUI->ClearStatusBar();


	//Step 2 - Create a Triangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2,P3,SqrGfxInfo);

	//Step 3 - Add the Triangle to the list of figures
	pManager->AddFigure(R);
}

