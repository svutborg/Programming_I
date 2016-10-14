#include <stdio.h>

int j = 100;

int main()
{
    int i;
    printf("%d\n",j);

    for(i = 0; i < 5; i++)
    {
        static int j = 0;
        j += i;
        printf("%d, %d\n", i, j);
    }
    printf("%d",j);

    return 0;
}
