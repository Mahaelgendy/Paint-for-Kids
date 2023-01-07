#include "Actions\ActionPLayWithColor.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionLoad.h"
#include ".\ApplicationManager.h"
#include ".\GUI\GUI.h"
#include <iostream>


int ActionPLayWithColors::randomColorsGenerator = 0;
int ActionPLayWithColors::wrong = 0;
int ActionPLayWithColors::right = 0;
ActionPLayWithColors::ActionPLayWithColors(ApplicationManager* pApp) :Action(pApp)
{

}
void ActionPLayWithColors::Execute() {
	//rest counter
	ActionPLayWithColors::wrong = 0;
	ActionPLayWithColors::right = 0;
	//load file saved from draw mode
	//Action* newAct = new ActionLoad(pManager);
	//newAct->Execute();
	pManager->setSelectedCasePlay(2);
	//getting figures color count
	int* figuresColors = new int[5] { 0 };
	pManager->getFiguresColors(figuresColors);
	GUI* pGui = pManager->GetGUI();
	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (figuresColors[i] != 0) {
			count++;
		}
		if (count > 0) break;
	}

	if (count == 0)// if all element is zero then there are no figures
		pGui->PrintMessage("Draw shapes in draw mode first or load a graph:");
	else {
		bool regenerator = true; // randomizing what to choose
		do {
			ActionPLayWithColors::randomColorsGenerator = rand() % 5;
			if( ActionPLayWithColors::randomColorsGenerator == 0 && figuresColors[0] != 0) {
				regenerator = false;
			}
			else if (ActionPLayWithColors::randomColorsGenerator == 1 && figuresColors[1] != 0) {
				regenerator = false;
			}
			else if (ActionPLayWithColors::randomColorsGenerator == 2 && figuresColors[2] != 0) {
				regenerator = false;
			}
			else if (ActionPLayWithColors::randomColorsGenerator == 3 && figuresColors[3] != 0) {
				regenerator = false;
			}
			else if (ActionPLayWithColors::randomColorsGenerator == 4 && figuresColors[4] != 0) {
				regenerator = false;
			}
		} while (regenerator);
		pGui->GetPointClicked(p1.x, p1.y);
		if (ActionPLayWithColors::randomColorsGenerator == 0) {
			pGui->PrintMessage("Pick Red Shapes");
		}
		else if (ActionPLayWithColors::randomColorsGenerator == 1) {
			pGui->PrintMessage("Pick Green Shapes");
		}
		else if (ActionPLayWithColors::randomColorsGenerator == 2) {
			pGui->PrintMessage("Pick Blue Shapes");
		}
		else if (ActionPLayWithColors::randomColorsGenerator == 3) {
			pGui->PrintMessage("Pick Yellow Shapes");
		}
		else if (ActionPLayWithColors::randomColorsGenerator == 4) {
			pGui->PrintMessage("Pick Shapes which are not filled");
		}
	}
}

void ActionPLayWithColors::ExecuteSelected(CFigure* fig)
{
	GUI* pGui = pManager->GetGUI();

	//get figure fill color
	color fill = fig->GetCurrentFillClr();

	//convert color name to string

	string CurrentColor = "";

	if ((fill.ucBlue == HOTBLUE.ucBlue) && (fill.ucGreen == BLUE.ucGreen) && (fill.ucRed == BLUE.ucRed))
		CurrentColor = "HOTBLUE";
	else if ((fill.ucBlue == HOTRED.ucBlue) && (fill.ucGreen == RED.ucGreen) && (fill.ucRed == RED.ucRed))
		CurrentColor = "HOTRED";
	else if ((fill.ucBlue == HOTYELLOW.ucBlue) && (fill.ucGreen == YELLOW.ucGreen) && (fill.ucRed == YELLOW.ucRed))
		CurrentColor = "HOTYELLOW";
	else if ((fill.ucBlue == GREEN.ucBlue) && (fill.ucGreen == GREEN.ucGreen) && (fill.ucRed == GREEN.ucRed))
		CurrentColor = "GREEN";
	else
		CurrentColor = "NO_FILL";

	//delete selected figure

	Action* deletAct = new ActionDelete(pManager);
	deletAct->Execute();

	cout << randomColorsGenerator << endl;

	int* figuresColors = new int[5] {0};

	pManager->getFiguresColors(figuresColors);
	for (int i = 0; i < figuresColors[i]; i++) 
		cout << figuresColors[i] << "";
		cout << CurrentColor << endl;
	
		if (CurrentColor == "HOTRED")
		{       //figure color
			if (ActionPLayWithColors::randomColorsGenerator == 0)
				ActionPLayWithColors::right++;
			else
				ActionPLayWithColors::wrong++;
	    }
		else if (CurrentColor == "HOTGREEN")
		{
			if (ActionPLayWithColors::randomColorsGenerator == 1)
				ActionPLayWithColors::right++;
			else
				ActionPLayWithColors::wrong++;
		}
		else if (CurrentColor == "HOTBLUE")
		{
			if (ActionPLayWithColors::randomColorsGenerator == 2)
				ActionPLayWithColors::right++;
			else
				ActionPLayWithColors::wrong++;
		}
		else if (CurrentColor == "HOTYELLOW")
		{
			if (ActionPLayWithColors::randomColorsGenerator == 3)
				ActionPLayWithColors::right++;
			else
				ActionPLayWithColors::wrong++;
		}
		else {
			if (ActionPLayWithColors::randomColorsGenerator == 4)
				ActionPLayWithColors::right++;
			else
				ActionPLayWithColors::wrong++;
		}

		int count = 0;
		for (int i = 0; i < 5; i++)
		{
			if (figuresColors[i] != 0)
				count++;
			if (count > 0) break;
		}
		if (figuresColors[ActionPLayWithColors::randomColorsGenerator - 1] == 0 || count == 0)
		{
			string message = "You finished . Your grade is" + to_string(ActionPLayWithColors::right) + "/" + to_string((ActionPLayWithColors::wrong + ActionPLayWithColors::right));
			pGui->ClearStatusBar();
			pGui->PrintMessage(message);
		}
		else
		{
			string message = "You picked " + to_string(ActionPLayWithColors::wrong) + " Wrong Shapes and " + to_string(ActionPLayWithColors::right) + " right shapes";
			pGui->ClearStatusBar();
			pGui->PrintMessage(message);
		}
}  