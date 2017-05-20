#include "TankShotController.h"

#define WIDTH 1300
#define HEIGHT 700

int iRand(int min, int max) {
	return min + rand() % (max - min + 1);
}

int main(int argc, char* argv[]) {
	//vars
	long Time = 0, T0 = 0;
	HWND window = init(WIDTH, HEIGHT);
	HDC image = loadImage("tank.bmp");
	ObjController ctrl = ObjController();
	ctrl.addObj(new Tank(200.0, 200.0, &image));
	ctrl.addObj(new Tank(400.0, 400.0, &image));
	Time = TIME;
	T0 = Time;
	begin();
	while (!KEY(VK_ESCAPE)) {
		resetCol();
		clear();
		ctrl.update();
		gsleep(10);
	}
	end();
	return 0;
}
