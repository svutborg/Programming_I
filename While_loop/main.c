#include <stdio.h>

int main()
{
    char keyPress = ' ';
    int i = 0, j;

    printf("press q to quit!");
    for (j=0; j<5; j++)
    {
        keyPress = ' ';
        printf("Outer loop iteration: %d\n",j);
        while (keyPress != 'q')
        {
            printf("\tloopcounter: %d\n",i++);
            keyPress = getchar();
        }
    }
    printf("Goodbye");
    return 0;
}
