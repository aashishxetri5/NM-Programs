#include <stdio.h>

int main()
{

    float x[20], y[20][20], sum, p, u, a, h;
    int i, j, n;

    /* Input Section */
    printf("Enter number of data?\n");
    scanf("%d", &n);

    printf("Enter data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
    }

    for (j = 1; j < n; j++) {
        for (i = j; i < n; i++) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    printf("\nThe backward difference table is:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j <= i; j++) {
            printf("%f\t", y[i][j]);
        }
    }

    a = 8.0;
    p = 1.0;
    sum = y[n - 1][0];
    h = x[1] - x[0];
    u = (a - x[n - 1]) / h;

    for (j = 1; j < n; j++) {
        p = p * (u + j - 1) / j;
        sum = sum + p * y[n - 1][j];
    }

    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);

    return 0;
}
