#include <stdio.h>

int main()
{
    int num1, num2;
    char name[20];

    printf("Hello user, what is your name?\n");
    scanf("%s", name);

    printf("Hello %s\nEnter two numbers, please!\n", name);
    scanf("%d %d", &num1, &num2);

    printf("You entered: %d and %d\n", num1, num2);
    printf("The sum of these numbers are %d\n", num1 + num2);



    return 0;
}
