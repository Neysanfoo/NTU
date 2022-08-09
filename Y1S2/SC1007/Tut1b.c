// Implement insertNode using reccursive solution
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void printList(Node *head);
Node *insertNode(Node *head, int i, int item);
Node *insertNodeRecursively(Node *head, int i, int item);

int main(void)
{
    Node *head = NULL;
    head = insertNodeRecursively(head,0,1);
    head = insertNodeRecursively(head,1,2);
    head = insertNodeRecursively(head,1,3);
    head = insertNodeRecursively(head,0,-1);
    printList(head);
}

Node *insertNode(Node *head, int i, int item) // i is position or index, item is data
{
    Node *temp = malloc(sizeof(Node));
    temp -> data = item;
    temp -> next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *temp2 = head;
    for (int j = 0; j < i-1; j++)
    {
        temp2 = temp2 -> next;
    }
    temp -> next = temp2 -> next;
    temp2 -> next = temp;
    return head;
}


Node *insertNodeRecursively(Node *head, int i, int item)
{
    if (head == NULL)
    {
        Node *temp = malloc(sizeof(Node));
        temp -> data = item;
        temp -> next = NULL;
        head = temp;
        return head;
    }
    if (i == 0)
    {
        Node *temp = malloc(sizeof(Node));
        temp -> data = item;
        temp -> next = head;
        head = temp;
        return head;
    }
    if (i == 1)
    {
        Node *temp = malloc(sizeof(Node));
        temp -> data = item;
        temp -> next = NULL;
        temp -> next = head -> next;
        head -> next = temp;
    }
    else
    {
        insertNodeRecursively(head, i-1, item);
    }
    return head;
}


void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    printf("(%p, %p) --> ", &head, head);
    while (head->next != NULL)
    {
        printf("(%p, %d, %p) --> ", head, head->data, head->next);
        head = head -> next;
    }
    printf("(%p, %d, %p)", head, head->data, head->next);
    printf("\n");
}