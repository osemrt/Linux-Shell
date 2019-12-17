#include "declarations.h"

int executeCommand(char *args[], char *envp[])
{
    int result; /* execution is successfull or not */
    char *command = args[0];
    int i;

    if (strcmp(command, "clear") == 0)
    {
        clearScreen();
        return;
    }
    else if (strcmp(command, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(command, "history") == 0)
    {
        ReversePrint();
        return;
    }
    else if (strcmp(command, "cd") == 0)
    {
        chdir(args[1]);
        return;
    }

    /* other cases */
    pid_t pid = fork();

    if (pid < 0)
    {
        /* error */
        write(STDOUT_FILENO, "An error has ocurred while creating a process!\n", 47);
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        /* parent */
        wait(NULL); /* wait for child */
    }
    else
    {
        /* child */

        char commandPath[MAX_LINE] = "";
        strcpy(commandPath, "/bin/");
        strcat(commandPath, command);

        result = execve(commandPath, args, envp);
        if (result < 0)
        { /* error */

            printf("\ncommand not found:");
            i = 0;
            while (args[i] != NULL)
            {
                printf(" %s", args[i]);
                i++;
            }
            printf("\n\n");

            exit(EXIT_FAILURE);
        }
    }

    return result;
}