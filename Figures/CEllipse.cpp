#include "CEllipse.h"
#include<string>
#include<fstream> 
#include <iostream>

//constractor
CEllipse::CEllipse(Point _P1, Point _P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	 P1=_P1;
	P2=_P2;
	ID = 200 + newID++;
	area = 3.1415f * P1.x * P2.x;
}
CEllipse::CEllipse()
{
}
void CEllipse::DrawMe(GUI* pGUI) const
{
	//DrawEllipse(const int iX1, const int iY1, const int iX2, const int iY2, const drawstyle dsStyle)

	pGUI->DrawEllipse(P1, P2, FigGfxInfo, Selected);
}
void CEllipse::Resize(float size) {
	this->P2.x = this->P2.x * size;
	this->P2.y = this->P2.y * size;

}
void CEllipse::PrintInfo(GUI* pOut)
{
	Point center;
	center.x = 0.5 * (P2.x + P1.x);
	center.y = 0.5 * (P2.y + P1.y);

	pOut->PrintMessage(string("Ellipse =>ID: ") + to_string(ID) + 
		" =>Width: " + to_string(abs(P1.x - P2.x)) +
		" =>Height: " + std::to_string(std::abs(P1.y - P1.y)) +
		" =>Area: " + std::to_string(area) +
		" =>center: ( " + std::to_string(center.x) +
		", " + to_string(center.y) + " )");
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
void CEllipse::Save(ofstream& File)
{
	File << "Elipse \t" << ID << "\t" << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t"
		<< convertColortoString(FigGfxInfo.DrawClr) << "\t";
		if (this->FigGfxInfo.isFilled)
			File << this->convertColortoString(this->FigGfxInfo.FillClr) << "\n";
		else
			File << "NON-FILLED\n";
}
void CEllipse::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->P1.x >> this->P1.y >> this->P2.x >> this->P2.y;
	cout << "ID" << this->ID << "p1x" << this->P1.x << "p1y" << this->P1.y;
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
