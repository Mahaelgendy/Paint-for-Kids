#include "CTriangle.h"

//constractor
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo) :CFigure(TriaGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	ID = 300 + newID++;
	area = abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0);
}
void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);

}
void CTriangle::Resize(float size)
{
	if (size == 0.5) size = -1;
	else if(size == 0.25) size = -(4.0 / 3);

	Point O;
	O.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	O.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	if (Corner1.x <= O.x)
		Corner1.x -= (O.x - Corner1.x) * size / 2;
	else
		Corner1.x += (Corner1.x - O.x) * size / 2;

	if (Corner2.x <= O.x)
		Corner2.x -= (O.x - Corner2.x) * size / 2;
	else
		Corner2.x += (Corner2.x - O.x) * size / 2;

	if (Corner3.x <= O.x)
		Corner3.x -= (O.x - Corner3.x) * size / 2;
	else
		Corner3.x += (Corner3.x - O.x) * size / 2;

	if (Corner1.y <= O.y)
		Corner1.y -= (O.y - Corner1.y) * size / 2;
	else
		Corner1.y += (Corner1.y - O.y) * size / 2;

	if (Corner2.y <= O.y)
		Corner2.y -= (O.y - Corner2.y) * size / 2;
	else
		Corner2.y += (Corner2.y - O.y) * size / 2;

	if (Corner3.y <= O.y)
		Corner3.y -= (O.y - Corner3.y) * size / 2;
	else
		Corner3.y += (Corner3.y - O.y) * size / 2;

	//to complete

}
void CTriangle::PrintInfo(GUI* pOut)
{
	pOut->PrintMessage(std::string("Triangle =>ID: ") +
		std::to_string(ID) + " =>Vertices: ( " + std::to_string(Corner1.x) +
		", " + std::to_string(Corner1.y) + " ), ( " + std::to_string(Corner2.x) +
		", " + std::to_string(Corner2.y) + " ), ( " + std::to_string(Corner3.x) +
		", " + std::to_string(Corner3.y) + " ) =>Area: " + std::to_string(int(area)) );

}
float area2(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool CTriangle::IsInFig(int x, int y) {
	float A = area2(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A1 = area2(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A2 = area2(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float A3 = area2(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}