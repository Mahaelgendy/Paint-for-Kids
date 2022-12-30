#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point P1;
	Point P2;
public:
		CEllipse(Point, Point, GfxInfo );
		virtual void DrawMe(GUI* pOut) const;
		virtual bool IsInFig(int, int);
		virtual void Resize(float);
};

#endif