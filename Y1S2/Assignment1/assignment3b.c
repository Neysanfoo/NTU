#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void triPartition(ListNode** head, int pivot);

void insert_at_end(ListNode *head, int x); // Time complexity: O(n)
ListNode *insert_at_start(ListNode *head, int x); // Time complexity: O(1)
void insert_at_n(ListNode *head, int n, int x);
ListNode *delete_at_n(ListNode *head, int n);
int backSorted(ListNode *head, int pivot);


int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

	while (scanf("%d", &i)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
	}
	temp->next = NULL;


	triPartition(&head, pivot);
	printList(head);
	deleteList(&head);

	return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

void triPartition(ListNode** head, int pivot){
	ListNode *temp = *head;
    int index = 0;
    int lessCount = 0;
    while (temp -> next != NULL)
    {
        if (temp -> item > pivot)
        {
            if (backSorted(temp, pivot))
            {
                break;
            }
            insert_at_end(*head, temp -> item);
            temp = temp -> next;
            *head = delete_at_n(*head,index);
            printList(*head);

        }
        else if (temp -> item < pivot)
        {
            if (lessCount == 0)
            {
                *head = insert_at_start(*head, temp -> item);
                temp = temp -> next;
                index++;
                *head = delete_at_n(*head,index);
                lessCount++;
            }
            else
            {
                insert_at_n(*head, lessCount, temp -> item);
                temp = temp -> next;
                index++;
                lessCount++;
                *head = delete_at_n(*head,index);
            }

            printList(*head);
        }
        else
        {
            temp = temp -> next;
            index++;
            printList(*head);
        }
        
    }
    
}


void insert_at_end(ListNode *head, int x) // Time complexity: O(n)
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

ListNode *insert_at_start(ListNode *head, int x) // Time complexity: O(1)
{
    ListNode *temp = malloc(sizeof(ListNode));
    temp -> item = x;
    temp -> next = head;
    return temp;
}

void insert_at_n(ListNode *head, int n, int x)
{
    ListNode *temp = malloc(sizeof(ListNode));

    for (int i = 0; i < n-1; i++)
    {
        head = head -> next;
    }
    temp -> item = x;
    temp -> next = head->next;
    head -> next = temp;
}

ListNode *delete_at_n(ListNode *head, int n)
{
    if (n==0)
    {
        head = head -> next;
        return head;
    }
    ListNode *temp = head;
    for (int i = 0; i < n-1; i++)
    {
        temp = temp -> next;
    }
    // temp points to (n-1)th ListNode
    ListNode *temp2 = temp -> next; // we make temp2 to clear memory in heap of the deleted node
    temp -> next = temp2 -> next;
    free(temp2);
    return head;
}

int backSorted(ListNode *head, int pivot)
{
    int isSorted = 1;
    while (head != NULL)
    {
        if (head -> item < pivot)
        {
            isSorted = 0;
        }
        head = head -> next;
    }
    return isSorted;
}