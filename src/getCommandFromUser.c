#include "declarations.h"

void getCommandFromUser(char input[])
{

    int flag = FALSE; /* it will be TRUE if the reading input is completed */
    int i = 0;
    struct Node *history_pointer = head; /* current history pointer */
    char *command;
    char c;

    do
    {
        disableBuffering();
        c = getchar();

        /* By pressing one arrow key getch will push three values into the buffer:
          1:ESC, 2:'[', 3) 'A', 'B', 'C' or 'D' */
        if (c == ESC)
        {
            if ((c = getchar()) == '[')
            {

                c = getchar();
                clearInputLine();
                printPrompt();

                if (c == 'A')
                {

                    /* up_arrow */
                    history_pointer = goBack(history_pointer); // getting from history
                    command = history_pointer->command;
                    strcpy(input, command);
                    i = strlen(command);
                    printf("%s", command);
                }
                else if (c == 'B')
                {

                    /* down arrow */
                    history_pointer = goForward(history_pointer); // getting from history
                    command = history_pointer->command;
                    strcpy(input, command);
                    i = strlen(command);
                    printf("%s", command);
                }
                else
                {
                    printf("%s", input);
                }
            }
        }
        else if (c == DEL)
        {
            history_pointer = head;
            clearInputLine();
            printPrompt();
            if (i > 0)
            {

                input[i - 1] = '\0';
                printf("%s", input);
                i--;
            }
        }
        else if (c == CR)
        {

            printf("\b \b"); // deletes M
            printf("\b \b"); // deletes ^
            printf("\r\n");

            if (i == 0)
            {
                clearInputLine();
                printPrompt();
            }
            else
            {

                history_pointer = head;
                input[i] = '\0';

                disableBuffering();
                InsertAtHead(input);
                enableBuffering();
                i = 0;
                flag = TRUE;
            }
        }
        else
        {
            /* other keys */
            input[i++] = c;
            enableBuffering();
        }

    } while (flag != TRUE);

    enableBuffering();
}

void disableBuffering()
{
    /* use system call to make terminal send all keystrokes directly to stdin */
    system("/bin/stty raw");
}

void enableBuffering()
{
    /* use system call to set terminal behaviour to normal behaviour */
    system("/bin/stty cooked");
}

void clearInputLine()
{
    /* \33[2K erases the entire line your cursor is currently on*/
    /* \r brings your cursor to the beginning of the line */
    printf("\33[2K\r");
}
