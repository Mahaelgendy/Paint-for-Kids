#include "CRectangle.h"

CRectangle::CRectangle(Point P1,Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	LowerRightCorner = P2;
}
	

void CRectangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawRectangle(TopLeftCorner, LowerRightCorner, FigGfxInfo, Selected);
	

}