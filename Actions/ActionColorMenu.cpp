#include "ActionColorMenu.h"
#include "..\ApplicationManager.h"
#include <iostream>

ActionColorMenu::ActionColorMenu(ApplicationManager* pApp) :Action(pApp)
{

}
void ActionColorMenu::Execute()
{
	
	GUI* pGUI = pManager->GetGUI();
	
		pGUI->ClearToolBar();
		pGUI->CreateColorToolBar();
		pGUI->ClearStatusBar();
		
}
