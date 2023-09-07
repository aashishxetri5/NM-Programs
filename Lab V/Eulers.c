#include <stdio.h>

#define f(x,y) (x + y)

float x;

float eulers(float xi, float yi, float h) {

    while(x > xi) {
        yi = yi + h*f(xi, yi);
        xi = xi + h;
        
    }
    return yi;
}

int main() {

    x = 0.4;
    float y0 = 1, x0 = 0;

    float h1 = 0.1;
    float h2 = 0.2;

    printf("When h = %.4f:\n%f", h1, eulers(x0, y0, h1));

    printf("\n\nWhen h = %.4f:\n%.4f", h2, eulers(x0, y0, h2));

    return 0;
}