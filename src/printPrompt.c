#include "declarations.h"

void printPrompt(){

    char* user = getenv("USER");
    char hostname[MAX_LINE];
    gethostname(hostname, MAX_LINE);
    printf(YEL "%s@%s > " RESET, user, hostname);

}