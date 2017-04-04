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
    ImageSheet img = ImageSheet("tank.bmp",128, 128, 2176, 384);
    Time = TIME;
    T0 = Time;
    begin();
    while(!KEY(VK_ESCAPE)) {
        resetCol();
        clear();
        img.draw(200,200);
        if(KEY(VK_RIGHT)) img.moveRight();
        else if(KEY(VK_LEFT)) img.moveLeft();
        gsleep(10);
    }
    end();
    return 0;
}
