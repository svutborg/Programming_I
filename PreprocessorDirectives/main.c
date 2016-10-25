#include <stdio.h>
#include <stdlib.h>

#define SUM_METHOD 1

#if SUM_METHOD == 1
    #define SUM(num1, num2) (num1 + num2)
#else
    #define SUM(num1, num2) (num1 - num2)
    #define DEBUG
#endif

#define STR_LEN 1000


int main()
{
    char str[STR_LEN];
    int i;

    scanf("%s", str);
    for(i = 0; (i < STR_LEN )&&( str[i] ) ; i++)
    {
        putchar(str[i]);
    }
    printf("%d", SUM(6, 8)); // printf("%d", (6 + 8));

    #ifdef DEBUG
        printf("In debugging mode");

    #endif // DEBUG

    return 0;
}
