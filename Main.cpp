#include "Tank.h"

#define WIDTH 1300
#define HEIGHT 700

int iRand(int min, int max) {
	return min + rand() % (max - min + 1);
}

int main(int argc, char* argv[]) {
	//vars
	long Time = 0, T0 = 0;
	HWND window = init(WIDTH, HEIGHT);
	Tank tank = Tank(200.0,200.0);
	Time = TIME;
	T0 = Time;
	begin();
	while (!KEY(VK_ESCAPE)) {
		resetCol();
		clear();
		tank.draw();
		tank.inter();
		gsleep(10);
	}
	end();
	return 0;
}
