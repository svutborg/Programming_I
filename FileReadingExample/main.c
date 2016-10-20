#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[20], c;
    FILE *fp;
    printf("Enter file name...\n");

    scanf("%s",input);
    fp = fopen(input,"r+");

    if(fp != NULL)
    {
        printf("========( %s )========\n",input);
        do
        {
            c = fgetc(fp);
            putchar(c);
        }while(c != EOF);
        getchar();
        gets(input);
        fputs(input,fp);
    }
    else
    {
        printf("Could not open file!\n");
    }

    if(fclose(fp) == 0)
        printf("File closed sucessfully");
    return 0;
}
