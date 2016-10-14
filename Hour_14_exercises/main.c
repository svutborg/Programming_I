#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Given the following:
    An int variable with block scope and temporary storage
    A constant character variable with block scope
    A float local variable with permanent storage
    A register int variable
    A char pointer initialized with a null character
write declarations for all of them.
*/
void exercise1()
{
    auto int i;     // An int variable with block scope and temporary storage
    const char c;   // A constant character variable with block scope
    static float f; // A float local variable with permanent storage
    register int ir;// A register int variable
    char *cp = 0;   // A char pointer initialized with a null character
}

/*
Rewrite the program in Listing 14.2. This time, pass the int variable x and the float variable y as arguments to the function_1() function.
What do you get on your screen after running the program?
*/
int x = 1234;
double y = 1.234567;
void exercise2()
{
    void function_1(int x, float y)
    {
        printf("From function_1:\n  x=%d, y=%f\n", x, y);
    }

    void local_main()
    {
        int x = 4321;   /* block scope 1*/

        function_1(x, y);
        printf("within the main block:\n  x=%d, y=%f\n", x, y);
        /* a nested block */
        {
            double y = 7.654321;  /* block scope 2 */
            function_1(x, y);
            printf("within the nested block:\n  x=%d, y=%f\n", x, y);
        }
    }
    local_main();
}

/*
#include <stdio.h>
int main()
{
    int i;
    for (i=0; i<5; i++){
        int x = 0;
        static int y = 0;
        printf(“x=%d, y=%d\n”, x++, y++);
    }
    return 0;
}
*/
void exercise3()
{
    int i;
    for (i=0; i<5; i++)
    {
        int x = 0;
        static int y = 0;
        printf("x=%d, y=%d\n", x++, y++);
    }
}

/*
Rewrite the add_two() function in Listing 14.3 to print out the previous result of the addition, as well as the counter value.
*/
void exercise4()
{
/* 14L03.c: Using the static specifier */
//#include <stdio.h>
/* the add_two function */
int add_two(int x, int y)
{
    static int counter = 1;
    static int sum = 0;

    printf("This is the function call of %d,\n", counter++);
    printf("The previous result of the addition was: %d\n",sum);
    sum = x + y;
    return (sum);
}
/* the main function */
//main()
//{
    int i, j;

    for (i=0, j=5; i<5; i++, j--)
        printf("the addition of %d and %d is %d.\n\n", i, j, add_two(i, j));
//}
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
