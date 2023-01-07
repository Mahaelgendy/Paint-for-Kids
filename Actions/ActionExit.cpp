#include "ActionExit.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "ActionSave.h"
#include <string>

ActionExit::ActionExit(ApplicationManager* pMan) :Action(pMan)
{

}
void ActionExit::ReadActionParameters() //must implement all the functions in the Action class
{}
void ActionExit::Execute()
{
	GUI* pGui = pManager->GetGUI();
	pGui->PrintMessage("If you want to save you graph before exit write (Y) else write (N) ");
	string s = pGui->GetSrting();
	if (s == "Y" || s == "y") {
		Action* newAct = new ActionSave(pManager);
		pManager->ExecuteAction(newAct);
	}
	else {
		pGui->PrintMessage("See you next time");
	}
}