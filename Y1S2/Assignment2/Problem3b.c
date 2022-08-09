#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int  item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist{
   int size;
   CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i,cases;
    int numP;
    scanf("%d",&cases);
    for(i=0; i<cases; i++)
    {
        while(scanf("%d",&item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n",numP);

        deleteList(&himalayas);
    }
    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value){
      //create a new node
      CDblListNode* newNode;
      newNode = (CDblListNode *) malloc(sizeof(CDblListNode));
      newNode->item = value;

      if(ptrCDLL->size==0) //first node
      {
          newNode->next = newNode;
          newNode->pre = newNode;
          ptrCDLL->head = newNode;
      }
      else{
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; //update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
      }
      ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL){

    if(CDLL.head==NULL) return;

    CDblListNode* temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head){
        printf("%d ", temp->item);
        temp = temp->next;

    }
    printf("%d\n",temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL){
    if(ptrCDLL->head==NULL) return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next!= ptrCDLL->head) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }

    free(cur);
    ptrCDLL->head =NULL;
    ptrCDLL->size =0;

}



int numMountainPairs(CDblLinkedList CDLL)
{
    if (CDLL.size == 2)
    {
        return 1;
    }
    if (CDLL.size == 1)
    {
        return 0;
    }
    int numPair = 0;
    int doubleCount = 0;
    int lsSize = CDLL.size;
    numPair += lsSize;
    CDblListNode *cur = CDLL.head;
    CDblListNode *tail = cur -> next -> next;
    CDblListNode * temp = cur -> next;
    for (int i = 0; i < lsSize; i++)
    {
        while (tail != cur && tail != cur -> pre)
        {
            int minH = (cur -> item < tail -> item) ? cur -> item :  tail -> item;
            int isVisibleLeft = 1;
            int isVisibleRight = 1;
            while (temp != tail)
            {
                if (temp -> item > minH)
                {
                    isVisibleRight = 0;
                    break;
                }
                temp = temp -> next;
            }
            temp = tail -> next;
            while (temp != cur)
            {
                if (temp -> item > minH)
                {
                    isVisibleLeft = 0;
                    break;
                }
                temp = temp -> next;
            }
            if (isVisibleLeft || isVisibleRight)
            {
                printf("%d", cur -> item);
                doubleCount++;
            }
            tail = tail -> next;
            temp = cur -> next;
        }
        
        cur = cur -> next;
        tail = cur -> next -> next;
        temp = cur -> next;
    }
    return numPair + doubleCount/2;
}