#include <cmath>
#include "Images.h"

#define WIDTH 1300
#define HEIGHT 700

int iRand(int min, int max) {
	return min + rand() % (max - min + 1);
}

int main(int argc, char* argv[]) {
	//vars
	long Time = 0, T0 = 0;
	HWND window = init(WIDTH, HEIGHT);
	ImageSheet tank = ImageSheet("tank.bmp", 64, 64, 1024, 128);
	Time = TIME;
	T0 = Time;
	begin();
	double posX = 200.0, posY = 200.0;
	while (!KEY(VK_ESCAPE)) {
		resetCol();
		clear();
		int angle = tank.mouseMagic(posX, posY);
		if (angle >= 352) angle = 351;
		tank.draw(posX, posY);
		tank.draw(posX, posY, angle / 22, 1);
		if (TIME - Time > 0.5) {
			if (KEY(VK_RIGHT)) {
				tank.moveRight();
			}
			else if (KEY(VK_LEFT)) {
				tank.moveLeft();
			}
			Time = TIME;
		}
		if (KEY(VK_UP)) {
			posX += sin((tank.posX * 22.5)*M_PI / 180) * 5;
			posY -= cos((tank.posX * 22.5)*M_PI / 180) * 5;
		}
		gsleep(10);
	}
	end();
	return 0;
}
