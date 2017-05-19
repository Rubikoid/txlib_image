#ifndef TANK_H
#define TANK_H
#include "Images.h"
class Tank {
public:
	ImageSheet img;
	DWORD moveTime;
	DWORD shotTime;
	double posX, posY;
	double shotX, shotY;
	double destShotF;

	Tank(double startX, double startY) : img("tank.bmp", 64, 64, 1024, 128) {
		posX = startX;
		posY = startY;
		moveTime = TIME;
		shotTime = -1;
		shotX = -1;
		shotY = -1;
		destShotF = -2;
	}

	void draw() {
		int angle = img.mouseMagic(posX, posY);
		if (angle >= 352) angle = 351;
		img.draw(posX, posY);
		img.draw(posX, posY, angle / 22, 1);
		if (shotTime != -1) txCircle(shotX, shotY, 4);
	}

	void inter() {
		if (shotTime != -1 && TIME - shotTime > 20) {
			shotTime = -1;
			shotX = -1;
			shotY = -1;
			destShotF = -2;
		}
		else if(shotTime != -1) {
			shotX += sin(destShotF*M_PI / 180.0) * 8;
			shotY -= cos(destShotF*M_PI / 180.0) * 8;
		}
		if (MouseButt() & 1) {
			shotX = posX + img.dX / 2.0;
			shotY = posY + img.dY / 2.0;
			destShotF = angleMagic(shotX, shotY, MouseX(), MouseY());
			shotTime = TIME;
		}
		if (TIME - moveTime > 0.5) {
			if (KEY(0x44)) { //D key
				img.moveRight();
			}
			else if (KEY(0x41)) {//A key
				img.moveLeft();
			}
			moveTime = TIME;
		}
		if (KEY(0x57)) { //W key
			posX += sin((img.posX * 22.5)*M_PI / 180) * 5;
			posY -= cos((img.posX * 22.5)*M_PI / 180) * 5;
		}
		else if (KEY(0x53)) { //S key
			posX -= sin((img.posX * 22.5)*M_PI / 180) * 5;
			posY += cos((img.posX * 22.5)*M_PI / 180) * 5;
		}
	}
};

#endif
