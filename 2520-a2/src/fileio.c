#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct car* readFileAvail()
{
    ListNode *head = malloc(sizeof(struct car));
    struct car* avail;
    FILE *fp;
    fp = fopen("cars.db","r");
    char buff[50];
    char* token;
    token= strtok(buff, " ");
    int mileage;
    int rDate;
    int count=0;
    int plateLen;
    while(fgets (buff, 50, fp)!=NULL)
        {
            char* plate=calloc(50,sizeof(char));
            token= strtok(buff, ":");
            if(strcmp(token,"Available") == 0)
                {
                    strncpy(plate,"TITS",6);
                    fgets (buff, 50, fp);
                    mileage=atoi(buff);
                    fgets (buff, 50, fp);
                    plateLen=strlen(buff);
                    strncpy(plate,buff,plateLen-1);
                    fgets (buff, 50, fp);
                    rDate=atoi(buff);


                    if(count==0)
                        {
                            head=addToEmpty(mileage,plate,rDate,head);
                            count++;
                        }
                        else
                            addToBack(mileage,plate,rDate,head);
                        }

                    }


                    fclose(fp);
                    return head;
                }
struct car* readFileRented()
{
    ListNode *head = malloc(sizeof(struct car));
    struct car* avail;
    FILE *fp;
    fp = fopen("cars.db","r");
    char buff[50];
    char* token;
    token= strtok(buff, " ");
    int mileage;
    int rDate;
    int plateLen;
    int count=0;
    while(fgets (buff, 50, fp)!=NULL)
        {
            char* plate=calloc(50,sizeof(char));
            token= strtok(buff, ":");
            if(strcmp(token,"Rented") == 0)
                {
                    fgets (buff, 50, fp);

                    mileage=atoi(buff);
                    fgets (buff, 50, fp);

                    plateLen=strlen(buff);
                    strncpy(plate,buff,plateLen-1);
                    fgets (buff, 50, fp);

                    rDate=atoi(buff);


                    if(count==0)
                        {
                            head=addToEmpty(mileage,plate,rDate,head);
                            count++;
                        }
                        else
                            addToBack(mileage,plate,rDate,head);
                        }

                    }


                    fclose(fp);
                    return head;


                }
struct car* readFileRepair()
{
    ListNode *head = malloc(sizeof(struct car));
    struct car* avail;
    FILE *fp;
    fp = fopen("cars.db","r");
    char buff[50];
    char* token;
    token= strtok(buff, " ");
    int mileage;
    int rDate;
    int plateLen;
    int count=0;

    while(fgets (buff, 50, fp)!=NULL)
        {
            char* plate=calloc(50,sizeof(char));
            token= strtok(buff, ":");
            if(strcmp(token,"Repair") == 0)
                {
                    fgets (buff, 50, fp);

                    mileage=atoi(buff);
                    fgets (buff, 50, fp);

                    plateLen=strlen(buff);
                    strncpy(plate,buff,plateLen-1);
                    fgets (buff, 50, fp);

                    rDate=atoi(buff);


                    if(count==0)
                        {
                            head=addToEmpty(mileage,plate,rDate,head);
                            count++;
                        }
                        else
                            addToBack(mileage,plate,rDate,head);
                        }

                    }


                    fclose(fp);
                    return head;


                }

void writeFile(ListNode *avail,ListNode *rented,ListNode *repair)
{
    struct car* head;
    FILE *fp;
    fp = fopen("cars.db","w");
    int mileage;
    char * plate;
    int rDate;
    head=avail;
    while (head!=NULL) {
        fprintf(fp,"Available: \n");
        fprintf(fp,"%d\n%s\n%d\n\n",head->mileage,head->plate,head->rDate);
        head = head->next;
    }
    head=rented;
    while (head!=NULL) {
        fprintf(fp,"Rented: \n");
        fprintf(fp,"%d\n%s\n%d\n\n",head->mileage,head->plate,head->rDate);
        head = head->next;
    }
    head=repair;
    while (head!=NULL) {
        fprintf(fp,"Repair: \n");
        fprintf(fp,"%d\n%s\n%d\n\n",head->mileage,head->plate,head->rDate);
        head = head->next;
    }

    fclose(fp);
}
