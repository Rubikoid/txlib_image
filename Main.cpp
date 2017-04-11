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
        tank.draw(200,200);
        tank.draw(200,200, 0, 1);
        char a[20];
		sprintf(a, "%d;%d;\n%d;%d", MouseX(), MouseY());
		textOut(1000, 50, a);
        if(KEY(VK_RIGHT)) tank.moveRight();
        else if(KEY(VK_LEFT)) tank.moveLeft();
        gsleep(10);
    }
    end();
    return 0;
}
