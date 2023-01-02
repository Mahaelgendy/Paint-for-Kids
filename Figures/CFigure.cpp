#include "CFigure.h"


CFigure::CFigure()
{
	PlayHidden = false;
	Selected = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	PlayHidden = false;
	ID = 0;
	area = 0.0f;
	center = { 0, 0 };
	
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


void CFigure::PrintInfo(GUI* pOut)
{
}
//Hides Figures
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}
//Gives Current Status
bool CFigure::HiddenStatus() const
{
	return PlayHidden;
}

