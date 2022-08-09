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
    numPair += lsSize;
    // Traverse linked list clockwise and anticlockwise, check if there is a mountain pair
    // It is a mountain pair if there are no mountains taller than both nodes

    // Logic:
    // Find the next greater mountain that is not an adjacent mountain
    // Check Clockwise and anticlockwise
    CDblListNode *cur = CDLL.head;
    CDblListNode *next = cur;
    CDblListNode *prev = cur;
    int flagLeft, flagRight;
    int doubleCount = 0;
    for (int i = 0; i < lsSize; i++)
    {
        flagLeft = 1;
        flagRight = 1;
        for (int j = 0; j < lsSize - 2; j++)
        {
            next = next->next;
            prev = prev->pre;

            if (flagLeft && j > 0 && cur ->item == prev->item)
            {
                printf("j:%d cur:%d prev:%d next:%d  FL:%d FR:%d \n",j, cur->item,prev->item,next->item,flagLeft,flagRight);
                numPair++;
            }
            else if (flagRight && j > 0 && cur ->item == next->item)
            {
                printf("j:%d cur:%d prev:%d next:%d  FL:%d FR:%d \n",j, cur->item,prev->item,next->item,flagLeft,flagRight);
                numPair++;
            }
            else if (flagLeft && j > 0 && cur ->item < prev->item)
            {
                printf("j:%d cur:%d prev:%d next:%d  FL:%d FR:%d \n",j, cur->item,prev->item,next->item,flagLeft,flagRight);
                numPair++;
            }
            else if (flagRight && j > 0 && cur ->item < next->item)
            {
                printf("j:%d cur:%d prev:%d next:%d  FL:%d FR:%d \n",j, cur->item,prev->item,next->item,flagLeft,flagRight);
                numPair++;
            }
            // printf("Flagleft:%d, Flagright: %d\n",flagLeft, flagRight);
            if (flagLeft == 0 && flagRight == 0)
            {
                break;
            }

            if (cur->item < next->item)
            {
                flagRight = 0;
            }
            if (cur->item < prev->item)
            {
                flagLeft = 0;
            }

        }
       
        cur = cur->next;
        next = cur;
        prev = cur;
    }
    return numPair - doubleCount;
}
// 5 2 2 4 3
// (5,2), (2,2), (2,4), (4,3), (3,5), (4,5), (5,2), (2,4)

