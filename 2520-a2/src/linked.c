#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct car ListNode;
struct car {
    int mileage;
    char * plate;
    int rDate;
    struct car *next;
}car;

void printL (ListNode *head);
void addToBack(int mileage, char * plate, int rDate, ListNode *head);
struct car* search(ListNode *head, char * plate);
void sort(ListNode *head, int type);
void removeFront(ListNode * head);
struct car* removeCar(ListNode * head, char * plate, int mileage,ListNode *addTo);
void killEnd(ListNode *head);
struct car* killFront(ListNode *head);
void printL (ListNode *head) {
    int mileage;
    char * plate;
    int rDate;
    while (head!=NULL) {
        printf("Mileage: %d \nPlate: %s \nReturn Date: %d \n\n",head->mileage,head->plate,head->rDate);
        head = head->next;
    }
}
struct car* search(ListNode *head, char * plate)
{
    struct car *temp;
    struct car *returnd=NULL;
    temp = head;
    while(temp!=NULL)
        {
            if((strcmp(plate,temp->plate) == 0))
                {

                    returnd=temp;
                }
                temp = temp->next;
            }
            return (returnd);
        }
struct car* addToEmpty(int mileage, char * plate, int rDate, ListNode *head)
{
    ListNode *back = malloc(sizeof(struct car));

    back->mileage = mileage;
    back->plate=plate;
    back->rDate=rDate;
    back->next=NULL;


    return (back);
}
void addToBack(int mileage, char * plate, int rDate, ListNode *head)
{

    ListNode *back = malloc(sizeof(struct car));

    back->mileage = mileage;
    back->plate=plate;
    back->rDate=rDate;
    back->next = NULL;

    ListNode *current = head;
    while (head!=NULL)
        {
            if(current->next == NULL)
                {
                    current->next = back;
                    break;
                }
                current = current->next;
            }


}
void sort(ListNode *head, int type)
{
    ListNode * temphead = head;
    int counter = 0;
    while (temphead)
        {
            temphead = temphead->next;
            counter++;
        }
        temphead = head;
        struct car *curr=head;
        struct car *prev;
        struct car *temp=head;
        int tMile;
        char * tPlate;
        int tRDate;
        if(type==1)
            {
                for (int j=0; j<counter; j++)
                    {
                        while (curr->next)
                            {
                                if(curr->mileage > curr->next->mileage)
                                    {

                                        tMile = curr->mileage;
                                        tPlate = curr->plate;
                                        tRDate = curr->rDate;

                                        curr->mileage=curr->next->mileage;
                                        curr->plate=curr->next->plate;
                                        curr->rDate=curr->next->rDate;

                                        curr->next->mileage=tMile;
                                        curr->next->plate=tPlate;
                                        curr->next->rDate=tRDate;

                                    }
                                    else
                                        {
                                            curr=curr->next;
                                        }
                                    }
                                    curr = head;
                                }
                            }
        else if(type==2)
        {
            for (int j=0; j<counter; j++)
                {
                    while (curr->next)
                        {
                            if(curr->rDate > curr->next->rDate)
                                {

                                    tMile = curr->mileage;
                                    tPlate = curr->plate;
                                    tRDate = curr->rDate;

                                    curr->mileage=curr->next->mileage;
                                    curr->plate=curr->next->plate;
                                    curr->rDate=curr->next->rDate;

                                    curr->next->mileage=tMile;
                                    curr->next->plate=tPlate;
                                    curr->next->rDate=tRDate;

                                }
                                else
                                    {
                                        curr=curr->next;
                                    }
                                }
                                curr = head;
                            }
                        }
                    }
void removeFront(ListNode * head)
{
                struct car * temp = head;
                temp=temp->next;
                free(temp);
            }
struct car* removeCar(ListNode * head, char * plate, int mileage, ListNode *addTo)
{
    struct car *temp=head;
    struct car *prev;
    struct car *searched;
    struct car *last;
    int i;
    int count=0;
    int pos=0;
    while(temp!=NULL)
        {
            count++;
            if((strcmp(plate,temp->plate) == 0))
                {
                    pos=count;
                }
                if(temp->next==NULL)
                    {
                        last=temp;
                    }

                    temp=temp->next;
                }
                if(pos==0)
                    {
                        printf("Not found \n");
                    }
                    else if (pos==1)
                    {
                        searched=search(head,plate);
                        addToBack(mileage,searched->plate,searched->rDate,addTo);
                        head=killFront(head);

                    }
                    else if(pos==count)
                    {
                        searched=search(head,plate);
                        killEnd(head);

                        addToBack(mileage,searched->plate,searched->rDate,addTo);
                    }
                    else{
                        temp=head;

                            searched=search(head,plate);
                            addToBack(mileage,searched->plate,searched->rDate,addTo);

                        }
                        return(head);

}
void killEnd(ListNode *head)
{
    struct car *temp;
    struct car *last;
    temp=head;
    last=head;
    while(temp != NULL && temp->next!=NULL)
        {
            last=temp;
            temp=temp->next;
        }
        if(last == temp)
            {
                head=NULL;
            } else {
                free(last->next);
                last->next = NULL;
            }
        }
struct car* killFront(ListNode *head) {
if (head != NULL) {
    head = head->next;
}
return (head);

}
double countRented (ListNode *head) {
    double mileage;
    double tTotal;
    double total;
    while (head!=NULL) {
        mileage=head->mileage;
        if(mileage<=100)
            {
                mileage=40;
            }
            else
                {
                    mileage=mileage-100;
                    tTotal=40+(.15*mileage);
                }
        tTotal=tTotal+mileage;
        total=total+tTotal;
        head = head->next;
    }
    return total;
}
