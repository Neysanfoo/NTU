#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printListAddress(ListNode *head);
void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int K = 0;

	scanf("%d",&K);

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


	reverseKNodes(&head, K);
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

// K nodes form a segment
// Reverse every K nodes

// 3
// 1 2 3 4 5 6 7 8 9 10 a

// 3 2 1 6 5 4 9 8 7 10 

// void reverseKNodes(ListNode** head, int K){
//     ListNode *segmentFront = *head;
//     ListNode *temp = *head;
//     for (int i = 0; i < K-1; i++)
//     {
//         ListNode *target = temp -> next;
//         temp -> next = target -> next;
//         target -> next = segmentFront;
//         *head = target;
//     }
// }

void reverseKNodes(ListNode** head, int K){  
    if (*head == NULL)
    {
        return;
    }
    ListNode *current, *prev, *next;
    current = *head;
    prev = NULL;
    int count = 0;
    while (current != NULL && count < K)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        reverseKNodes(head, K);

    *head = prev;

    printListAddress(*head);
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