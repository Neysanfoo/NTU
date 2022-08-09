#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");
    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}

BTNode *GetNewNode(char id)
{
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode -> id = id;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BTNode *Insert(BTNode *root, char id)
{
    if (root == NULL)
    {
        root = GetNewNode(id);
        return root;
    }
    else if(id <= root -> id)
    {
        root -> left = Insert(root -> left, id);
    }
    else
    {
        root -> right = Insert(root -> right, id);
    }
    return root;
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
        printf ( "%c\n", root -> id );
        printBST( root->left, depth + 1 );
    }
}


void buildTree(BTNode** node, char* preO, char* postO)
{
    if (preO[0] == '\0')
    {
        return;
    }
    *node = GetNewNode(preO[0]);
    char LeftNodeVal = preO[1];
    int i = 0;
    while ( postO[i] != LeftNodeVal)
    {
        i++;
    }
    char *LeftPreO = malloc(sizeof(char) * 20);
    for (int j = 1; j <= i +1; j++)
    {
        LeftPreO[j-1] = preO[j];
    }
    LeftPreO[i + 1] = '\0';
    char *RightPreO = malloc(sizeof(char) * 20);
    int j;
    for (j = i; preO[j+2] != '\0' ; j++)
    {
        RightPreO[j-i] = preO[j+2];
    }
    RightPreO[j-i] = '\0';
    char *LeftPostO = malloc(sizeof(char) * 20);
    for (j = 0; j <= i; j++)
    {
        LeftPostO[j] = postO[j];
    }
    LeftPostO[i+1] = '\0';

    char *RightPostO = malloc(sizeof(char) * 20);
    for (j = i; postO[j+2] != '\0'; j++)
    {
        RightPostO[j-i] = postO[j+1];
    }
    RightPostO[j-i] = '\0';

    buildTree(&((*node) -> left), LeftPreO, LeftPostO);
    buildTree(&((*node) -> right), RightPreO, RightPostO);
}

/*
Two key observations:
- Preorder traversal follows <Root><Left><Right>
- Postorder traversal follows <Left><Right><Root>

We can access the root using preO[0]
The left child is preO[1]
We find the value of this left child in postO
Then due to the property of postorder traversal, the postorder array for the
left subtree is LPost = postO[:i+1] then RPost = postO[i+1:]
Then the preorder array can be splited by length match: 
LPre=preO[1:i+2], RPre=preO[i+2:]

1 24567 389
56472 983 1

124567389
564729831
        1
       / \
      2  3
     / \ |
    4  7 8
   / \   |
  5  6   9
*/