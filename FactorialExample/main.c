#include <stdio.h>
#include <stdlib.h>

double factorial(double value);

int main()
{
    double val;
    for(val = 0; val < 30; val++)
        printf("%.0f! = %.0f\n", val, factorial(val));
    return 0;
}

double factorial(double value)
{
    if(value == 0)
        return 1;
    if(value == 1)
        return 1;
    return factorial(value - 1) * value;
}
