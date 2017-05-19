#include <cmath>
#include "Images.h"

#define WIDTH 1300
#define HEIGHT 700

int iRand(int min, int max) {
    return min + rand() % (max-min+1);
}

int main(int argc, char* argv[]) {
    //vars
    long Time = 0, T0 = 0;
    HWND windows = init(WIDTH, HEIGHT);
    ImageSheet tank = ImageSheet("tank.bmp", 64, 64, 1024, 128);
    Time = TIME;
    T0 = Time;
    begin();
    while(!KEY(VK_ESCAPE)) {
        resetCol();
        clear();
        int angle = tank.mouseMagic(200.0,200.0);
		if (angle >= 352) angle = 351;
		tank.draw(200,200);
        tank.draw(200,200, angle/22, 1);
        if(KEY(VK_RIGHT)) tank.moveRight();
        else if(KEY(VK_LEFT)) tank.moveLeft();
        gsleep(10);
    }
	end();
	return 0;
}
