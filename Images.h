#ifndef IMG_H
#define IMG_H

#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include "TXgrap.h"
//#include "Vector.h"

#define TIME		GetTickCount()/100
#define KEY			GetAsyncKeyState
#define uint 		unsigned int //govnokode for compare with vector.size()
#define RADI_MASS   20

class ImageSheet {
    public:
    HDC image;
    int posX, posY;
    int dX, dY;
    int nX, nY;

    ImageSheet(char* imageName, int deltaX, int deltaY, int sizeX, int sizeY) {
        image = loadImage(imageName);
        dX = deltaX;
        dY = deltaY;
        posX = 0;
        posY = 0;
        nX = sizeX;
        nY = sizeY;
    }

    void draw(int x, int y, int xMove = 0, int yMove = 0) {
        txTransparentBlt(getDC(), x, y, dX, dY, image, (posX+xMove)*dX, (posY+yMove)*dY, RGB(0,96,64));
    }

    void moveRight() {
        posX += 1;
        if(posX == nX/dX) posX = 0;
    }

    void moveLeft() {
        posX -= 1;
        if(posX < 0) posX = nX/dX - 1;
    }

    void mouseMagic(float x, float y) {
        char a[20];
        float f = 0.0;
        x+= dX/2.0;
        y+= dY/2.0;
        if(MouseX() == x) f = 90.0;
        else f = atan((MouseY() - y)/(MouseX() - x)*-1)*180/M_PI;
		sprintf(a, "%f;%f", MouseX() - x, MouseY() - y);
		//txLine((double)x,(double)y,MouseX(),MouseY());
		//textOut(1000, 50, a);
    }

    ~ImageSheet() {
        txDeleteDC(image);
    }
};


#endif
