#include "declarations.h"

void clearScreen()
{
    //CSI[2J clears screen,
    //CSI[H moves the cursor to top-left corner
    char *CLEAR_SCREEN = "\x1B[1J\x1B[H";
    write(STDOUT_FILENO, CLEAR_SCREEN, 7);
}
