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
    Point center;
    center.x = 0.5 * (P2.x + P1.x);
    center.y = 0.5 * (P2.y + P1.y);
    float a = abs(P2.x - P1.x) / 2;
    float b = abs(P2.y - P1.y) / 2;
    float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
    if (check <= 1)
        return true;

    return false;
}