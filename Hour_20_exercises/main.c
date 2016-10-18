#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Rewrite the program in Listing 20.1 by switching the order between the statement in line 15 and the statement in line 17.
What do you get after running the rewritten program? Why?

*/
void exercise1()
{
/* 20L01.c Referencing a union */
//#include <stdio.h>
//#include <string.h>

    //main(void) // local main
    {
        union menu {
            char name[23];
            double price;
        } dish;

        printf("The content assigned to the union separately:\n");
        /* reference name */
        strcpy(dish.name, "Sweet and Sour Chicken");
        /* reference price */
        dish.price = 9.95;
        printf("Dish Name: %s\n", dish.name);
        printf("Dish Price: %5.2f\n", dish.price);

        //return 0;
    }
}
/*
Rewrite the program in Listing 20.2. This time, print out values held by all the members in the info union each time one of the members is assigned a value.
*/
void exercise2()
{
    /* 20L02.c: Memory sharing in unions */
    //#include <stdio.h>

    //main(void) // Local main
    {
        union employee {
            int start_year;
            int dpt_code;
            int id_number;
        } info;

        /* initialize and display start_year */
        info.start_year = 1997;
        printf("Start Year: %d\n", info.start_year);
        /* initialize and display dpt_code */
        info.dpt_code = 8;
        printf("Dpt. Code: %d\n", info.dpt_code);
        /* initialize and display id */
        info.id_number = 1234;
        printf("ID Number: %d\n", info.id_number);
        // return 0;
    }
}

/*

*/
void exercise3()
{

}

/*

*/
void exercise4()
{

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
