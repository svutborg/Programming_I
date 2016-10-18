#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printUsage(char *argv0);
void printNewBase(int base, int number);
void convertToBase(int number, int base, char *result);

int main(int argc, char *argv[])
{
    if(argc != 3) // Wrong number of arguments?
    {
        printUsage(argv[0]);
    }
    else
    {
        int base = atoi(argv[1]),
            number = atoi(argv[2]);
        if(!base || !number) // atoi returns 0 if it could not convert
        {
            printUsage(argv[0]);
        }
        else
        {
            printNewBase(base, number);
        }
    }
    return 0;
}

void printNewBase(int base, int number)
{
    char result[50];
    switch(base)
    {
        case 8:
            printf("%d in base %d is %o", number, base, number);
            break;
        case 10:
            printf("%d in base %d is %d", number, base, number);
            break;
        case 16:
            printf("%d in base %d is 0x%X", number, base, number);
            break;
        default:
            convertToBase(number, base, result);
            printf("%d in base %d is %s", number, base, result);
            break;
    }
}

void convertToBase(int number, int base, char *result)
{
    int i = 0, j;
    char temp;

    // as long as the number > 0
    while(number>0)
    {
        // resolve numbers into string
        result[i] = number%base+'0';
        number/=base;
        if(result[i]>'9') // Use A, B, C... if the base is larger than 10
        {
            result[i] += 'A'-'9'-1;
        }
        i++;
        if(number == 1)
        {
            result[i++] = '1';
            break;
        }
    }
    // reverse the order of the string
    for(j=0; j<i/2; j++)
    {
        temp = result[j];
        result[j] = result[i-j-1];
        result[i-j-1] = temp;
    }
    // add null-character to the to make it a string
    result[i] = '\0';
}

void printUsage(char *argv0)
{
    int a, b = 0;
    for(a = 0; argv0[a]; a++) // find the last backslash
    {
        if(argv0[a] == '\\') // if the current char is \ store the number
            b = a+1;
    }
    argv0 += b; // point string pointer to last backslash
    printf("Usage: %s <new base> <base 10 number>", argv0);
}
