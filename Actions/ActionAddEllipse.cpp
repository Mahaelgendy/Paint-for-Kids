#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager * pApp):Action(pApp)  //constructor
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo EllipGfxInfo;
	EllipGfxInfo.isFilled = pManager->getFillColor();	//default is not filled

	//get drawing, filling colors and pen width from the interface
	EllipGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	EllipGfxInfo.FillClr = pGUI->getCrntFillColor();
	EllipGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Ellipse data from the user
	pGUI->PrintMessage("New Ellips: Click at first point");	
	P1=GetPoint(); //Read 1st point and store in point P1
	pGUI->PrintMessage("New Ellips: Click at second point");
	P2 = GetPoint();//Read 2nd point and store in point P2
	
	pGUI->ClearStatusBar();
	
	//Step 3 - Create a Ellipse with the parameters read from the user
	CEllipse* E =new CEllipse(P1, P2, EllipGfxInfo);

	//Step 4 - Add the Ellipse to the list of figures
	pManager->AddFigure(E);
}

