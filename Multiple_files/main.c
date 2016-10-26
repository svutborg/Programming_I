#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "my_math.h"

int main()
{

    printf("%d",getCounter());
    printf("%d",incrementCounter());
    printf("%d",incrementCounter());
    printf("%d",decrementCounter());
    resetCounter();
    printf("%d",getCounter());

    return 0;
}
