#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main()
{
    char *s, *stringArray[10];
    int i, indeces[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Randomisation algorihm
    #ifdef RANDOM
        char temp;
        int r1, r2;

        srand(time(NULL));
        for(i = 0; i < RAND_NUM; i++)
        {
            r1 = rand()%10;
            r2 = rand()%10;
            temp = indeces[r1];
            indeces[r1] = indeces[r2];
            indeces[r2] = temp;
        }
    #endif // RANDOM

    // populate the array of strings
    stringArray[0] = "BitTorrent";
    stringArray[1] = "DHCP (Dynamic Host Configuration protocol";
    stringArray[2] = "DNS (Domain Name System)";
    stringArray[3] = "FTP (File Transfer Protocol)";
    stringArray[4] = "HTTP (Hypertext Transfer Protocol)";
    stringArray[5] = "NFS (Network File System)";
    stringArray[6] = "NTP (Network Time Protocol)";
    stringArray[7] = "RDP (Remote Desktop Protocol)";
    stringArray[8] = "RTCP (RTP Control Protocol)";
    stringArray[9] = "SSH (Secure Shell)";

    // Print the welcome line
    #ifdef RANDOM
        s = " random";
    #else
        s = "";
    #endif // RANDOM
    printf("Welcome to group picker 3000!\nBelow is the%s order for the application layer protocol presentation\n", s);

    #ifdef DEBUG
        printf("Random order: \n");
    #endif // DEBUG

    // Print the actual (randomised) list
    for(i = 0; i < 10; i++)
    {
        #ifdef DEBUG
            printf("%d ", indeces[i]);
        #endif // DEBUG
        printf("\t%i: %s\n", i, stringArray[indeces[i]]);
    }
    return 0;
}
