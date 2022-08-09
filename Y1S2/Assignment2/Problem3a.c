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
    int numPair = 0;
    int lsSize = CDLL.size;
    // numPair += lsSize;
    CDblListNode *cur = CDLL.head;
    CDblListNode *next = cur -> next;
    CDblListNode *prev = cur -> pre;
    int flagLeft, flagRight;
    for (int i = 0; i < lsSize; i++)
    {
        while (cur != next)
        {
            if (cur -> item < next -> item)
            {
                numPair++;
                printf("cur:%d next:%d  \n",cur->item,next->item);
                break;
            }
            if (cur -> next == next)
            {
                next = next -> next;
                continue;
            }
            if (cur -> item  == next -> item )
            {
                numPair++;
                printf("cur:%d next:%d  \n",cur->item,next->item);
                next = next -> next;
                continue;
            }
            if (cur -> item  > next -> item )
            {
                next = next -> next;
                continue;
            }
            
        }
        next = next -> next;
        while (prev != next)
        {
            if (cur -> item  < prev -> item )
            {
                numPair++;
                printf("cur:%d prev:%d  \n",cur->item,prev->item);
                break;
            }
            if (cur -> pre == prev)
            {
                prev = prev -> pre;
                continue;
            }
            if (cur -> item  == prev -> item )
            {
                numPair++;
                printf("cur:%d prev:%d  \n",cur->item,prev->item);
                prev = prev -> pre;
                continue;
            }
            if (cur -> item  > prev -> item )
            {
                prev = prev -> pre;
                continue;
            }
        }
        cur = cur -> next;
        next = cur -> next;
        prev = cur -> pre;
    }
    return numPair;
}