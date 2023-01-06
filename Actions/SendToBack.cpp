#include "..\ApplicationManager.h"
#include "SendToBack.h"

#include "..\GUI\GUI.h"


ActionSendToBack::ActionSendToBack(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionSendToBack::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//pGUI->HighlightButton(ITM_SEND_TO_BACK);

	int selectedIndexFigure = pManager->GetSelectedFigureIndex();
	if (selectedIndexFigure > -1) {
		pManager->SendToBack(selectedIndexFigure);
		pGUI->PrintMessage("The shape was sent to Back");
	}
	else {
		pGUI->PrintMessage("You Must Select A Shape First...");
	}

	//pGUI->RemoveButtonHighlight(ITM_SEND_TO_BACK);

}