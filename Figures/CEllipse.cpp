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

	pGUI->DrawEllipse(P1, P2, FigGfxInfo, Selected);


}
bool CEllipse::IsInFig(int x, int y) {
	if (pow(x - P1.x, 2) / pow(P2.x, 2) + pow(y - P1.y, 2) / pow(P2.y, 2) <= 1)
	{
		return true;
	}
	return false;
}