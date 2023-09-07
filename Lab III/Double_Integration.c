#include <stdio.h>
#include <math.h>

#define f(x, y) ( pow(x, 3) + pow(y, 2) )

int main() {

    float h1, h2;
    float x0, xn, y0, yn;

    printf("Enter the lower and upper limit of dy: ");
    scanf("%f %f", &y0, &yn);

    printf("Enter the lower and upper limit of dx: ");
    scanf("%f %f", &x0, &xn);

    h1 = (yn-y0)/2;
    h2 = (xn-x0)/2;

    float ans = h1 * h2 * ( f(x0, y0) + f(x0, yn) + f(xn, y0) + f(xn, yn)) ;

    printf("The double integration is: %.3f", ans );

    return 0;
}