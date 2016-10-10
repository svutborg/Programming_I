#include <stdio.h>
#include <stdlib.h>

/*
Given three integer variables, x = 512, y = 1024, and z = 2048, write a program to print out their left values as well as their right values.
*/
void exercise1()
{
  int x = 512, y = 1024, z = 2048;
  printf("x: %d @ %p\ny: %d @ %p\nz: %d @ %p\n", x, &x, y, &y, z, &z);
}

/*
Write a program to update the value of the double variable flt_num from 123.45 to 543.21 by using a double pointer.
*/
void exercise2()
{
    double flt_num = 123.45, *flt_ptr;
    flt_ptr = &flt_num;
    printf("flt_num before: %.2f\n", flt_num);
    *flt_ptr = 543.21;
    printf("flt_num after: %.2f\n", flt_num);
}

/*
Given a character variable ch and ch = ‘A’, write a program to update the value of ch to decimal 66 by using a pointer.
*/
void exercise3()
{
    char ch = 'A', *ch_ptr;
    ch_ptr = &ch;
    printf("ch before: %c\n", ch);
    *ch_ptr = 66;
    printf("ch after: %c\n", ch);
}

/*
Given that x=5 and y=6, write a program to calculate the multiplication of the two integers and print out the result, which is saved in x, all in the way of indirection (that is, using pointers).
*/
void exercise4()
{
    int x = 5, y = 6, *x_ptr, *y_ptr;

    x_ptr = &x;
    y_ptr = &y;

    printf("The Multiplication of x: %d on address %p, with y: %d on address %p is ", x, &x, y, &y);

    *x_ptr *= *y_ptr;

    printf("%d\n", x);
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
