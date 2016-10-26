#ifndef EDITOR_INCLUDED
    #define EDITOR_INCLUDED

    void cleanFile(FILE *ifp, FILE *ofp);
    void copyToOutputFile(FILE *ifp, FILE *ofp);
    char *removeLineNumber(char *line);
    char *replaceCharacters(char *line);

#endif // EDITOR_INCLUDED
