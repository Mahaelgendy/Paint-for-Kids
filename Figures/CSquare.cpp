#include "CSquare.h"
#include <fstream>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	area = float(abs((TopLeftCorner.x - (TopLeftCorner.x+ length)) * (TopLeftCorner.y - (TopLeftCorner.y + length))));
	ID = 100+ newID++;
	
}
CSquare::CSquare()
{}

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}
void CSquare::Resize(float size) {
	this->length = this->length * size;

}
bool CSquare::IsInFig(int x, int y) {
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}
void CSquare::PrintInfo(GUI* pOut)
{
	pOut->PrintMessage(string("Square =>ID: ") + to_string(ID) +
		" =>Width: " + std::to_string(
			abs( (TopLeftCorner.x - (TopLeftCorner.x + length)) )
			) +
			" =>Height: " + std::to_string(abs((TopLeftCorner.y - (TopLeftCorner.y + length)))) +
			" =>Area: " + std::to_string(int(area)));
}
void CSquare::Save(ofstream& File)
{
	File << "Square\t" << ID << "\t" << TopLeftCorner.x << "\t" << TopLeftCorner.y << "\t" << length << "\t"
		<< convertColortoString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->convertColortoString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "NON-FILLED\n";
}
void CSquare::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->TopLeftCorner.x >> this->TopLeftCorner.y >> this->length;

	Infile >> temp;
	this->FigGfxInfo.DrawClr = convertStringtoColor(temp);

	Infile >> temp;
	if (temp == "NON-FILLED")
		this->FigGfxInfo.isFilled = false;
	else
	{
		this->FigGfxInfo.FillClr = convertStringtoColor(temp);
		this->FigGfxInfo.isFilled = true;
	}
	this->FigGfxInfo.BorderWdth = 3;
	this->Selected = false;
}