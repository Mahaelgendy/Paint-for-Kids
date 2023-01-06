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
CEllipse::CEllipse() //default constructor, We need it to Load
{
}
void CEllipse::DrawMe(GUI* pGUI) const
{	//Call GUI::DrawEllipse to draw a ellipse on the screen
	pGUI->DrawEllipse(P1, P2, FigGfxInfo, Selected);
}
int CEllipse::Resize(float size)  //to increase and decrease size of figer
{
	float centreX = (this->P2.x + this->P1.x) / 2;
	float centreY = (this->P2.y + this->P1.y) / 2;
	float radius = abs(centreX - this->P1.x);
	int newRadius= radius * size;

	int newP2X = centreX + newRadius;
	int newP2Y = centreY + 0.5*newRadius;
	int newP1X = centreX - newRadius;
	int newP1Y = centreY - 0.5*newRadius;

	int leftCornerX = newP2X + 0.0*newRadius;
	int leftCornerY = newP2Y + 0*newRadius;
	int rightCornerX = newP1X - 0.0*newRadius;
	int rightCornerY = newP1Y - 0*newRadius;

	if (leftCornerX < UI.wx || leftCornerX > UI.width + UI.wx) return 1;
	if (rightCornerX < UI.wx || rightCornerX > UI.width + UI.wx) return 1;
	
	this->P2.x = newP2X;
	this->P2.y = newP2Y;
	this->P1.x = newP1X;
	this->P1.y = newP1Y;
	return 0;
	
}
void CEllipse::PrintInfo(GUI* pOut)  //Print Figer Data 
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

bool CEllipse::IsInFig(int x, int y) //Determine the position of the point
{
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
void CEllipse::Save(ofstream& File) //Write Figer Data On File 
{
	File << "Elipse \t" << ID << "\t" << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t"
		<< convertColortoString(FigGfxInfo.DrawClr) << "\t";
		if (this->FigGfxInfo.isFilled)
			File << this->convertColortoString(this->FigGfxInfo.FillClr) << "\n";
		else
			File << "NON-FILLED\n";
}
void CEllipse::Load(ifstream& Infile) //Set the Load Data To figer 
{
	string temp;
	Infile >> this->ID >> this->P1.x >> this->P1.y >> this->P2.x >> this->P2.y;
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
