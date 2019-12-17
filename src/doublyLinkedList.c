#include "declarations.h"

//Creates a new Node and returns pointer to it.
struct Node *GetNewNode(char command[])
{
    int len;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("An error has occurred while creating a node...\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->command, command);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(char command[])
{
    struct Node *newNode = GetNewNode(command);
    if (head->next == NULL)
    {
        head->next = newNode;
        return;
    }
    (head->next)->prev = newNode;
    newNode->next = head->next;
    head->next = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(char command[])
{
    struct Node *temp = head;
    struct Node *newNode = GetNewNode(command);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next; // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print()
{
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%s ", temp->command);
        temp = temp->next;
    }
    printf("\n");
}

//Prints all elements in linked list in reverse traversal order.
void ReversePrint()
{
    struct Node *temp = head;
    int i = 0;

    if (temp == NULL)
        return; // empty list, exit
    // Going to last Node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    while (temp != NULL)
    {
        i++;
        printf("%d %s\n", i, temp->command);
        temp = temp->prev;
    }
}

//Returns the last history command
struct Node *goBack(struct Node *p)
{
    if (p == head && p->next != NULL)
    {
        return head->next;
    }
    else if (p->next != NULL)
    {
        return p->next;
    }
    else
    {
        return p;
    }
}

//Gets the next new command in the left of p from the linked list
struct Node *goForward(struct Node *p)
{
    if (p == head)
    {
        return head;
    }
    if (p == head->next)
    {
        return head;
    }
    else
    {
        return p->prev;
    }
}
