#include <stdio.h>

int main()
{
    int x, y;

    printf("type a value for x: ");
    scanf("%d",&x);
    printf("type a value for y: ");
    scanf("%d",&y);

    printf("x=%d, y=%d\n", x, y);

    x = x + y;
    printf("x = x + y: %d\n", x);
    y -= x;
    printf("y = %d",y);

    return 0;
}
