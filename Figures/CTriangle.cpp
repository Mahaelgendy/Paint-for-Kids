#include "CTriangle.h"
#include <fstream>
#include <iostream>
//constractor
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo) :CFigure(TriaGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	ID = 300 + newID++;
	area = abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0);
}
CTriangle::CTriangle()
{}
void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);

}
int CTriangle::Resize(float size)
{
	Point newCorner1 = Corner1;
	Point newCorner2 = Corner2;
	Point newCorner3 = Corner3;

	if (size == 0.5) size = -1;
	else if(size == 0.25) size = -(4.0 / 3);

	Point O;
	O.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	O.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	if (newCorner1.x <= O.x)
		newCorner1.x -= (O.x - newCorner1.x) * size / 2;
	else
		newCorner1.x += (newCorner1.x - O.x) * size / 2;

	if (newCorner2.x <= O.x)
		newCorner2.x -= (O.x - newCorner2.x) * size / 2;
	else
		newCorner2.x += (newCorner2.x - O.x) * size / 2;

	if (newCorner3.x <= O.x)
		newCorner3.x -= (O.x - newCorner3.x) * size / 2;
	else
		newCorner3.x += (newCorner3.x - O.x) * size / 2;

	if (newCorner1.y <= O.y)
		newCorner1.y -= (O.y - newCorner1.y) * size / 2;
	else
		newCorner1.y += (newCorner1.y - O.y) * size / 2;

	if (newCorner2.y <= O.y)
		newCorner2.y -= (O.y - newCorner2.y) * size / 2;
	else
		newCorner2.y += (newCorner2.y - O.y) * size / 2;

	if (newCorner3.y <= O.y)
		newCorner3.y -= (O.y - newCorner3.y) * size / 2;
	else
		newCorner3.y += (newCorner3.y - O.y) * size / 2;
	
	if (newCorner1.y < UI.StatusBarHeight || newCorner1.y > UI.height - UI.StatusBarHeight)return 1;
	if (newCorner2.y < UI.StatusBarHeight || newCorner2.y > UI.height - UI.StatusBarHeight) return 1;
	if (newCorner3.y < UI.StatusBarHeight || newCorner3.y > UI.height - UI.StatusBarHeight) return 1;
	if (newCorner1.x < UI.wx || newCorner1.x > UI.width + UI.wx) return 1;
	if (newCorner2.x < UI.wx || newCorner2.x > UI.width + UI.wx) return 1;
	if (newCorner3.x < UI.wx || newCorner3.x > UI.width + UI.wx) return 1;
	
	Corner1 = newCorner1;
	Corner2 = newCorner2 ;
	Corner3 = newCorner3;
	return 0;
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
void CTriangle::Save(ofstream& File)
{
	File << "Triangle\t" << ID << "\t" << Corner1.x << "\t"
		<< Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y
		<< "\t" << Corner3.x << "\t" << Corner3.y << "\t"
		<< convertColortoString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->convertColortoString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "NON-FILLED\n";

}
void CTriangle::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->Corner1.x >> this->Corner1.y >> this->Corner2.x >> this->Corner2.y >> this->Corner3.x >> this->Corner3.y;
	Infile >> temp;
	this->FigGfxInfo.DrawClr = convertStringtoColor(temp);
	Infile >> temp;
	if (temp == "NON-FILLED") {
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.FillClr = convertStringtoColor(temp);
		this->FigGfxInfo.isFilled = true;
		cout << "fall";
	}
	this->Selected = false;
	this->FigGfxInfo.BorderWdth = 3;
}