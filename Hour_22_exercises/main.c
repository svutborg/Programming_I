#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void listing22_3(void);
/*
Assume that the following paragraph of Tao Te Ching is saved in a text file called LaoTzu.txt:
    Be bent, and you will remain straight.
    Be vacant, and you will remain full.
    Be worn, and you will remain new.
Write a program to use ftell() to find the positions of the three strings in the file, and then call fseek() to set the file position indicator
in such a way that the three strings are printed out in reverse order.
*/
void exercise1()
{
    FILE *fp;
    int pointPositions[] = {0, 0, 0};
    int index = 0;
    char str[50];

    fp = fopen("LaoTzu.txt", "r+");
    if(fp != NULL)
    {
        while(!feof(fp))
        {   // read through file and save the positions of each period
            if(fgetc(fp) == '.')
            {
                pointPositions[index++] = ftell(fp);
            }

        }
        // move the cursor to the line after the second punctuation and read a line
        fseek(fp, pointPositions[1]+2, SEEK_SET);
        printf("%s", fgets(str,50,fp));
        // move the cursor to the line after the first punctuation and read a line
        fseek(fp, pointPositions[0]+2, SEEK_SET);
        printf("%s", fgets(str,50,fp));
        // move the cursor to the first line and read a line
        fseek(fp, 0, SEEK_SET);
        printf("%s", fgets(str,50,fp));
    }
}

/*
Rewrite the program you made in exercise 1 by calling the rewind() function to reset the file position indicator at the beginning of the LaoTzu.txt file.
*/
void exercise2()
{
    FILE *fp;
    int pointPositions[] = {0, 0, 0};
    int index = 0;
    char str[50];

    fp = fopen("LaoTzu.txt", "r+");
    if(fp != NULL)
    {
        while(!feof(fp))
        {   // read through file and save the positions of each period
            if(fgetc(fp) == '.')
            {
                pointPositions[index++] = ftell(fp);
            }

        }
        // move the cursor to the line after the second punctuation and read a line
        fseek(fp, pointPositions[1]+2, SEEK_SET);
        printf("%s", fgets(str,50,fp));
        // move the cursor to the line after the first punctuation and read a line
        fseek(fp, pointPositions[0]+2, SEEK_SET);
        printf("%s", fgets(str,50,fp));
        // move the cursor to the first line and read a line
        fseek(fp, 0, SEEK_SET);
        printf("%s", fgets(str,50,fp));

        // rewinding
        rewind(fp);
    }
}

/*
Given a double value of 123.45, and an int value of 10000, write a program to save them into a binary file, called data.bin, and then read them back from the binary file.
Also, print out what you’re writing or reading. What do you think the size of the binary file will be?
*/
void exercise3()
{
    // the size of the binary file should be (double: 8 bytes, int: 4 bytes) 12 bytes
    FILE *fp;
    double d_num = 123.45;
    int i_num = 10000;

    if((fp = fopen("data.bin", "w+b")) != NULL)
    {
        // write data
        printf("Writing %.2f to data.bin\n", d_num);
        fwrite(&d_num, sizeof(double), 1, fp);
        printf("Writing %d to data.bin\n", i_num);
        fwrite(&i_num, sizeof(int), 1, fp);

        // clearing variables, just to make sure that it works
        d_num = 0.0;
        i_num = 0;
        printf("\nClearing d_num=%.2f and i_num=%d\n\n", d_num, i_num);

        // read back data
        rewind(fp);
        fread(&d_num, sizeof(double), 1, fp);
        printf("Reading d_num=%.2f from data.bin\n", d_num);
        fread(&i_num, sizeof(int), 1, fp);
        printf("Reading i_num=%d from data.bin\n", i_num);
        fclose(fp);
    }
}

/*
Read the text file strnum.mix, which is created by the program in Listing 22.3. Redirect the input stream so that you can use the scanf() function to perform the reading operation.
*/
void exercise4()
{
    char buffer[50];
    int stdin_save;
    FILE *fp;
    printf("Running program from listing 22.3 to generate the strnum.mix file\n\n");
    listing22_3();

    stdin_save = dup(STDIN_FILENO); // storing file descriptor for stdin
    printf("\nredirecting stdin...\n");
    if((fp = freopen("strnum.mix", "r", stdin)) != NULL)
    {   // if stdin has been redirected, start reading from the file
        printf("redirecting stdin has been redirected\n");
        while(!feof(fp))
        {   // while we are not done reading, continue reading and print what has been read
            scanf("%50[^\n]s", buffer); // the: %50[^\n]s, specifies to read as string, upto 50 charcters, for as long as it does not meet a newline character: that is the ^\n part
            printf("%s", buffer);
        }
        putchar('\n');
    }
    dup2(stdin_save, STDIN_FILENO); // restoring stdin
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


void listing22_3()
{   // listing 22.3
    /* 22L03.c: Using the fscanf() and fprintf() functions */
    //#include <stdio.h>

    enum {SUCCESS, FAIL, MAX_NUM = 3, STR_LEN = 23};

    auto void DataWrite(FILE *fout);
    auto void DataRead(FILE *fin);
    auto int ErrorMsg(char *str);

    // local main
    //main(void)
    {
        FILE *fptr;
        char filename[]= "strnum.mix";
        //int reval = SUCCESS;

        if ((fptr = fopen(filename, "w+")) == NULL)
        {
          //  reval = ErrorMsg(filename);
        }
        else
        {
            DataWrite(fptr);
            rewind(fptr);
            DataRead(fptr);
            fclose(fptr);
        }

        //return reval;
    }
    /* function definition */
    void DataWrite(FILE *fout)
    {
        int i;
        char cities[MAX_NUM][STR_LEN] = { "St.Louis->Houston:", "Houston->Dallas:", "Dallas->Philadelphia:"};
        int miles[MAX_NUM] = { 845, 243, 1459};

        printf("The data written:\n");
        for (i=0; i<MAX_NUM; i++)
        {
            printf("%-23s %d miles\n", cities[i], miles[i]);
            fprintf(fout, "%s %d", cities[i], miles[i]);
        }
    }
    /* function definition */
    void DataRead(FILE *fin)
    {
        int i;
        int miles;
        char cities[STR_LEN];

        printf("\nThe data read:\n");
        for (i=0; i<MAX_NUM; i++)
        {
            fscanf(fin, "%s%d", cities, &miles);
            printf("%-23s %d miles\n", cities, miles);
        }
    }
    /* function definition */
    int ErrorMsg(char *str)
    {
        printf("Cannot open %s.\n", str);
        return FAIL;
    }
}
