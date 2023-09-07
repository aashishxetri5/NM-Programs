#include <stdio.h>
#include <math.h>

float f(float x) {
    return ( pow(x, 3) + 1);
}

int main() {
    float a, b, h, ans;
    
    printf("Enter initial and final value of x:\n");
    scanf("%f%f", &a, &b);
    
    h = (b-a)/3;

    ans = (3*h/8) * (f(a) + f(b) + 3*f(a+h) + 3*f(a+2*h) );

    printf("\nIntegral value of f(x)=%f ", ans);
    
    return 0;
}