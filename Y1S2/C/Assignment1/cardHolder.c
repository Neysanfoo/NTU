/*
The NTU Name Card Holder has a capacity of MAX (e.g., 5 for this program)
name cards. You are required to write a NTU Name Card Holder Management Program.
The program uses an array of MAX structures for the name card holder.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

typedef struct
{
    int nameCardID;
    char personName[20];
    char companyName[20];
} NameCard;

void options(void);
void listNameCards(int current_size, NameCard *nameCards);
NameCard addNameCard(int nameCardID, char personName[20], char companyName[20]);
int removeNameCard(int current_size, NameCard *nameCards);
void bubbleSort(int current_size, NameCard *nameCards);
void getNameCard(int current_size, NameCard *nameCards);
int checkExistance(int current_size, int ID, NameCard *nameCards);

int main(void)
{
    NameCard nameCards[MAX];
    int current_size = 0;
    options();
    int choice;
    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("listNameCards():\n");
            if (current_size > 0)
            {
                listNameCards(current_size, nameCards);
            }
            else
            {
                printf("The name card holder is empty\n");
            }
            break;
        case 2:
        {
            char temp;
            printf("addNameCard():\n");
            int nameCardID;
            printf("Enter nameCardID:\n");
            scanf("%d", &nameCardID);
            char personName[20], companyName[20];
            printf("Enter personName:\n");
            scanf("%c", &temp);
            scanf("%[^\n]s", personName);
            printf("Enter companyName:\n");
            scanf("%c", &temp);
            scanf("%[^\n]s", companyName);
            if (current_size >= 5)
            {
                printf("The name card holder is full\n");
            }
            else if (checkExistance(current_size, nameCardID, nameCards) == 1)
            {
                nameCards[current_size] = addNameCard(nameCardID, personName, companyName);
                current_size++;
                printf("The name card has been added successfully\n");
                bubbleSort(current_size, nameCards);
            }
            else
            {
                printf("The nameCardID has already existed\n");
            }
            break;
        }
        case 3:
            printf("removeNameCard():\n");
            if (current_size == 0)
            {
                char temp[20];
                printf("Enter personName:\n");
                scanf("%s", temp);
                printf("The name card holder is empty\n");
            }
            else
            {
                int card_found = removeNameCard(current_size, nameCards);
                if (card_found == 1)
                {
                    current_size -= 1;
                }
                else
                {
                    printf("The target person name is not in the name card holder\n");
                }
            }

            break;
        case 4:
            printf("getNameCard():\n");
            if (current_size > 0)
            {
                getNameCard(current_size, nameCards);
            }
            else
            {
                printf("The target person name is not found\n");
            }
            break;
        case 5:
            return 0;
            break;
        }
    }
    printf("%d, %s, %s\n", nameCards[0].nameCardID, nameCards[0].personName, nameCards[0].companyName);
}

void options(void)
{
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM: \n"
           "1: listNameCards()\n"
           "2: addNameCard() \n"
           "3: removeNameCard() \n"
           "4: getNameCard() \n"
           "5: quit\n");
}
void listNameCards(int current_size, NameCard *nameCards)
{
    for (int i = 0; i < current_size; i++)
    {
        printf("nameCardID: %d\n", nameCards[i].nameCardID);
        printf("personName: %s\n", nameCards[i].personName);
        printf("companyName: %s\n", nameCards[i].companyName);
    }
}

NameCard addNameCard(int nameCardID, char personName[20], char companyName[20])
{
    NameCard new_card;
    new_card.nameCardID = nameCardID;
    strcpy(new_card.personName, personName);
    strcpy(new_card.companyName, companyName);
    return new_card;
}

int checkExistance(int current_size, int ID, NameCard *nameCards)
{
    for (int i = 0; i < current_size; i++)
    {
        if (nameCards[i].nameCardID == ID)
        {
            return 0; //already exists
        }
    }
    return 1;
}

int removeNameCard(int current_size, NameCard *nameCards)
{
    char target[20];
    char temp;
    printf("Enter personName:\n");
    scanf("%c", &temp);
    scanf("%[^\n]s", target);

    for (int i = 0; target[i] != '\0'; i++)
    {
        target[i] = tolower(target[i]);
    }

    for (int i = 0; i < current_size; i++)
    {
        int name_len = strlen(nameCards[i].personName);
        char nameInLower[name_len + 1];
        for (int c = 0; nameCards[i].personName[c] != '\0'; c++)
        {
            nameInLower[c] = tolower(nameCards[i].personName[c]);
        }
        nameInLower[name_len] = '\0';
        if (strcmp(nameInLower, target) == 0)
        {
            printf("The name card is removed\n");
            printf("nameCardID: %d\n", nameCards[i].nameCardID);
            printf("personName: %s\n", nameCards[i].personName);
            printf("companyName: %s\n", nameCards[i].companyName);
            if (current_size == 1)
            {
                return 1;
            }
            for (int j = i; j < current_size - 1; j++)
            {
                nameCards[j] = nameCards[j + 1];
            }
            return 1; // Name was found
        }
    }
    return 0;
}

void bubbleSort(int current_size, NameCard *nameCards)
{
    int noSwaps = 0;
    while (noSwaps == 0)
    {
        noSwaps = 1;
        for (int i = 0; i < current_size - 1; i++)
        {
            if (nameCards[i].nameCardID > nameCards[i + 1].nameCardID)
            {
                noSwaps = 0;
                NameCard temp = nameCards[i];
                nameCards[i] = nameCards[i + 1];
                nameCards[i + 1] = temp;
            }
        }
    }
}

void getNameCard(int current_size, NameCard *nameCards)
{
    char target[20];
    char temp;
    printf("Enter personName:\n");
    scanf("%c", &temp);
    scanf("%[^\n]s", target);
    int name_found = 0;

    for (int i = 0; target[i] != '\0'; i++)
    {
        target[i] = tolower(target[i]);
    }

    for (int i = 0; i < current_size; i++)
    {
        int name_len = strlen(nameCards[i].personName);
        char nameInLower[name_len + 1];
        for (int c = 0; nameCards[i].personName[c] != '\0'; c++)
        {
            nameInLower[c] = tolower(nameCards[i].personName[c]);
        }
        nameInLower[name_len] = '\0';
        if (strcmp(nameInLower, target) == 0)
        {
            printf("The target person name is found\n");
            printf("nameCardID: %d\n", nameCards[i].nameCardID);
            printf("personName: %s\n", nameCards[i].personName);
            printf("companyName: %s\n", nameCards[i].companyName);
            name_found = 1;
            break;
        }
    }
    if (name_found == 0)
    {
        printf("The target person name is not found\n");
    }
}