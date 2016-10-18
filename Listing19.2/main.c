/* 19L02.c Initializing a structure */
#include <stdio.h>
struct employee {
    int id;
    char name[32];
};

void printEmployeeInfo(struct employee e);

int main(void)
{

    /* structure initialization */
    struct employee info = {1,"B. Smith"};

    printEmployeeInfo(info);

    printf("What's your name?\n");
    gets(info.name);
    printf("What's your ID number?\n");
    scanf("%d", &info.id);

    printEmployeeInfo(info);

    return 0;
}

void printEmployeeInfo(struct employee e)
{
    printf("Employee info:\n");
    printf("Employee Name: %s\n", e.name);
    printf("Employee ID #: %04d\n\n", e.id);
}
