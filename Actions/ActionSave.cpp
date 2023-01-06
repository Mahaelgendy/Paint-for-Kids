#include "ActionSave.h"
#include"..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include<fstream>
#include <direct.h>






ActionSave::ActionSave(ApplicationManager* pApp, int _FigerCount) :Action(pApp)
{
	FigerCount = _FigerCount;
}


//Execute the action
void ActionSave::Execute()
{
	////get a pointer to the interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Please write the file name then press ENTER--> (IF FILE NAME EXISIT YOU WILL LOSE THE OLD DATA)");
	FileName = pGUI->GetSrting();  //read the file name
	ofstream File;   

	File.open((FileName + ".txt"), ios::out);  

	bool flag = false;
	if (File.fail()) {     //Check if the FileName is a valid name
		flag = true; 
	}
		

	while (flag)   //Reopen A viald Color
	{
		pGUI->PrintMessage("INVALID NAME...Please write a valid name then press Enter");
		FileName = pGUI->GetSrting();
		File.open(FileName + ".txt", ios::out);
		if (File.good()) {
			flag = false;
		}
	}
	File << pManager->colorToString(UI.DrawColor) << "\t";		//Write the Current Draw Color 
	File << pManager->colorToString(UI.FillColor) << "\t";		//Write the Current Fill Color 
	File << pManager->colorToString(UI.BkGrndColor) << "\t";   //Write the Current BackGround Color 
	pGUI->ClearStatusBar();
	File << FigerCount << "\n";

	pManager->SaveFigData(File);  //Save Each figer Data
	File.close(); //Close The file 
	pGUI->PrintMessage("Your data has been seved successfully...");   //Done!

}

