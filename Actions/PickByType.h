#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class PickByType : public Action
{
	CFigure* Fig;
	Point P;
	int figuresNumber, pickedFigNumber, numberOfWrongFig, numberOfRightFig, randomFigNumber;
	int FigsList[4];
	void PrintScore(int);

	public:
		PickByType(ApplicationManager*);
		void ReadActionParameters();
		void Execute();
};