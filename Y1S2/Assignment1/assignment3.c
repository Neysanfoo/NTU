#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
ListNode *moveToEnd(ListNode *head, ListNode *beforeTarget);
ListNode *moveToFront(ListNode *head, ListNode *beforeTarget);

void insert_at_end(Node *head, int x); // Will not work on empty list (as currently implemented)
Node *insert_at_start(Node *head, int x); // Returns type Node* because we need to return the pointer of the new starting Node and assign it to head
void insert_at_n(Node *head, int n, int x); // Assume we get a valid position, does not handle error condition in case of invalid position

void triPartition(ListNode** head, int pivot);

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
    *head = moveToFront(*head,(*head) -> next);
        
}

ListNode *moveToEnd(ListNode *head, ListNode *beforeTarget)
{
    ListNode *temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    ListNode *target = beforeTarget -> next;
    if (target == temp)
    {
        return head;
    }
    beforeTarget -> next = target -> next;
    target -> next = NULL;
    temp -> next = target;
    return head;
}

ListNode *moveToFront(ListNode *head, ListNode *beforeTarget)
{
    ListNode *target = beforeTarget -> next;
    beforeTarget -> next = target -> next;
    target -> next = head;
    head = target;
    return head;
}

