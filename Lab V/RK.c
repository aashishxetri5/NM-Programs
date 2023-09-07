#include <stdio.h>
#include <math.h>

#define f(x,y) (x + y)

float x;

float RK(float xi, float yi, float h) {

    float m1, m2, m3, m4;
    while(x > xi) {
        m1 = f(xi, yi);
        m2 = f(xi+h/2, yi + m1*h/2);
        m3 = f(xi+h/2, yi + m2*h/2);
        m4 = f(xi+h, yi + m3*h);

        yi = yi + h*(m1+2*m2+2*m3+m4)/6;
        xi = xi + h;
        
    }
    return yi;
}

int main() {
    x = 0.4;
    float y0 = 1, x0 = 0;
    float h1 = 0.1, h2 = 0.2;
    
    printf("When h = %.4f:\n%f", h1, RK(x0, y0, h1));

    printf("\n\nWhen h = %.4f:\n%.4f", h2, RK(x0, y0, h2));

    return 0;
}