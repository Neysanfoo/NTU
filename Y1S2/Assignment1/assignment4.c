#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList* llptr);
void InsertAtEnd(ListNode *head, int x);
LinkedList rearrange (LinkedList ll);
void printListAddress(ListNode *head);
ListNode *combineLists1(ListNode *leftList, ListNode *rightList);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll.head == NULL){
			ll.head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll=rearrange(ll);

	printList(ll);
    deleteList(&ll);
	return 0;
}

void printList(LinkedList ll){
    ListNode* temp = ll.head;

    while(temp !=NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList* llptr){
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	llptr->head=NULL;
	llptr->size =0;
}

LinkedList rearrange (LinkedList ll){
    ListNode *oldList = ll.head;
    int listLen = ll.size;
    int isEven = 0;
    if (listLen % 2 == 0)
    {
        isEven = 1;
    }
    ListNode *newListLeft = malloc(sizeof(ListNode));
    ListNode *newListRight = malloc(sizeof(ListNode));
    newListLeft -> next = NULL;
    newListRight -> next = NULL;

    if (isEven)
    {
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListLeft, oldList ->item);
            oldList = oldList -> next;
        }
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListRight, oldList ->item);
            oldList = oldList -> next;
        }
    }
    else
    {
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListLeft, oldList ->item);
            oldList = oldList -> next;
            
        }
        for (int i = 0; i < listLen/2 + 1 ; i++)
        {
            InsertAtEnd(newListRight, oldList ->item);
            oldList = oldList -> next;
            
        }
    }
    newListLeft = newListLeft -> next;
    newListRight = newListRight -> next;

    ListNode *combined1 = combineLists1(newListLeft,newListRight);
    printListAddress(combined1);
    newListLeft = malloc(sizeof(ListNode));
    newListRight = malloc(sizeof(ListNode));
    newListLeft -> next = NULL;
    newListRight -> next = NULL;

    if (isEven)
    {
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListLeft, combined1 ->item);
            combined1 = combined1 -> next;
        }
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListRight, combined1 ->item);
            combined1 = combined1 -> next;
        }
    }
    else
    {
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListLeft, combined1 ->item);
            combined1 = combined1 -> next;
            
        }
        for (int i = 0; i < listLen/2 ; i++)
        {
            InsertAtEnd(newListRight, combined1 ->item);
            combined1 = combined1 -> next;
            
        }
        InsertAtEnd(newListLeft, combined1 ->item);
    }
    newListLeft = newListLeft -> next;
    newListRight = newListRight -> next;

    ListNode *combined2 = combineLists1(newListRight,newListLeft);
    ll.head = combined2;
    return ll;
}

void InsertAtEnd(ListNode *head, int x)
{
    ListNode *n = malloc(sizeof(ListNode));
    ListNode *temp = head;
    n -> item = x;
    n -> next = NULL;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = n;
}


void printListAddress(ListNode *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    printf("(%p, %p) --> ", &head, head);
    while (head->next != NULL)
    {
        printf("(%p, %d, %p) --> ", head, head->item, head->next);
        head = head -> next;
    }
    printf("(%p, %d, %p)", head, head->item, head->next);
    printf("\n");
}


ListNode *combineLists1(ListNode *leftList, ListNode *rightList)
{
    ListNode *combined = malloc(sizeof(ListNode));
    combined -> next = NULL;
    ListNode *head = combined;
    while (rightList != NULL)
    {
        InsertAtEnd(combined, rightList -> item);
        rightList = rightList -> next;
        if (leftList != NULL)
        {
            InsertAtEnd(combined, leftList -> item);
            leftList = leftList -> next;
        }
        
        
    }
    head = head -> next;
    return head;
}
