#include <stdio.h>
#include <math.h>

int main() {

    int n;
    printf("Enter a number of cases: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the data: ");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    // finding the sum
    float a, b, sum_x, sum_y, sum_xy, sum_sqx;

    sum_x = sum_y = sum_xy = sum_sqx = 0;

    for (int i = 0; i < n; i++) {
        sum_sqx += pow(x[i], 2);
        sum_xy += (x[i] * log10(y[i]) );
        sum_x += x[i];
        sum_y += log10(y[i]);
    }

    // finding coeffiecients
    b = ((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_sqx) - pow(sum_x, 2));
    a = (sum_y - b * sum_x) / n;

    printf("Y = %f * %f^x", pow(a, 10), pow(a, 10) );

    return 0;
}