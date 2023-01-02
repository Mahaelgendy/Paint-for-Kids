#include "ActionSwitchToPlay.h"
#include "..\GUI\GUI.h"
#include "../ApplicationManager.h"

ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pMan):Action(pMan)
{
		
}

void ActionSwitchToPlay::Execute() {

	GUI* pGUI = pManager->GetGUI();
	//Action* newAct = new ActionSave(pManager, 1);
	//pManager->ExecuteAction(newAct);
	UI.InterfaceMode = MODE_PLAY;
	pGUI->ClearToolBar();
	pGUI->CreatePlayToolBar();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Welcome to play mode!");
	
}