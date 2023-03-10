#include "CHexagon.h"
#include <math.h>
#include<fstream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
CHexagon::CHexagon(Point P1, int HorizentalLength, int VertivalLength, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	VerticalLen = VertivalLength;
	HorizentalLen = HorizentalLength;
	ID = 400 + newID++;
	area = (6 * (VerticalLen * VerticalLen)) / (4.0 * tan((M_PI / 6)));
		
}
//////////////////////////////////////////////////////////////////////////////////////////////
CHexagon::CHexagon(){
} //default constructor, We need it to Load
	
//////////////////////////////////////////////////////////////////////////////////////////////
void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawHexagon to draw a Square on the screen	
	pGUI->DrawHexagon(TopLeftCorner, VerticalLen,HorizentalLen, FigGfxInfo, Selected);
}
int CHexagon::Resize(float size) {  
	int newVerLen = this->VerticalLen * size ;
	int newHor = this->HorizentalLen * size;

	float maxHorLen = TopLeftCorner.x + 1.5 * newHor;
	float minHorLen = abs(TopLeftCorner.x - 0.5 * newHor);
	float maxVerLen = TopLeftCorner.y + 2 * newVerLen;

	if (minHorLen < UI.wx || maxHorLen > UI.width + UI.wx || maxVerLen < UI.StatusBarHeight || maxVerLen > UI.height - UI.StatusBarHeight)
	{
		return 1;
	}
	else {
		this->VerticalLen= newVerLen;
		this->HorizentalLen = newHor;
		return 0;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
bool CHexagon::IsInFig(int x, int y) {  //Determine the position of the point
	boolean c = false;
	int vertexX[6] = { TopLeftCorner.x, TopLeftCorner.x + HorizentalLen , TopLeftCorner.x + (1.5 * HorizentalLen), (TopLeftCorner.x + HorizentalLen), TopLeftCorner.x, abs(TopLeftCorner.x - (0.5 * HorizentalLen)) };
	int vertexY[6] = { TopLeftCorner.y,TopLeftCorner.y, TopLeftCorner.y + VerticalLen, TopLeftCorner.y + (2 * VerticalLen), TopLeftCorner.y + (2 * VerticalLen), abs(TopLeftCorner.y + VerticalLen) };
	for (int i = 0, j = 6 - 1; i < 6; j = i++)
	{
		if (((vertexY[i] > y) != (vertexY[j] > y))
			&& (x < (vertexX[j] - vertexX[i]) * (y - vertexY[i]) / (vertexY[j] - vertexY[i]) + vertexX[i]))
			c = !c;
	}
	return c;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void CHexagon::PrintInfo(GUI* pOut)   //Print Figer Data 
{
	pOut->PrintMessage(string(
		"Hexagon =>ID: ") + to_string(ID) +
		" =>Width: " + std::to_string(HorizentalLen) +
		" =>Height: " + std::to_string(VerticalLen) +
		" =>Area: " + std::to_string(int(area))
		);
}
//////////////////////////////////////////////////////////////////////////////////////////////
void CHexagon::Save(ofstream& File)  //Write Figer Data On File 
{
	File << "Hexagon\t" << ID << "\t" << TopLeftCorner.x << "\t" << TopLeftCorner.y << "\t" << VerticalLen << "\t" << HorizentalLen << "\t"
	<< convertColortoString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->convertColortoString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "NON-FILLED\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////
 void CHexagon::Load(ifstream& Infile)  //Set the Load Data To figer 
{
	 string temp;
	 Infile >> this->ID >> this->TopLeftCorner.x >> this->TopLeftCorner.y >> this->VerticalLen >> this->HorizentalLen ;
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
	 }
	 this->Selected = false;
	 this->FigGfxInfo.BorderWdth = 3;
}
