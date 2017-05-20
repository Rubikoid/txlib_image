#ifndef IMG_H
#define IMG_H

#include "Balls.h"

double angleMagic(double fromX, double fromY, double toX, double toY);

double angleMagic(double fromX, double fromY, double toX, double toY) {
	double f = 0.0;
	f = atan2((toY - fromY)*-1, toX - fromX) * 180 / M_PI;
	f = 90 - f;
	if (f < 0) f = (90 - f*-1) + 270;
	return f;
}

class ImageSheet {
    public:
    HDC image;
    int posX, posY;
    int dX, dY;
    int nX, nY;

    ImageSheet(char* imageName, int deltaX, int deltaY, int sizeX, int sizeY) {
        image = loadImage(imageName);
        dX = deltaX; //size of one
        dY = deltaY;
        posX = 0; //pos in pic
        posY = 0;
        nX = sizeX; //size of pic
        nY = sizeY;
    }

	ImageSheet(HDC *_image, int deltaX, int deltaY, int sizeX, int sizeY) {
		image = *_image;
		dX = deltaX; //size of one
		dY = deltaY;
		posX = 0; //pos in pic
		posY = 0;
		nX = sizeX; //size of pic
		nY = sizeY;
	}
	
	ImageSheet() {}

    void draw(double x, double y, int xMove = -1, int yMove = -1) {
		xMove = xMove == -1 ? posX : xMove;
		yMove = yMove == -1 ? posY : yMove;
        txTransparentBlt(getDC(), x, y, dX, dY, image, xMove*dX, yMove*dY, RGB(0,96,64));
    }

    void moveRight() {
        posX += 1;
        if(posX == nX/dX) posX = 0;
    }

    void moveLeft() {
        posX -= 1;
        if(posX < 0) posX = nX/dX - 1;
    }

    double mouseMagic(double x, double y) {
		x += dX / 2.0;
		y += dY / 2.0;
		double f = angleMagic(x, y, MouseX(), MouseY());
		txLine(x,y,MouseX(),MouseY());
		return f;
	}

    ~ImageSheet() {
        txDeleteDC(image);
    }
};


#endif
