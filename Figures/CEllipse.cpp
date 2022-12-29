#include "CEllipse.h"

//constractor
CEllipse::CEllipse(Point _P1, Point _P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	 P1=_P1;
	P2=_P2;
}
void CEllipse::DrawMe(GUI* pGUI) const
{
	//DrawEllipse(const int iX1, const int iY1, const int iX2, const int iY2, const drawstyle dsStyle)

	//Call Output::DrawRect to draw a Square on the screen	
	//pGUI->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
	pGUI->DrawEllipse(P1, P2, FigGfxInfo, Selected);


}