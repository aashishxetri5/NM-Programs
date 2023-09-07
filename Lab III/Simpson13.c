#include <stdio.h>
#include <math.h>

float f(float x) {
    return (pow(x, 2.0) * exp(-x) );
}

int main() {
    float a, b, h, ans;
    
    printf("Enter initial and final value of x:\n");
    scanf("%f%f", &a, &b);
    
    h=(b-a)/2;
    
    ans = (h/3) * (f(a) + f(b) + 4*f(a+h) );
    printf("\nIntegral value of f(x)=%f ", ans);
    
    return 0;
}