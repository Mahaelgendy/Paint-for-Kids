#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"


class ActionPickByColor :public Action {
	CFigure* Fig;
	Point P;
	int ColorsNumber, pickedColorNumber, numberOfWrongColor, numberOfRightColor, randomFigNumber;
	int ColorsList[7];
	color AssignColor(CFigure*);
	void PrintScore(int);

public:
	ActionPickByColor(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
};
