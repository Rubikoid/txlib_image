#ifndef TANK_H
#define TANK_H
#include "Images.h"
class Tank : public base {
public:
	ImageSheet img;
	DWORD moveTime;
	int god;

	Tank(double startX, double startY, int _god = 0) : base(V2Pos(Vector2(64, 64), Vector2(startX, startY))), img("tank.bmp", 64, 64, 1024, 128) {
		moveTime = TIME;
		god = _god;
	}

	Tank(double startX, double startY, HDC *_img, int _god = 0) : base(V2Pos(Vector2(64, 64), Vector2(startX, startY))), img(_img, 64, 64, 1024, 128) {
		moveTime = TIME;
		god = _god;
	}

	void collide(base *with) { 
		with->destroyed = true;
	}

	void update() {
		/*if (MouseButt() & 1) {
		shotX = posX + img.dX / 2.0;
		shotY = posY + img.dY / 2.0;
		destShotF = angleMagic(shotX, shotY, MouseX(), MouseY());
		shotTime = TIME;
		}*/
		if (TIME - this->moveTime > 0.5) {
			if (KEY(0x44)) { //D key
				this->img.moveRight();
			}
			else if (KEY(0x41)) {//A key
				this->img.moveLeft();
			}
			this->moveTime = TIME;
		}
		if (KEY(0x57)) { //W key
			bnds.pos.x += sin((this->img.posX * 22.5)*M_PI / 180) * 5;
			bnds.pos.y -= cos((this->img.posX * 22.5)*M_PI / 180) * 5;
		}
		else if (KEY(0x53)) { //S key
			bnds.pos.x -= sin((this->img.posX * 22.5)*M_PI / 180) * 5;
			bnds.pos.y += cos((this->img.posX * 22.5)*M_PI / 180) * 5;
		}
	}

	void draw() {
		int angle = this->img.mouseMagic(bnds.pos.x, bnds.pos.y);
		if (angle >= 352) angle = 351;
		this->img.draw(bnds.pos.x, bnds.pos.y);
		this->img.draw(bnds.pos.x, bnds.pos.y, angle / 22, 1);
	}

	~Tank()
	{
		this->img.~ImageSheet();
	}
};

#endif
