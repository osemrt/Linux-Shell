#include "declarations.h"

int main(int argc, char const *argv[])
{

    initialize();

    char input[MAX_LINE] = "";
    char *args[MAX_LINE / 2 + 1];
    char *envp[] = {"PATH=/bin", NULL};
    int running = TRUE;

    initialize();

    while (running)
    {
        printPrompt(input);
        fflush(0);
        getCommandFromUser(input);
        parseCommand(input, args);
        executeCommand(args, envp);
    }

    return 0;
}
