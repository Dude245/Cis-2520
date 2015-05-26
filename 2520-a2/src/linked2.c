#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node ListNode;
struct node {
    double num;
    struct node *next;
}node;


struct node* push(double num,ListNode *head)
{
    ListNode *temp = malloc(sizeof(struct node));
    temp->num = num;
    temp->next = NULL;

if(head == NULL)
		head = temp;
	else
	{
		temp->next = head;
		head = temp;
	}

    return head;
}
double getTop(ListNode *head)
{
    double num;
    if(head==NULL)
        printf("Empty \n");

        return head->num;
    }
struct node* pop(ListNode *head)
{
    if(head==NULL)
        printf("Empty \n");

        ListNode *temp = malloc(sizeof(struct node));
        temp=head;

        head=head->next;
        free(temp);

        return head;
    }

double calc(char x,double first,double sec)
{
    if(x=='+')
        {
            return(first+sec);
        }
        if(x=='-')
            {
                return(first-sec);
            }
        if(x=='*')
            {
                return(first*sec);
            }
        if(x=='/')
            {
                return(first/sec);
            }
        else
            {
                return 0;
            }
}
