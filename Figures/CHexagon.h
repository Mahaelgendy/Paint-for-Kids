#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;	
	int VerticalLen;
	int HorizentalLen;
public:
	CHexagon(Point , int,int, GfxInfo FigureGfxInfo );
	CHexagon();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool IsInFig(int, int);
	virtual int Resize(float);
	virtual void PrintInfo(GUI* pOut);
	virtual void Save(ofstream& File);
	virtual void Load(ifstream& Infile);



};

#endif