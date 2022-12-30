#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
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
	if (
		(x >= min(TopLeftCorner.x,( TopLeftCorner.x + length) ) &&
			x <= max(TopLeftCorner.x, (TopLeftCorner.x + length) ) &&
			y >= min(TopLeftCorner.x, (TopLeftCorner.x + length) ) &&
			y <= max(TopLeftCorner.x, (TopLeftCorner.x + length) )
		)
		)
	{
		return true;
	}
	return false;
}