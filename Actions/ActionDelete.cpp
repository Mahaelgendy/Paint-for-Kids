#include "ActionDelete.h"
#include "../GUI/GUI.h"
#include "..\ApplicationManager.h"


ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)//constructor chaining
{}

void ActionDelete::Execute()
{
	GUI* pGui = pManager->GetGUI();
	DeleteShape();

}
void ActionDelete::DeleteShape() 
{
	GUI* pGUI = pManager->GetGUI();
	int* Figs = pManager->getFigCount();
	CFigure** FigsList = pManager->getFigList();
	int figSelectedFlag = 0;
	for (int i = 0; i < *Figs; i++) 
	{
		if (FigsList[i]->IsSelected())
		{
			delete FigsList[i];
			*Figs = *Figs -1;
			figSelectedFlag = 1;
			for (int j = i; j < *Figs; j++)
			{
				FigsList[j] = FigsList[j + 1];
			}
			i--;
		}
	}
	if (figSelectedFlag == 1) {
		if (UI.InterfaceMode == MODE_DRAW)
			pGUI->PrintMessage("Figure Deleted");
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else {
		pGUI->PrintMessage("Please Select A Figure ...");
	}
}