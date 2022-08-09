#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);
int getPrecedence(char opt);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void printList(ListNode *head);
void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);
    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);
    // printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    printf("(%p, %p) --> ", &temp, temp);
    while (temp->next != NULL)
    {
        if (temp -> type == OPERAND)
            printf("(%p, %d, %p) --> ", temp, temp->item, temp->next);
        else
            printf("(%p, %c, %p) --> ", temp, temp->item, temp->next);
        temp = temp -> next;
    }
    printf("(%p, %d, %p)", temp, temp->item, temp->next);
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}


void in2PreLL(char* infix, LinkedList *inExpLL)
{
    // Put infix into LinkedList
    ListNode *head;
    head = NULL;
    ListNode *tail = malloc(sizeof(ListNode));
    tail ->next = NULL;
    tail -> item = 0;
    head = tail;
    Stack s;
    s.head = NULL;
    s.size = 0;
    int num = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (c >='0' && c <= '9')
        {
            num = num * 10 + (c - '0');
        }
        else
        {
            if (num != 0)
            {
                ListNode *temp = malloc(sizeof(ListNode));
                temp -> item = num;
                temp -> type = OPERAND;
                tail -> next = temp;
                tail = tail -> next;
                num = 0;
            }
            if (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')')
            {
                ListNode *temp = malloc(sizeof(ListNode));
                if (c=='(')
                {
                    temp -> item = ')';
                }
                else if (c==')')
                {
                    temp -> item = '(';
                }
                else
                {
                    temp -> item = c;
                }
                temp -> type = OPT;
                tail -> next = temp;
                tail = tail -> next;
            }
        }
    }
    if (num != 0)
        {
                ListNode *temp = malloc(sizeof(ListNode));
                temp -> item = num;
                temp -> type = OPERAND;
                temp -> next = NULL;
                tail -> next = temp;
                tail = tail -> next;
        }
    head = head -> next;
    // Reverse LinkedList
    ListNode *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Convert infix to postfix
    // inExpLL
    while (head != NULL)
    {
        if (head -> type == OPERAND)
        {
            insertNode(inExpLL, head -> item, OPERAND);
        }
        else
        {
            if (isEmptyStack(s) ) //if stack is empty, then push it to stack
            {
                
                push(&s, head -> item);
            }
            else if ((head -> item == '*' || head -> item == '/') ) // if item has greater precedence than stack top then push it
            {
                push(&s, head -> item);
            }
            else if (head -> item == '(')
            {
                push(&s, head -> item);
            }
            else if (head -> item == ')')
            {
                while (peek(s) != '(')
                {
                    char top = peek(s);
                    pop(&s);
                    insertNode(inExpLL, top, OPT);
                }
                pop(&s);
            }
            else
            {
                while ((!isEmptyStack(s) && (peek(s) == '*' || peek(s) == '/')))
                {
                    char top = peek(s);
                    pop(&s);
                    insertNode(inExpLL, top, OPT);
                }
                
                push(&s, head -> item);
            }

        }
        printList(inExpLL->head);
        head = head -> next;

    }
    while (!isEmptyStack(s))
    {
        char top = peek(s);
        pop(&s);
        insertNode(inExpLL, top, OPT);
    }
    printList(inExpLL->head);
    
}


void printList(ListNode *head)
{
    ListNode *temp = head;
    while(temp!=NULL)
    {
        if (temp -> type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

