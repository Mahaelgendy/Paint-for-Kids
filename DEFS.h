#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square
	DRAW_ELPS,		//Draw an Ellipse
	DRAW_TRIG,		//Draw an Triangle
	DRAW_HEX,		//Draw a Hexagon
	TO_COLOR,
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	SELECT,			//Select figer(s)
	GO_BACK,
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SELECT_FILL_COLOR,
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,     	//Switch interface to Play mode

	///TODO: Add more action types (if needed)
	TO_SIZE,
	HALF,
	QUARTER,
	DOUBLE1,
	QUADRUPLE,
	BACK2,
	BACK4,
	PLAY_SHAPES,    //play with only shapes
	PLAY_COLORS,	//play with only colors
	PLAY_SHAPES_COLORS,
	_BLACK,
	_WHITE,
	_RED,
	_BLUE,
	_GREEN,
	_YELLOW,
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif