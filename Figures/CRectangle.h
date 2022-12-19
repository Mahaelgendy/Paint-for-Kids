#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point TopLeftCorner;	
	Point LowerRightCorner;	
public:
	CRectangle(Point ,Point, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
};

#endif