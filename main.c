#include <stdio.h>
#include <math.h>

int main() {
    double x;
    double sum = 1.0;
    double term = 1.0;
    int i = 1;

    printf("Enter x: ");
    scanf("%lf", &x);

    /*
        e^(-x) = 1 - x + x^2/2! - x^3/3! + ...

        If the current term is:
            x^(i-1)/(i-1)!

        then the next term is:
            -x^i/i!

        which can be calculated as:
            next_term = current_term * (-x) / i

        We stop when the magnitude of the next term is
        smaller than 1e-10, making the truncation error
        much smaller than 0.5e-5, the required accuracy
        for rounding to 5 decimal places.
    */

    while (1) {
        term = term * (-x) / i;
        sum += term;

        if (fabs(term) < 1e-10)
            break;

        i++;
    }

    printf("e^(-%.5f) = %.5f\n", x, sum);

    return 0;
}
