#include <stdio.h>
#include "math.h"

const double PI = 3.1415926535;

double sequence(int current, double state, double sum, double x, double eps) {
    if (fabs(sin(x) - sum) > eps) {
        state = state * x / (2 * current) * x / (2 * current + 1) * (-1);
        sum += state;
        sequence(current + 1, state, sum, x, eps);
    }
    return sum;

}

int main(void) {
    double x, sum, current, eps;
    int n = 1;
    printf("input x && epsilon\n");
    scanf("%lf %lf", &x, &eps);
    if (fabs(x) > PI) {
        if (x > 0) {
            while (x > PI) {
                x -= PI;
            }
        } else {
            while (fabs(x) > PI) {
                x += PI;
            }
        }
    }
    printf("sinx = %lf\n", sin(x));
    current = x;
    sum = x;
    while (fabs(sin(x) - sum) > eps) {
        current = current * x / (2 * n) * x / (2 * n + 1) * (-1);
        sum += current;
        n++;
    }
    printf("sum = %lf\nn = %d\n", sum, --n);
    printf("recurrent sequence is %lf", sequence(1, x, x, x, eps));
    return 0;
}
