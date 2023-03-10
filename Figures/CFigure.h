#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

static int newID = 0; //used to increments ID's
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	GUI* pOut;
	float area;
	Point center;
	bool PlayHidden;
	

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	void Hide();
	void Show();
	bool HiddenStatus() const;

	GfxInfo GetGfxInfo()const;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool IsInFig(int, int) = 0;//Take a point -->Return True if the point in figer area  or  Flase if is not 
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	virtual int Resize(float) = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	virtual void Save(ofstream &File) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &File) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(GUI* pOut);	//print all figure info on the status bar

	color convertStringtoColor(string) const;  // Convert  String to Object Color ---> 
	string convertColortoString(color) const; //Convert   Object Color to String  --->  

};

#endif