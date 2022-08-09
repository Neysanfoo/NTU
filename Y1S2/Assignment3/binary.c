#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode 
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

void printTree(BTNode *root, int depth);
BTNode *Insert(BTNode *root, int data);

int main(void)
{
    BTNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 2);
    root = Insert(root, 9);
    printTree(root,0);
    return 0;
}

BTNode *GetNewNode(int data)
{
    BTNode *temp = malloc(sizeof(BTNode));
    temp -> data = data;
    temp -> right = NULL;
    temp -> left = NULL;
    return temp;
}

BTNode *Insert(BTNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data <= root -> data)
    {
        root -> left = Insert(root -> left, data);
    }
    else
    {
        root -> right = Insert(root -> right, data);
    }
    return root;
}


void printSpace(int x)
{
    for (int i = 0; i< x; i++)
    {
        printf(" ");
    }
}

void padding ( char ch, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
        putchar ( ch );
}

void printTree(BTNode *root, int depth)
{
    int i;

    if ( root == NULL ) {
        padding ( '\t', depth );
        puts ( "~" );
    }
    else {
        printTree ( root->right, depth + 1 );
        padding ( '\t', depth );
        printf ( "%d\n", root -> data );
        printTree( root->left, depth + 1 );
    }
}
