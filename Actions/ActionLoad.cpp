#include "ActionLoad.h"
#include"..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include<fstream>
#include <iostream>



ActionLoad::ActionLoad(ApplicationManager* pApp) : Action(pApp)
{
}


void ActionLoad::Execute()
{
	int r, g, b;		//To Read RGB Color
	ifstream File;		 //object of ifstream class
	bool flag = false; 
	string figName;  
	int figcount;
	CFigure* fig;
	GUI* pGUI = pManager->GetGUI(); //Point to GUI
	pGUI->PrintMessage("please write the file name -->");
	FileName = pGUI->GetSrting();   //Get input from user


	File.open(FileName + ".txt");  //Open the File
	

	if (File.fail())  //Check if the FileName is a valid name
	{
		pGUI->PrintMessage("invalid name");
		return;
	}
	pGUI->ClearDrawArea();
	pManager->DeleteAllFig();       //Delete The figure list  
	  
	File >> r >> g >> b;
	color DrawColor(r, g, b); 
	File >> r >> g >> b;
	color FillColor(r, g, b);

	File >> r >> g >> b;
	color BkGrndColor(r, g, b);
	pGUI->setCrntDrawColor(DrawColor);
	pGUI->setCrntFillColor(FillColor);
	pGUI->setBackgroundColor(BkGrndColor);
	File >> figcount;
	
	while (figcount)         //For each line on the file we will read it and determine its type
	{
		cout << figcount;
		File >> figName;
		if (figName == "Elipse")
		{
			fig = new CEllipse();
		}
		else if (figName == "Square") {
			fig = new CSquare();
		}
		else if (figName == "Triangle")
		{
			fig = new CTriangle();
		}	
		else if (figName == "Hexagon") {
			fig = new CHexagon();
		}
			
		fig->Load(File);			 //Now we created the object and we should load it
		pManager->AddFigure(fig);	//Add to the figure list

		figcount--;		//decrease the count 
	}
	pManager->UpdateInterface();    //Draw the figure list
	pGUI->PrintMessage("File loaded successfully...^_^");
	pGUI->ClearStatusBar();
}
