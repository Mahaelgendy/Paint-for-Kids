#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2, Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool IsInFig(int, int);
	virtual void Resize(float);
	virtual void PrintInfo(GUI* pOut);
	virtual void Save(ofstream& File);
	virtual void Load(ifstream& Infile);

};

#endif