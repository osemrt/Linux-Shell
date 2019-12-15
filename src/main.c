#include "declarations.h"

int main(int argc, char const *argv[])
{

    initialize();

    char input[MAX_LINE];
    char *commands[MAX_LINE / 2 + 1];
    char *args[MAX_LINE / 2 + 1];
    char *envp[] = {"PATH=/bin", NULL};
    int running = TRUE;

    initialize();

    while (running)
    {
        printPrompt(input);
        fflush(0);
        getCommandFromUser(input);
        
    }

    return 0;
}
