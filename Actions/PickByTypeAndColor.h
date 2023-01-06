
#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByTypeAndColor :
	public Action

{
	CFigure* Fig;
	Point P;
	int  figuresNumber, randomFigNumber, pickedFigNumber, numberOfRightFig, numberOfWrongFig;
	int combinations[23];
	void PrintScore(int);

public:
	PickByTypeAndColor(ApplicationManager*);
	~PickByTypeAndColor();
	void ReadActionParameters();
	void Execute();
};

