/* 19L02.c Initializing a structure */
#include <stdio.h>

int main(void)
{
    struct employee {
        int id;
        char name[32];
    };
    /* structure initialization */
    struct employee info = {
        1,
        "B. Smith"
    };

    printf("Here is a sample:\n");
    printf("Employee Name: %s\n", info.name);
    printf("Employee ID #: %04d\n\n", info.id);

    printf("What's your name?\n");
    gets(info.name);
    printf("What's your ID number?\n");
    scanf("%d", &info.id);

    printf("\nHere are what you entered:\n");
    printf("Name: %s\n", info.name);
    printf("ID #: %04d\n", info.id);

    return 0;
}
