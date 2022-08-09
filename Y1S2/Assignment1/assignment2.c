#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
ListNode *Reverse(ListNode *head, int N);

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
    if (start == end)
    {
        return head;
    }
    ListNode *current, *prev, *next;
    ListNode *temp = head;
    ListNode *temp2 = head;

    for (int i = 0; i < start-1; i++)
    {
        temp = temp -> next;
    }

    for (int i = 0; i < end +1; i++)
    {
        temp2 = temp2 -> next;
    }

    ListNode *reverseMid = Reverse(temp -> next, end - start);
    temp -> next = reverseMid;
    while(reverseMid -> next != NULL)
    {
        reverseMid = reverseMid -> next;
    }
    reverseMid -> next = temp2;
    
    return head;
}

ListNode *Reverse(ListNode *head, int N)
{
    ListNode *current, *prev, *next;
    current = head;
    prev = NULL;
    for (int i = 0; i < N + 1; i++)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}