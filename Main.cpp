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
    init(WIDTH, HEIGHT);
    ImageSheet tank = ImageSheet("tank.bmp", 64, 64, 1024, 128);
    Time = TIME;
    T0 = Time;
    begin();
    while(!KEY(VK_ESCAPE)) {
        resetCol();
        clear();
        char a[20];
        float f = 0.0;
        if(MouseX() == 200) f = 90.0;
        else f = atan((MouseY() - 200.0)/(MouseX() - 200.0)*-1)*180/M_PI;
		sprintf(a, "%d;%d;%d", MouseX() - 200, MouseY() - 200, (int)fmod(f,22.5f));
		txLine(200,200,MouseX(),MouseY());
		textOut(1000, 50, a);
        tank.draw(200,200);
        tank.draw(200,200, 0, 1);
        if(KEY(VK_RIGHT)) tank.moveRight();
        else if(KEY(VK_LEFT)) tank.moveLeft();
        gsleep(10);
    }
    end();
    return 0;
}
