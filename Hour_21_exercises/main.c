#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Write a program to read the text file haiku.txt and count the number of characters in the file. Also, print out the content of the file and the total character number on the screen.
*/
void exercise1()
{
    FILE *fp;
    char c;
    int counter = 0;

    // Open stream for reading
    fp = fopen("haiku.txt", "r");

    // Read file
    if(fp != NULL)
    { // If the file stream is open
        // While we haven't reached the end of file we keep on reading.
        while(!feof(fp))
        {
            c = fgetc(fp); // Read one character
            putchar(c); // Print that one character
            counter++; // increment counter
        }
        putchar('\n');
        printf("%d total character in the file.\n", counter); // print the char count
        fclose(fp); // Closing the file after reading is done.
    }
}

/*
Write a program to receive a string entered by the user, and then save the string into a file with the name also given by the user.
*/
void exercise2()
{
    FILE *fp;
    char str[30];

    // ask user for a filename
    printf("Enter file name (NOT including file-extension):\n");
    scanf("%s", str);

    // open file
    fp = fopen(strcat(str,".txt"),"w");
    if(fp != NULL)
    { // if the stream was established
        // ask user for text to save to the file
        printf("Your following entry will be saved to: %s\n", str);
        scanf("%s", str);
        if(!fputs(str, fp)) // if the text was successfully written to the file
        {
            printf("%s was successfully written\n", str);
        }
        fclose(fp); // Close file
    }
}

/*
Given the string "Disk file I/O is fun." write a program to write the string into a file called test_21.txt by writing one character at a time.
Meanwhile, print out the string on the screen.
*/
void exercise3()
{
    FILE *fp;
    char *str="Disk file I/O is fun.";
    int index = 0;

    // open file stream
    fp = fopen("test_21.txt","w");
    if(fp != NULL)
    { // if the stream was successfully opened
        while(str[index] != '\0')
        { // for as long as the current character is not the null-character
            fputc(str[index], fp); // put the current character to the file
            putchar(str[index++]); // put the current character to the console window
        }
        fclose(fp); // close file stream
        putchar('\n');
    }
}

/*
Rewrite exercise 3. This time, try to write one block of characters (that is, one string) at a time.
*/
void exercise4()
{
    FILE *fp;
    char *str="Disk file I/O is fun.";

    // open file stream
    fp = fopen("test_21.txt","w");
    if(fp != NULL)
    { // if the stream was successfully opened
        fputs(str, fp); // put the entire string to the file at once
        puts(str); // put the entire string to the console window at once

        fclose(fp); // close file stream
        putchar('\n');
    }
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
