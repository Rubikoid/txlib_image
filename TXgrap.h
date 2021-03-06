#ifndef GRAP_H
#define GRAP_H

#include <stdio.h>
#include "TXLib.h"

void resetCol();
void clear();
void begin();
void end();
void gsleep(int sleep);
void textOut(int x, int y, char *text);
int MouseButt();
int MouseX();
int MouseY();
void boxColor();
HDC loadImage(char* imageName);
HDC& getDC();

HWND init(int x, int y)
{
    HWND desc = txCreateWindow(x,y, true);
    txTextCursor(false);
    resetCol();
    txClear();
	return desc;
}

void resetCol()
{
    txSetFillColour(RGB(50,50,50));
    txSetColor(TX_WHITE, 1);
}

void boxColor() {
    txSetFillColour(RGB(50,50,50));
    txSetColor(TX_WHITE, 3);
}

void clear(){txClear();}
void begin(){txBegin();}
void end(){txEnd();}
void gsleep(int sleep){txSleep(sleep);}
void textOut(int x, int y, char *text){txTextOut(x, y, text);}
int MouseButt(){return txMouseButtons();}
int MouseX(){return txMouseX();}
int MouseY(){return txMouseY();}
HDC loadImage(char* imageName) {return txLoadImage(imageName);}
HDC& getDC(){return txDC();}

#endif
