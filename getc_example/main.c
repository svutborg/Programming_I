#include <stdio.h>

int main()
{
    char c;
    printf("Hello. Type a character\n");
    c = getc(stdin);
    printf("You typed %c\nGoodbye...",c);

    return 0;
}
