#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

const char charactersToRemove[] =   {'“', '”'};
const char charactersToadd[] =      {'"', '"'};
const int replaceCount = sizeof(charactersToRemove)/sizeof(charactersToRemove[0]);

void cleanFile(FILE *ifp, FILE *ofp)
{
    char *buffer;
    int i = 0;

    buffer = malloc(200);
    while((buffer[i]=fgetc(ifp)) != EOF)
    {
        if(buffer[i] == '\n')
        {
            buffer[i+1] = '\0';
            buffer = removeLineNumber(buffer);
            buffer = replaceCharacters(buffer);
            fputs(buffer, ofp);
            i=0;
        }
        else
        {
            i++;
        }
    }
        if(i > 0)
        {
            buffer[i] = '\0';
            buffer = removeLineNumber(buffer);
            buffer = replaceCharacters(buffer);
            fputs(buffer, ofp);
        }
}

void copyToOutputFile(FILE *ifp, FILE *ofp)
{
    int ch;
    while((ch=fgetc(ifp)) != EOF)
    {
        fputc(ch, ofp);
    }
}

char *removeLineNumber(char *line)
{
    int i = 0;
    int colonReached = 0;

    while((line[i] != '\n') && (line[i] != '\0'))
    {
        if(line[i] == ':')
        {
            colonReached = 1;
        }
        else
        {
            if((colonReached == 1)&&(line[i] != ' '))
                break;
        }
        i++;
    }
    line += i;
    return line;
}

char *replaceCharacters(char *line)
{
    int i, j;
    for(i = 0; i < replaceCount; i++)
    {
        j = 0;
        while(line[j] != '\0')
        {
            if(line[j] == charactersToRemove[i])
                line[j] = charactersToadd[i];
            j++;
        }
    }
    return line;
}
