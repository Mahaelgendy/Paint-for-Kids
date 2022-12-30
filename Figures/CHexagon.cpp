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
bool CHexagon::IsInFig(int x, int y) {
    //// Check length (squared) against inner and outer radius
    //float l2 = x * x + y * y;
    //if (l2 > 1.0f) return false;
    //if (l2 < 0.75f) return true; // (sqrt(3)/2)^2 = 3/4

    //// Check against borders
    //float px = x * 1.15470053838f; // 2/sqrt(3)
    //if (px > 1.0f || px < -1.0f) return false;

    //float py = 0.5f * px + y;
    //if (py > 1.0f || py < -1.0f) return false;

    //if (px - py > 1.0f || px - py < -1.0f) return false;

    return false;
}