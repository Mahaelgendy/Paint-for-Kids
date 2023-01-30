#include "ActionAddHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "../Figures/CHexagon.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{} //constractor

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;
	Point topLeft;
	int horLen, verLen;
	float maxHorLen = 0;
	float minHorLen = 0;
	float maxVerLen = 0;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo HexGfxInfo;
	HexGfxInfo.isFilled  = pManager->getFillColor();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	HexGfxInfo.FillClr = pGUI->getCrntFillColor();
	HexGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	//Step 1 - Read Hexagon data from the user
	do {
		pGUI->PrintMessage("New hexa: Click at first point");
		//Read 1st point and store in point P1
		P1 = GetPoint();

		pGUI->PrintMessage("New hexa: Click at second point");
		//Read 2nd point and store in point P2
		P2 = GetPoint();

		pGUI->ClearStatusBar();

		//Step 2 - prepare Hexagon data
		//User has entered two points P1&P2
		//2.1- Identify the Top left corner of the Hexagon
		topLeft.x = P1.x < P2.x ? P1.x : P2.x;
		topLeft.y = P1.y < P2.y ? P1.y : P2.y;

		//2.2- Calcuate Hexagon horizontal_length and vertical_length
		horLen = abs(P1.x - P2.x);
		verLen = sqrt(pow(horLen, 2) - pow((0.5 * horLen), 2));

		maxHorLen = topLeft.x + 1.5 * horLen;
		minHorLen = abs(topLeft.x - 0.5 * horLen);
		maxVerLen = topLeft.y + 2 * verLen;

		if (minHorLen < UI.wx || maxHorLen > UI.width + UI.wx || maxVerLen < UI.StatusBarHeight || maxVerLen > UI.height - UI.StatusBarHeight)
		{
			pGUI->PrintMessage("Please click a valid point");
			Sleep(1000);
			pGUI->ClearStatusBar();
		}
	} while (minHorLen < UI.wx || maxHorLen > UI.width + UI.wx || maxVerLen < UI.StatusBarHeight || maxVerLen > UI.height - UI.StatusBarHeight);

	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(topLeft, horLen, verLen, HexGfxInfo);

	//Step 4 - Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
