#include "ActionSwitchToDrawMode.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
ActionSwitchToDrawMode::ActionSwitchToDrawMode(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToDrawMode::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();

	pGUI->PrintMessage("Back to Draw mode");
	UI.InterfaceMode = MODE_DRAW;
}
