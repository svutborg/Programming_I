#include <stdio.h>
#include <stdlib.h>


/*
Given the following declaration and definition of a structure:
    struct automobile { int year;
                        char model[10];
                        int engine_power;
                        double weight;
    } sedan = {1997, "New Model", 200, 2345.67};
write a program to display on the screen the initial values held by the structure.
*/
void exercise1()
{
    struct automobile { int year;
                        char model[10];
                        int engine_power;
                        double weight;
    } sedan = {1997, "New Model", 200, 2345.67};

    printf("The initial Values of the sedan struct:\n");
    printf("\t%d\n \t%s\n \t%d\n \t%.2f\n", sedan.year, sedan.model, sedan.engine_power, sedan.weight);
}

/*
Rewrite the program in Listing 19.2. This time, create a function that can display the content in the employee structure. Then, make calls to the function by passing the structure to it.
*/
void exercise2()
{
    /* 19L02.c Initializing a structure */
    //#include <stdio.h>
    struct employee {
        int id;
        char name[32];
    };

    void disp_employee(struct employee e)
    {
        printf("\nHere are what you entered:\n");
        printf("Name: %s\n", e.name);
        printf("ID #: %04d\n", e.id);
    }

    //main(void) // local main function
    {
        /* structure initialization */
        struct employee info = {
            1,
            "B. Smith"
        };

        printf("Here is a sample:\n");
        printf("Employee Name: %s\n", info.name);
        printf("Employee ID #: %04d\n\n", info.id);

        printf("What's your name?\n");
        getchar(); // Added to stop gets catching the newline from pritnf
        gets(info.name);
        printf("What's your ID number?\n");
        scanf("%d", &info.id);

        disp_employee(info);
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
