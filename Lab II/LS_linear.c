// a program to implement least square approax for linear data
#include <stdio.h>
#include <math.h>

int main() {

    int n;
    printf("Enter the number of data: ");
    scanf("%d", &n);

    float sum_x, sum_y, sum_sqx, sum_xy, a, b, x[n], y[n];

    printf("Enter x and y coord (x, y): ");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i] );
    }

    for (int i = 0; i < n; i++) {
        sum_sqx = sum_sqx + pow((x[i]), 2);
        sum_xy = sum_xy + (x[i] * y[i]);
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
    }

    b = ((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_sqx) - pow(sum_x, 2));
    a = (sum_y - b * sum_x) / n;

    printf("Y = %f + %f x", a, b);
    return 0;
}