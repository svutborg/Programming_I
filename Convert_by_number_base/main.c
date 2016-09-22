#include <stdio.h>
#include <stdlib.h>

/**
*   Will convert the number parameter provided in base 10 to its corresponding string in
*   the base specified by the base parameter e.g.
*   binary: base 2
*   hexadecimal: base 16
*   octal: base 8
*   the resulting string will be returned in the result parameter
**/
void convertToBase(int number, char base, char *result)
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

int main()
{
    char str[65] = "", temp[10];
    int number, base;
    while(1)
    {
        printf("Enter a base 10 number to convert and a base\n");
        gets(temp);
        number = atoi(temp);
        gets(temp);
        base = atoi(temp);
        convertToBase(number, base, str);
        switch(base)
        {
            case 2:
                temp[0] = '0';
                temp[1] = 'b';
                temp[2] = '\0';
                break;
            case 16:
                temp[0] = '0';
                temp[1] = 'x';
                temp[2] = '\0';
                break;
            default:
                temp[0] = '\0';
                break;
        }
        printf("%d in base %d is: %s%s\n", number, base, temp, str);
    }
    return 0;
}
