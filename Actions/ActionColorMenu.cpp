#include "ActionColorMenu.h"
#include "..\ApplicationManager.h"
#include <iostream>

ActionColorMenu::ActionColorMenu(ApplicationManager* pApp) :Action(pApp)
{

}
void ActionColorMenu::Execute()
{
	
	GUI* pGUI = pManager->GetGUI();

	//create color tool bar
	pGUI->ClearToolBar();
	pGUI->CreateColorToolBar();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Welcome To Color Tool Bar");
		
}
