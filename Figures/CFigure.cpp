#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = 0;
	area = 0.0f;
	pOut = 0;
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

