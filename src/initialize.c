#include "declarations.h"

void initialize()
{
    clearScreen();
    welcomeScreen();

    /* separate the first node */
    struct Node *newNode = GetNewNode("");
    head = newNode;

}