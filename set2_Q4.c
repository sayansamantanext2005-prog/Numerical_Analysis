#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x - exp(-x);
}

int main()
{
    double a = 0.0;
    double b = 1.0;
    double c;
    double tolerance = 1e-6;
    int iteration = 0;

    if (f(a) * f(b) >= 0) {
        printf("Invalid initial interval.\n");
        return 1;
    }

    /* Initial Regula Falsi approximation */
    c = (a * f(b) - b * f(a)) / (f(b) - f(a));

    printf("Iter\t a\t\t b\t\t c\t\t f(c)\n");

    while (fabs(f(c)) >= tolerance)
    {
        iteration++;

        printf("%d\t %.8f\t %.8f\t %.8f\t %.8f\n",
               iteration, a, b, c, f(c));

        /* Keep the interval containing the root */
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        /* Calculate the next false-position point */
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
    }

    iteration++;

    printf("%d\t %.8f\t %.8f\t %.8f\t %.8f\n",
           iteration, a, b, c, f(c));

    printf("\nRoot = %.5f\n", c);

    return 0;
}
