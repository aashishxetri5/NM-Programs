#include <stdio.h>
#include <math.h>

#define f1(x, y, z) (11 + 2*y - z) / 6
#define f2(x, y, z) (5 + 2*x - 2*z) / 7
#define f3(x, y, z) (1 + x + 2*y) / 5

int main() {
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int i = 1;

    printf("Enter the allowed error:\n");
    scanf("%f", &e);
    
    printf("\ni\tx\ty\tz\n");
    do
    {
        /* Calculation */
        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0);
        z1 = f3(x0, y0, z0);
        printf("%d\t%f\t%f\t%f\n", i, x1, y1, z1);
    
        /* Error */
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);
        i++;
    
        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e && e2 > e && e3 > e);
    
    printf("\nSolution: x=%f, y=%f and z = %f\n", x1, y1, z1);
    
    return 0;
}