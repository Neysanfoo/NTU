#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void printListAddress(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp = NULL;
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
    if (temp != NULL)
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

void reverseKNodes(ListNode** head, int K){
    if (*head == NULL)
    {
        return;
    }
    if (K == 0 || K == 1)
    {
        return;
    }
    int listLen = 0;
    ListNode *count = *head;
    while (count != NULL)
    {
        count = count ->next;
        listLen++;
    }
    int segments = listLen / K;
    int segCount = 0;


    printListAddress(*head);
    ListNode *current, *prev, *next, *temp1, *temp2, *temp3;  
    temp1 = temp2 = temp3 = NULL;
    int i;

    next = *head;

    while (next != NULL)
    {
        i = 1;
        temp1 = next;
        current = next;
        prev = NULL;
        next = current -> next;
        while (next != NULL && segCount < segments)
        {
            current -> next = prev;
            prev = current;
            current = next;
            next = next -> next;
            i++;
            if (i == K )
            {
                segCount++;
                break;
            }
        }
        current -> next = prev;

        if (temp3 == NULL)
        {
            temp3 = current;
        }
        if (temp2 != NULL)
        {
            temp2 -> next = current;
        }
        temp2 = temp1;
    }
    
    *head = temp3;
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