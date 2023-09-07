#include <stdio.h>
#include <math.h>

float f(float x) {
    return ( pow(x, 3) + 1 );
}

int main() {
    float a, b, h, x, ans, sum = 0;
    int n, i;

    printf("Enter initial and final value of x:\n");
    scanf("%f%f", &a, &b);
    
    printf("\nNumber of segments:");
    scanf("%d", &n);
    
    h = (b - a) / n;
    
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 3 == 0) {
            sum = sum + 2 * f(x);
        } else {
            sum = sum + 3 * f(x);
        }
    }

    ans = (3 * h / 8) * (f(a) + f(b) + sum);
    printf("\nIntegral value of f(x)=%f ", ans);
    
    return 0;
}