#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include "common.h"

void clearScreen();
void welcomeScreen();
void printPrompt();
void initialize();

void getCommandFromUser(char input[]);
void disableBuffering();
void enableBuffering();
void clearInputLine();

void parseCommand(char input[], char *args[]);
void executeCommand(char *args[], char *envp[]);

struct Node *GetNewNode(char command[]);
void InsertAtHead(char command[]);
void InsertAtTail(char command[]);
void ReversePrint();
struct Node *goBack(struct Node *p);
struct Node *goForward(struct Node *p);
void Print();

#endif // !DECLARATIONS_H