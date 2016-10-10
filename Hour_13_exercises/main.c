#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Given a character array in the following statement, char str1[] = “This is Exercise 1.”;
write a program to copy the string from str1 to another array, called str2.
*/
void exercise1()
{
    char str1[] = "This is Exercise 1.";
    char str2[strlen(str1)];

    strcpy(str2, str1);

    printf("%s\n", str2);
}

/*
Write a program to measure the length of a string by evaluating the elements in a character array one by one until you reach the null character.
To prove you get the right result, you can use the strlen() function to measure the same string again.
*/
void exercise2()
{
    int len = 0;
    char testStr[] = "This is a test!";

    //for(; testStr[len]; len++); // Compact notation
    while(testStr[len] != '\0') // Less compact
    {
        len++;
    }

    printf("%d, %d\n", len, strlen(testStr));
}

/*
Rewrite the program in Listing 13.4. This time, convert all uppercase characters to their lowercase counterparts.
*/
void exercise3()
{
    char str[80];
    int i, delt = 'a' - 'A';

    printf("Enter a string less than 80 charcters:\n");
    getchar();
    gets(str);
    i = 0;
    while (str[i])
    {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] += delt; /* convert to lower case */
        i++;
    }
    printf("The entered string is (in lowercase):\n");
    puts( str );
}

/*
Write a program that uses the scanf() function to read in two integers entered by the user, adds the two integers, and then prints out the sum on the screen.
*/
void exercise4()
{
    int num1, num2;
    printf("Enter two integer numbers:\n");
    scanf("%d %d", &num1, &num2);
    printf("%d\n", num1 + num2);
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
            default:
                printf("Non-valid selection, press another number...\n");
                break;
        }
    }
    printf("Quitting, Goodbye!");
    return 0;
}
