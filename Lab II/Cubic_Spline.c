#include <stdio.h>
#include <math.h>

int main() {
    int n, i;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    float x[n], f[n], h[n - 1], u[n - 1], a[n - 1], s, x1;

    // taking inputs
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &f[i]);
    }

    printf("Enter a value to be interpolated: ");
    scanf("%f", &x1);

    // h and u
    for (int i = 0; i < n - 1; i++) {
        h[i + 1] = x[i + 1] - x[i];
        u[i] = x1 - x[i + 1];
    }

    i = 1;

    // setting of a for three points
    a[0] = 0;
    a[n - 1] = 0;
    a[1] = ((6 * ((f[2] - f[1]) / h[2]) - ((f[1] - f[0]) / h[1])) - h[1] * a[0] - h[2] * a[2]) / (2 * (h[1] + h[2]));

    // finding the range interpolation value lies
    for (i = 0; i < n; i++) {

        if (x1 <= x[i]) {
            u[0] = u[i - 1];
            u[1] = u[i];
            break;
        }
    }

    // finding S
    s = (a[i - 1] * (pow(h[i], 2) * u[i] - pow(u[i], 3)) + a[i] * (pow(u[i - 1], 3) - h[i] * u[i - 1])) / (6 * h[i]) + (f[i] * u[i - 1] - f[i - 1] * u[i]) / h[i];

    printf("%f", s);

    return 0;
}