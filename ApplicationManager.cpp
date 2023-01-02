#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddTriangle.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionColor.h"
#include "Actions\ActionFillColor.h"
#include "Actions\ActionFillButton.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionResize.h"
#include "Actions\ActionSwitchToDrawMode.h"
#include "Actions\ActionSwitchToPlay.h"
#include "Actions\PickByType.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	filled = false;
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
		case DRAW_TRIG:
			newAct = new ActionAddTriangle(this);
			break;
		case DRAW_ELPS:
			///create AddLineAction here
			newAct = new ActionAddEllipse(this);
			break;
		case DRAW_HEX:
			///create AddLineAction here
			newAct = new ActionAddHexagon(this);
			break;
		case SELECT:
			newAct = new ActionSelect(this);
			break;
		case CHNG_DRAW_CLR:
			newAct = new ActionColor(this);
			break;
		case CHNG_FILL_CLR:
			newAct = new ActionFillColor(this);
			break;
		case SELECT_FILL_COLOR:
			newAct = new ActionFillButton(this);
			break;
		case RESIZE :
			newAct = new ActionResize(this,SelectedFig);
			break;
		case GO_BACK:
			newAct = new ActionSwitchToDrawMode(this);
			break;
		case DEL:
			newAct = new ActionDelete(this);
			break;
		case TO_PLAY:
			newAct = new ActionSwitchToPlay(this);
			break;
		case PLAY_SHAPES:
			newAct = new PickByType(this);
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
int* ApplicationManager::getFigCount() {
	return &FigCount;
};
CFigure** ApplicationManager::getFigList() {
	return FigList;
};
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->HiddenStatus() == false) {
			if (FigList[i]->IsInFig(x, y))
			{
				return FigList[i];
			}
		}
	return NULL;
}
CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
int ApplicationManager::getSelectedFigure()
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}
CFigure* ApplicationManager::GetSelectedFigure() const
{
	//check if a figure selected
	for (int i = (FigCount - 1); i >= 0; i--) {
		if (FigList[i]->IsSelected()) return FigList[i];
	}
	return NULL;
}
CFigure* ApplicationManager::GetNotSelectedFigure() const
{
	//check if a figure selected
	for (int i = (FigCount - 1); i >= 0; i--) {
		if (!FigList[i]->IsSelected()) return FigList[i];
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->HiddenStatus() == false)
			FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::setFillColor(bool _fillColor)
{
	filled = _fillColor;
}

bool ApplicationManager::getFillColor()
{
	return filled;
}


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
