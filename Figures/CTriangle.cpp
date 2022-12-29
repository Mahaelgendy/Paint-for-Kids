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
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool CTriangle::IsInFig(int x, int y) {
	float A = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float A3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}