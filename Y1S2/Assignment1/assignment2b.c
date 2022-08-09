#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
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

ListNode *reverseSegment(ListNode* head, int start, int end)
{
    ListNode *findSize = head;
    int size = 0;
    while(findSize != NULL)
    {
        findSize = findSize -> next;
        size ++;
    }
    if ((start < 0) || (end > size -1 ))
    {
        return head;
    }
    printf("%d\n",size);
    ListNode *temp = head;
    for (int i = 0; i < start - 1; i++)
    {
        temp = temp -> next;
    }
    ListNode *prev, *current, *next;
    prev = temp;
    current = temp -> next;
    next = current;
    for (int i = 0; i<end-start; i++)
    {
        next = next -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    if (start == 0)
    {
        head = prev;
        temp -> next = next;
    }
    else{
        next = next -> next;
        current -> next = prev;
        prev = current;
        current = next;
        temp -> next -> next = next;
        temp -> next = prev;
    }
    return head;
    
}
