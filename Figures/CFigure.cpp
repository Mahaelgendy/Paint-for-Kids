#include "CFigure.h"
#include <ostream>


CFigure::CFigure()
{
	PlayHidden = false;
	Selected = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	PlayHidden = false;
	ID = 0;  
	area = 0.0f;
	center = { 0, 0 };
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


void CFigure::PrintInfo(GUI* pOut)
{
}
//Hides Figures
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}
//Gives Current Status
bool CFigure::HiddenStatus() const
{
	return PlayHidden;
}

GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}
//////////////////////////////////////////////////////////////////////////////////////////////
color CFigure::convertStringtoColor(string colorName) const
{
	//Function to Convert  String to Object Color --->  We Need It on Load
	if (colorName == "BLUE")  return BLUE;
	if (colorName == "BLACK") return BLACK;
	if (colorName == "BLUE")  return BLUE;
	if (colorName == "WHITE") return WHITE;
	if (colorName == "RED") return RED;
	if (colorName == "YELLOW") return YELLOW;
	if (colorName == "GREEN") return GREEN;
	if (colorName == "MAGENTA") return MAGENTA;
	if (colorName == "TURQUOISE") return TURQUOISE;
	if (colorName == "GOLD") return GOLD;
	if (colorName == "PERU") return PERU;
	if (colorName == "TAN") return TAN;
	if (colorName == "LIGHTCORAL") return LIGHTCORAL;
	if (colorName == "PINK") return PINK;
	if (colorName == "CHOCOLATE") return CHOCOLATE;
	if (colorName == "ORANGE") return ORANGE;
	if (colorName == "PURPLE") return PURPLE;
	if (colorName == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
	return BLACK;
}
//////////////////////////////////////////////////////////////////////////////////////////////
string CFigure::convertColortoString(color c) const
{
	//Function to Convert   Object Color to String  --->  We Need It on Save
	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
		return "BLACK";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";
	if ((c.ucBlue == LIGHTGOLDENRODYELLOW.ucBlue) && (c.ucGreen == LIGHTGOLDENRODYELLOW.ucGreen) && (c.ucRed == LIGHTGOLDENRODYELLOW.ucRed))
		return "LIGHTGOLDENRODYELLOW";
	if ((c.ucBlue == MAGENTA.ucBlue) && (c.ucGreen == MAGENTA.ucGreen) && (c.ucRed == MAGENTA.ucRed))
		return "MAGENTA";
	if ((c.ucBlue == TURQUOISE.ucBlue) && (c.ucGreen == TURQUOISE.ucGreen) && (c.ucRed == TURQUOISE.ucRed))
		return "TURQUOISE";
	if ((c.ucBlue == SKYBLUE.ucBlue) && (c.ucGreen == SKYBLUE.ucGreen) && (c.ucRed == SKYBLUE.ucRed))
		return "SKYBLUE";
	if ((c.ucBlue == LIGHTSTEELBLUE.ucBlue) && (c.ucGreen == LIGHTSTEELBLUE.ucGreen) && (c.ucRed == LIGHTSTEELBLUE.ucRed))
		return "LIGHTSTEELBLUE";
	if ((c.ucBlue == IVORY.ucBlue) && (c.ucGreen == IVORY.ucGreen) && (c.ucRed == IVORY.ucRed))
		return"IVORY";
	if ((c.ucBlue == PINK.ucBlue) && (c.ucGreen == PINK.ucGreen) && (c.ucRed == PINK.ucRed))
		return"PINK";
	if ((c.ucBlue == CHOCOLATE.ucBlue) && (c.ucGreen == CHOCOLATE.ucGreen) && (c.ucRed == CHOCOLATE.ucRed))
		return"CHOCOLATE";
	if ((c.ucBlue == TURQUOISE.ucBlue) && (c.ucGreen == TURQUOISE.ucGreen) && (c.ucRed == TURQUOISE.ucRed))
		return"TURQUOISE"; 
	if ((c.ucBlue == ORANGE.ucBlue) && (c.ucGreen == ORANGE.ucGreen) && (c.ucRed == ORANGE.ucRed))
		return"ORANGE";
	if ((c.ucBlue == PURPLE.ucBlue) && (c.ucGreen == PURPLE.ucGreen) && (c.ucRed == PURPLE.ucRed))
		return"PURPLE";

	return "COLOR";
}
