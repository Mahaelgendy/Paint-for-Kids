#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	CSquare();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool IsInFig(int, int);
	virtual int Resize(float);
	virtual void PrintInfo(GUI* pOut);
	virtual void Save(ofstream& File);
	virtual void Load(ifstream& Infile);

};

#endif