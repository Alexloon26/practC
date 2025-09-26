#include <stdio.h>
#include <math.h>

void test_case(double m, double n) {
    if (m < 0) {
        printf("Error: sqrt of negative value\n");
        return;
    }
    if (n < 0) {
        printf("Error: sqrt of negative value\n");
        return;
    }
    if (m == 0) {
        printf("Error: division by zero\n");
        return;
    }

    if (sqrt(pow(m, 3) * n) + n * m + pow(m, 2) - m == 0) {
        printf("Error: division by zero\n");
        return;
    }

    double z1 = (((m - 1) * sqrt(m) - (n - 1) * sqrt(n)))/(sqrt(pow(m, 3) * n) + n * m + pow(m, 2) - m);
    double z2 = (sqrt(m) - sqrt(n)) / m;

    printf("Z1 = %.2lf, Z2 = %.2lf\n", z1, z2);
}

int main(void) {
    // 1) sqrt of negative n
    test_case(4.0, -2.0);

    // 2) sqrt of negative m
    test_case(-3.0, 2.0);

    // 3) division by zero in z2
    test_case(0.0, 2.0);

    // 4) division by zero in z1
    test_case(1.0, 0.0);

    // 5) without errors
    test_case(4.0, 2.0);

    return 0;
}
