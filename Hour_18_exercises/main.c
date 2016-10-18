#include <stdio.h>
#include <stdlib.h>


/*
Write a program to print out the values represented by the enumerated names declared in Quiz question 2 in this hour.
enum tag { name1, name2 = 10, name3, name4 };
*/
void exercise1()
{
    enum tag { name1, name2 = 10, name3, name4 };

    printf("%d, %d, %d, %d\n", name1, name2, name3, name4);

}

/*
Given the following declarations:
    typedef char WORD;
    typedef int SHORT;
    typedef long LONG;
    typedef float FLOAT;
    typedef double DFLOAT;
write a program to measure the sizes of the synonyms to the data types.
*/
void exercise2()
{
    typedef char WORD;
    typedef int SHORT;
    typedef long LONG;
    typedef float FLOAT;
    typedef double DFLOAT;

    printf("%d, %d, %d, %d, %d\n", sizeof(WORD), sizeof(SHORT), sizeof(LONG), sizeof(FLOAT), sizeof(DFLOAT));
}

/*
Rewrite the program in Listing 18.4. This time, add integers starting at the value of MIN_NUM instead of the value of MAX_NUM.
*/
void exercise3()
{
    /* 18L04.c: Calling a recursive function */
    //#include <stdio.h>

    enum con{   MIN_NUM = 0,
                MAX_NUM = 100};

    auto int fRecur(int n);

    //main() // Local main
    {
        int i, sum1, sum2;

        sum1 = sum2 = 0;
        for (i=MAX_NUM; i >= MIN_NUM; i--)
            sum1 += i;
        printf("The value of sum1 is %d.\n", sum1);
        sum2 = fRecur(MIN_NUM);
        printf("The value returned by fRecur() is %d.\n", sum2);

        //return 0;
    }
    /* function definition */
    int fRecur(int n)
    {
        if (n == MAX_NUM)
            return MAX_NUM;
        return fRecur(n + 1) + n;
    }
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
            default:
                printf("Non-valid selection, press another number...\n");
                break;
        }
    }
    printf("Quitting, Goodbye!");
    return 0;
}
