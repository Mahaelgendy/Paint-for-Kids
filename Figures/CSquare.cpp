#include "CSquare.h"
#include <fstream>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	area = float(abs((TopLeftCorner.x - (TopLeftCorner.x+ length)) * (TopLeftCorner.y - (TopLeftCorner.y + length))));
	ID = 100+ newID++;
	
}
	

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
	File << "Square\n" << ID << "\t" << TopLeftCorner.x << "\t" << TopLeftCorner.y << "\t" << length 
		<< convertColortoString(FigGfxInfo.DrawClr) << "\t"
		<< convertColortoString(FigGfxInfo.FillClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->convertColortoString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "NON-FILLED\n";
}