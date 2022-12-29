#include "CTriangle.h"

//constractor
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo) :CFigure(TriaGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);



}