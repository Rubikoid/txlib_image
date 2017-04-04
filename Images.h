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

    void draw(int x, int y) {
        txTransparentBlt(getDC(), x, y, dX, dY, image, posX, posY, TX_WHITE);
    }

    void moveRight() {
        posX += dX;
        if(posX == nX) posX = 0;
    }

    void moveLeft() {
        posX -= dX;
        if(posX < 0) posX = nX-dX;
    }

    ~ImageSheet() {
        txDeleteDC(image);
    }
};


#endif
