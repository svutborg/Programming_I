#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_FILE_NAME_SIZE 20
typedef enum {false, true} bool;
bool getFileName(char *FN);


int main()
{
    char buffer[MAX_FILE_NAME_SIZE+1];
    int c;
    bool done = false;
    FILE *fp;
    printf("Welcome to primitive text editor v1.0\n\n");

    printf("Enter file name to edit.\n");

    while(!getFileName(buffer))
    {
        printf("Enter valid file name\n");
    }
    if((fp = fopen(buffer, "a+")) != NULL)
    {
        printf("============( %s )===============\n", buffer);
        // print existing file
        while((c = fgetc(fp)) != EOF)
        {
            putchar(c);
        }
        while(!done)
        {
            c = getch();
            if(c==27)
            {
                done = true;
            }
            else
            {
                fputc(c, fp);
            }
        }

        printf("============( %s )===============\n", buffer);
    }
    fclose(fp);
    printf("Quitting!");
    return 0;
}

bool getFileName(char *FN)
{
    int i = 0;
    bool done = false;
    FN[0] = '\0';
    while(!done&&i<MAX_FILE_NAME_SIZE)
    {
        FN[i] = getch();
        switch(FN[i])
        {
            case '\t': // disallow tabs
                i--;
                break;
            case 13: // Enter
                done = true;
                FN[i] = '\0';
                break;
            default:
                putchar(FN[i]);
        }
        i++;
    }
    putchar('\n');
    if(FN[0] == '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}
