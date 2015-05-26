#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node ListNode;
struct node {
    double num;
    char sym;
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
        printf("Empty Top \n");

        return head->num;
    }
struct node* pop(ListNode *head)
{
    if(head==NULL)
        printf("Empty Pop\n");

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
void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
