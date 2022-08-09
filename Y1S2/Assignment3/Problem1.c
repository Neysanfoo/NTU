#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void push(Stack *sPtr, BTNode *item){
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

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}


void padding ( char ch, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
        putchar ( ch );
}

void printBST(BTNode *root, int depth)
{
    int i;

    if ( root == NULL ) {
        padding ( '\t', depth );
        puts ( "~" );
    }
    else {
        printBST ( root->right, depth + 1 );
        padding ( '\t', depth );
        if (root->item == '+' || root->item == '-' || root->item == '*' || root->item == '/' )
        {
            printf("%c", root -> item);
        }
        else
        {
            printf ( "%d\n", root -> item );
        }
        printBST( root->left, depth + 1 );
    }
}

BTNode *GetNewNode(int item)
{
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode -> item = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}



void createExpTree(BTNode** root,char* prefix)
{
    Stack s;
    s.head = NULL;
    s.size = 0;
    int num = 0;
    Stack tempS;
    tempS.head = NULL;
    tempS.size = 0;
    
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        int front = prefix[i];
        if (front == '+' || front == '-' || front == '*' || front == '/') 
        {
            BTNode *newNode = GetNewNode(front + 100);
            push(&tempS, newNode);
        }
        else if (front == ' ' && num != 0)
        {
            BTNode *newNode = GetNewNode(num);
            push(&tempS, newNode);
            num = 0;
        }
        else if (front == '0' && num == 0)
        {
            BTNode *newNode = GetNewNode(front - '0');
            push(&tempS, newNode);
        }
        else if (front >= '0' && front <= '9')
        {
            num = num * 10;
            num += (front - '0');
        }
    }
    if (num > 0)
    {
        BTNode *newNode = GetNewNode(num);
        push(&tempS,newNode);
    }
    while(!isEmptyStack(tempS))
    {
        BTNode *front = GetNewNode(peek(tempS)->item);

        pop(&tempS);
        int frontVal = front ->item;
        if (frontVal == '+' + 100 || frontVal == '-' + 100|| frontVal == '*' + 100|| frontVal == '/' + 100)
        {
            front -> left = peek(s);
            pop(&s);
            front -> right = peek(s);
            pop(&s);
            push(&s,front);
        }
        else
        {
            push(&s, front);
        }
    }
    *root = peek(s);
}

void printTree(BTNode *node){
    if (node == NULL) return;
    printTree(node-> left);
    if (node -> item == '+' + 100 || node -> item == '-' + 100 || node -> item == '*' + 100 || node -> item == '/' + 100 )
        printf("%c ", node -> item - 100);
    else
        printf("%d ", node -> item);
    printTree(node-> right);
}


void printTreePostfix(BTNode *node){
    if (node == NULL) return;
    printTreePostfix(node-> left);
    printTreePostfix(node-> right);

    if (node -> item == '+' + 100 || node -> item == '-'+ 100  || node -> item == '*'+ 100  || node -> item == '/'+ 100  )
        printf("%c ", node -> item - 100);
    else
        printf("%d ", node -> item);
}

double computeTree(BTNode *node){
    if (node == NULL) return 0;
    if (node -> item == '+' + 100)
    {
        return (computeTree(node -> left) + computeTree(node -> right) );
    }
    else if (node -> item == '-' + 100)
    {
        return (computeTree(node -> left) - computeTree(node -> right) );
    }
    else if (node -> item == '/' + 100)
    {
        return (computeTree(node -> left) / computeTree(node -> right) );
    }
    else if (node -> item == '*' + 100)
    {
        return (computeTree(node -> left) * computeTree(node -> right) );
    }
    else
    {
        return node -> item;
    }
}

