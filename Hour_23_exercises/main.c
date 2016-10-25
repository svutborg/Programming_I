#include <stdio.h>
#include <stdlib.h>

/*
In Hour 18, “Using Special Data Types and Functions,” you learned how to define enum data. Rewrite the program in Listing 18.1 with the #define directive.
*/
void exercise1()
{
    /* 18L01.c: Defining enum data types */
    //#include <stdio.h>
    /* local main() function */
    //main()
    {
    //enum language {human=100, animal=50, computer};
    #define HUMAN 100
    #define ANIMAL 50
    #define COMPUTER 51
    //enum days{SUN, MON, TUE, WED, THU, FRI, SAT};
    #define SUN 0
    #define MON 1
    #define TUE 2
    #define WED 3
    #define THU 4
    #define FRI 5
    #define SAT 6

    printf("human: %d, animal: %d, computer: %d\n", HUMAN, ANIMAL, COMPUTER);
    printf("SUN: %d\n", SUN);
    printf("MON: %d\n", MON);
    printf("TUE: %d\n", TUE);
    printf("WED: %d\n", WED);
    printf("THU: %d\n", THU);
    printf("FRI: %d\n", FRI);
    printf("SAT: %d\n", SAT);

    //return 0;
    }
}

/*
Define a macro name that can multiply two arguments.
Write a program to calculate the multiplication of 2 and 3 with the help of the macro. Print out the result of the multiplication.
*/
void exercise2()
{
    #define MULT(a, b) (a*b)

    printf("The multiplication of 2 and 3 using macro is: %d\n", MULT(2, 3));
}

/*
Rewrite the program in Listing 23.2 with the #if, #elif, and #else directives.
*/
int exercise3()
{
    /* 23L02.c: Using #ifdef, #ifndef, and #endif */
    //#include <stdio.h>

    #define UPPER_CASE 1
    #define NO_ERROR 0
    #define ERROR -1

    // local main
    //main(void)
    {
        #if UPPER_CASE == 1
            printf("THIS LINE IS PRINTED OUT,\n");
            printf("BECAUSE UPPER_CASE IS 1.\n");
        #elif UPPER_CASE == 0
            printf("\nThis line is printed out,\n");
            printf("because UPPER_CASE is 0.\n");
        #else
            printf("\nError,\n");
            printf("UPPERCASE is neither 0 nor 1.\n");
            return ERROR;
        #endif

        return NO_ERROR;
    }
}

/*
Rewrite the program in Listing 23.3 with nested #if directives.
*/
int exercise4()
{
    /* 23L02.c: Using #ifdef, #ifndef, and #endif */
    //#include <stdio.h>

    #define UPPER_CASE 1
    #define NO_ERROR 0
    #define ERROR -1

    // local main
    //main(void)
    {
        #if UPPER_CASE == 1
            printf("THIS LINE IS PRINTED OUT,\n");
            printf("BECAUSE UPPER_CASE IS 1.\n");
        #else
            #if UPPER_CASE == 0
                printf("\nThis line is printed out,\n");
                printf("because UPPER_CASE is 0.\n");
            #else
                printf("\nError,\n");
                printf("UPPERCASE is neither 0 nor 1.\n");
                return ERROR;
            #endif // UPPER_CASE
        #endif // UPPER_CASE

        return NO_ERROR;
    }
}

/*

*/
void exercise5()
{

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
