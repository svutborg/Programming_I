#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void printUsageInstructions()
{
    printf("Usage: program <input file> <output file>\n");
}

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;

    if(argc != 3)
    {
        printUsageInstructions();
    }
    else
    {
        ifp = fopen(argv[1],"r");
        if(ifp == NULL)
        {
            printUsageInstructions();
            printf(">> input file: %s could not be opened\n", argv[1]);
            exit(1);
        }
        ofp = fopen(argv[2],"w");
        if(ifp == NULL)
        {
            printUsageInstructions();
            printf(">> output file: %s could not be opened\n", argv[2]);
            exit(1);
        }
        cleanFile(ifp, ofp);

        fclose(ifp);
        fclose(ofp);
    }
    return 0;
}
