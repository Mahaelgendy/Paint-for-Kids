#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_SIZE,
	MODE_COLOR,
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SQUR,		//Square item in menu
	ITM_ELPS,		//Ellipse item in menu
	ITM_TRIG,		//Tringel item in menu
	ITM_HEXA,		//Hexagon item in menu
	ITM_SELECT,		//Select item in menue
	ITEM_COLOR,		//Color Item in menue
	ITIM_RESIZE,	//Resize Item in menu	
	ITM_TO_FRONT,	//Bring Front Item in menu	
	ITM_TO_BACK,	//Send Back Item in menu	
	ITM_SAVE,		//Save Item in menue
	ITM_LOAD,		//Load Item	in menue
	ITM_DELETE,		//Delete Item in menue
	ITM_PLAY,		//Play Item in menue
	
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};
enum ColorMenuItem
{
	ITM_BORDER,   
	ITM_FILL,
	ITM_BUTTON,
	ITM_BLACK,
	ITM_WHITE,
	ITM_RED,
	ITM_BLUE,
	ITM_GREEN,
	ITM_YELLOW,
	ITM_BACK4,
	COLOR_ITM_COUNT
};
enum SizeMenuItem // The items of colors
{
	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUADRUPLE,

	ITM_BACK2,

	SIZE_ITM_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_SHAPE,
	ITM_COLOR,
	ITM_SHAPE_COLOR,
	ITM_DRAW_BACK,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color ToolBarBkGrndColor;
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif