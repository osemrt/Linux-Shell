#include "declarations.h"

int getCommandFromUser(char input[])
{

    int flag = FALSE; /* it will be TRUE if the reading input is completed */
    int i = 0;

    char *msg1;
    char *msg2;
    char c;

    //printf("\r"); /* \r brings your cursor to the beginning of the line */
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

                if (c == 'A')
                {
                    /* up_arrow */
                    printPrompt();
                    msg1 = "up..."; // getting from history
                    strcpy(input, msg1);
                    i = strlen(msg1);

                    printf("%s", msg1);
                }
                else if (c == 'B')
                {
                    /* down arrow */
                    printPrompt();
                    msg2 = "down..."; // getting from history
                    strcpy(input, msg2);
                    i = strlen(msg2);

                    printf("%s", msg2);
                }
            }
        }
        else if (c == DEL)
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
        }
        else if (c == CR)
        {
            input[i] = '\0';
            printf("\b \b"); // deletes M
            printf("\b \b"); // deletes ^

            printf("\n");
            clearInputLine();
            printf("read:%s...\n", input);
            clearInputLine();
            i = 0;
            flag = TRUE;
        }
        else
        {
            /* other keys */
            input[i++] = c;
            enableBuffering();
        }

    } while (!flag == TRUE);

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
