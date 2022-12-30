#include "CHexagon.h"

CHexagon::CHexagon(Point P1, int HorizentalLength, int VertivalLength, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	VerticalLen = VertivalLength;
	HorizentalLen = HorizentalLength;
}
	

void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(TopLeftCorner, VerticalLen,HorizentalLen, FigGfxInfo, Selected);
}
void CHexagon::Resize(float size) {
    this->VerticalLen = this->VerticalLen * size;
    this->HorizentalLen = this->HorizentalLen * size;
}
bool CHexagon::IsInFig(int x, int y) {
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