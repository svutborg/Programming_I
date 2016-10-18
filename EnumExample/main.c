#include <stdio.h>


int main()
{
    typedef enum new_boolean {FALSE, TRUE} bools;
    bools my_bool;
    char key;


    my_bool = TRUE;

    printf("FALSE: %d, TRUE: %d", FALSE, TRUE);

    while(my_bool)
    {
        key = getchar();
        if(key == 'q')
        {
            my_bool = FALSE;
        }
        else
            printf("Not q!\n");
    }

    return 0;
}
