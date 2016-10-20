#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[20], c;
    FILE *fp;
    int num1, num2, num3 = 15;
    printf("Enter file name...\n");

    scanf("%s",input);
    fp = fopen(input,"r+");

    if(fp != NULL)
    {
        //printf("%d\n",ftell(fp));
        printf("========( %s )========\n",input);
        do
        {
            c = fgetc(fp);
            putchar(c);
        }while(c != EOF);
        //printf("%d\n",ftell(fp));
        /*fseek(fp, 10, SEEK_SET);
        fputs("11111",fp);
        rewind(fp);
        printf("\nNew content( %s )New content\n",input);
        do
        {
            c = fgetc(fp);
            putchar(c);
        }while(c != EOF);

        rewind(fp);
        fprintf(fp,"File title is: [%s]\n",input);
        */
        rewind(fp);
        while(fgetc(fp) != '\n');
        fscanf(fp,"%d, %d, %d", &num1, &num2, &num3);
        printf("File contains the following numbers:\n%d and %d and %d", num1, num2, num3);
    }
    else
    {
        printf("Could not open file!\n");
    }

    if(fclose(fp) == 0)
        printf("File closed successfully");
    return 0;
}
