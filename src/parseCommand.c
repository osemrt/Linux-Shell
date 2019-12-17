#include "declarations.h"

void parseCommand(char input[], char *args[])
{

    int length, /* # of characters in the command line */
        i,      /* loop index for accessing inputBuffer array */
        start,  /* index where beginning of next command parameter is */
        ct;     /* index of where to place the next parameter into args[] */

    length = strlen(input);
    input[length] = '\n';
    start = -1;
    ct = 0;

    /* examine every character in the inputBuffer */
    for (i = 0; i < length + 1; i++)
    {
        switch (input[i])
        {
        case ' ':
        case '\t': /* argument separators */
            if (start != -1)
            {
                args[ct] = &input[start]; /* set up pointer */
                ct++;
            }
            input[i] = '\0'; /* add a null char; make a C string */
            start = -1;
            break;

        case '\n': /* should be the final char examined */
            if (start != -1)
            {
                args[ct] = &input[start];
                ct++;
            }
            input[i] = '\0';
            args[ct] = NULL; /* no more arguments to this command */
            break;
        default: /* some other character */
            if (start == -1)
                start = i;
        }
    }
    args[ct] = NULL; /* just in case the input line was > 1024 */
}