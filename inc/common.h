#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


#define TRUE 1
#define FALSE 0

#define MAX_LINE 1024

#define ESC 27
#define CR 13
#define DEL 127

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

struct Node *head; // global variable - pointer to head node

typedef struct Node
{
    char command[1024];
    struct Node *next;
    struct Node *prev;
} Node;

#endif // !COMMON_H