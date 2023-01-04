#include "ActionSave.h"
#include"..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include<fstream>
#include <direct.h>






ActionSave::ActionSave(ApplicationManager* pApp, int _FigerCount) :Action(pApp)
{
}


//Execute the action
void ActionSave::Execute()
{
	//auto path = std::filesystem::current_path(); //getting path
	//std::filesystem::current_path(path); //setting path
	////get a pointer to the interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Please write the file name then press ENTER--> (IF FILE NAME EXISIT YOU WILL LOSE THE OLD DATA)");
	FileName = pGUI->GetSrting();
	ofstream File;   

	File.open((FileName + ".txt"), ios::out);

	bool flag = false;
	if (File.fail()) {
		flag = true; 
	}
		

	while (flag)
	{
		pGUI->PrintMessage("INVALID NAME...Please write a valid name then press Enter");
		FileName = pGUI->GetSrting();
		File.open(FileName + ".txt", ios::out);
		if (File.good()) {
			flag = false;
		}
	}
	pGUI->ClearStatusBar();
	pManager->SaveFigData(File);
	File.close(); 
	pGUI->PrintMessage("Your data has been seved successfully...");

}

