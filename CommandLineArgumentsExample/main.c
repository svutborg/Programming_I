#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc >= 2)
    {
        if(strcmp(argv[1],"-help") == 0)
        {
            printf("Printing help information!\n");
        }
        else
        {
            printf("%s -help for more information\n",argv[0]);
        }
    }
    else
    {
        printf("no arguments passed!\n");
    }


    return 0;
}
