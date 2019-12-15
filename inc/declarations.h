#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include "common.h"

void clearScreen();
void welcomeScreen();
void printPrompt();
void initialize();

int getCommandFromUser(char input[]);

void disableBuffering();
void enableBuffering();
void clearInputLine();

#endif // !DECLARATIONS_H