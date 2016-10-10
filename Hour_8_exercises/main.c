#include <stdio.h>
#include <stdlib.h>

/*
    Given x = 0xEFFF and y = 0x1000 (that is, EFFF and 1000 as hex values),
    what hex values do you get by evaluating ~x and ~y?
*/
void exercise1()
{
    int x = 0xEFFFFFFF, y = 0x10000000;

    printf("Exercise 1:\n");
    printf("Given x = 0xEFFF and y = 0x1000 (that is, EFFF and 1000 as hex values), what hex values do you get by evaluating ~x and ~y?\n\n");
    printf("Given x = %X and y = %X, you get ~x = %X and ~y = %X\n\n", x, y, ~x, ~y);
}

void exercise2()
{
    int x = 0xEFFFFFFF, y = 0x10000000;

    printf("Exercise 2:\n");
    printf("Taking the values of x and y assigned in Exercise 1, write a program that prints out the values of !x and !y by using both the %%d and %%u formats in the printf() function.\n");
    printf("Given x = %X and y = %X, you get\n\t(%%d): !x = %d\n\t(%%u): !x = %u \nand\n\n\t(%%d): !y = %d\n\t(%%u): !y = %u\n\n", x, y, !x, !x, !y, !y);

}

void exercise3()
{
    int x = 123, y = 4;

    printf("Exercise 3:\n");
    printf("Given x = 123 and y = 4, write a program that displays the results of the expressions x << y and x >> y.\n");
    printf("\tx << y: %d << %d = %d\n", x, y, x<<y);
    printf("\tx >> y: %d >> %d = %d\n", x, y, x>>y);
}

void exercise4()
{
    printf("Exercise 4:\n");
    printf("Write a program that shows the values (in hex) of the expressions 0xFFFF ^ 0x8888, 0xABCD & 0x4567, and 0xDCBA | 0x1234.\n");
    printf("\t0xFFFF ^ 0x8888 = 0x%04X\n", 0xFFFF ^ 0x8888);
    printf("\t0xABCD & 0x4567 = 0x%04X\n", 0xABCD & 0x4567);
    printf("\t0xDCBA | 0x1234 = 0x%04X\n", 0xDCBA | 0x1234);
}

void exercise5()
{
    char x = ' ';
    printf("Exercise 5:\n");
    printf("Use the ?: operator and the for statement to write a program that keeps taking the characters entered by the user until the character q is accounted.\n");
    for(;x!='q'?1:0;)
    {
        x = getchar();
    }
    printf("Quitting exercise 5!\n");
}

int main()
{
    char selection[20];
    while(1)
    {
        printf("Choose exercise\n");
        printf("Enter number, press q to quit\n");
        scanf("%s", selection );
        if(selection[0] == 'q')
        {
            break;
        }
        switch(selection[0])
        {
            case '1':
                exercise1();
                break;
            case '2':
                exercise2();
                break;
            case '3':
                exercise3();
                break;
            case '4':
                exercise4();
                break;
            case '5':
                exercise5();
                break;
            default:
                printf("Non-valid selection, press another number...\n");
                break;
        }
    }
    printf("Quitting, Goodbye!");
    return 0;
}
