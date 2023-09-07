#include<stdio.h>
#include<math.h>

float f(float x) {
    return (1 - exp(-x/2.0));
}

int main() {
    float a, b, h, x, sum=0;
    int n;
    
    printf("Enter initial and final value of x:\n");
    scanf("%f%f", &a, &b);

    h=(b-a);

    sum = h/2 * (f(a) + f(b));

    printf("\nIntegral value of f(x)=%f ", sum);
}