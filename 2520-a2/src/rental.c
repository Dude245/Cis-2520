//Nathan Reymer
//0797359


#include <stdio.h>
#include <stdlib.h>
#include "linked.c"
#include "fileio.c"

int main(int argc, char**argv) {

    int choice=0;

    char plate[20];
    int mileage;
    int rDate;
    double tTotal;
    double tMileage;
    double total;
    int tRet;


    struct car *avail;
    struct car *rented;
    struct car *repair;
    struct car *node;


    avail = malloc(sizeof(struct car) );
    rented = malloc(sizeof(struct car) );
    repair = malloc(sizeof(struct car) );
    node = malloc(sizeof(struct car) );


    //Read Data from File
    avail=readFileAvail();
    rented=readFileRented();
    repair=readFileRepair();

    while(choice!=7)
        {
          mileage=0;
            sort(avail,1);
            sort(rented,2);
            sort(repair,1);
            printf("Enter a number: \n");
            printf("1. add a new car to the available-for-rent list \n");
            printf("2. add a returned car to the available-for-rent list \n");
            printf("3. add a returned car to the repair list \n");
            printf("4. transfer a car from the repair list to the available-for-rent list \n");
            printf("5. rent the first available car \n");
            printf("6. print all the lists \n");
            printf("7. quit. \n");
            scanf("%d",&choice);

            if(choice==1)
                {
                    printf("Plate Number?:\n");
                    scanf("%s",plate);
                    printf("Mileage?:\n");
                    scanf("%d",&mileage);
                    if(avail!=NULL)
                        {
                    addToBack(mileage,plate,0,avail);
                        }
                    else if (avail==NULL)
                    {
                    avail=addToEmpty(mileage,plate,0,avail);
                    }
                }
            else if(choice==2)
            {
                printf("Plate Number?:\n");
                scanf("%s",plate);
                printf("Mileage?:\n");
                scanf("%d",&mileage);
                node=search(rented,plate);
                if(node!=NULL)
                    {
                        tMileage=node->mileage;
                        if(tMileage<=100)
                            {
                                tTotal=40;
                            }
                        else
                            {
                                tMileage=tMileage-100;
                                tTotal=40+(.15*tMileage);
                            }
                            total=total+tTotal;
                            printf("$%.2lf \n",tTotal);
                            if(rented->next->next!=NULL)
                            {
                            rented=removeCar(rented,plate,mileage,avail);
                            }

                            else if(avail==NULL)
                                {
                                    avail=addToEmpty(mileage,node->plate,node->rDate,avail);
                                }
                        printf("\nAdded returned car to the Available for rent list \n");
                        }
            else
                printf("Not Found \n");

            }
            else if(choice==3)
            {

                printf("Plate Number?:\n");
                scanf("%s",plate);
                printf("Mileage?:\n");
                scanf("%d",&mileage);
                node=search(rented,plate);
                if(node!=NULL)
                    {
                        tMileage=node->mileage;
                        if(tMileage<=100)
                            {
                                tTotal=40;
                            }
                            else
                                {
                                    tMileage=tMileage-100;
                                    tTotal=40+(.15*tMileage);
                                }
                                total=total+tTotal;
                                printf("$%.2lf \n",tTotal);

                                if(rented!=NULL)
                                {
                                rented=removeCar(rented,plate,mileage,repair);
                                }

                                if(repair==NULL)
                                    {
                                        repair=addToEmpty(mileage,node->plate,node->rDate,repair);
                                    }
                                    printf("\nAdded returned car to the Repair list \n");
                            }
                            else
                                {
                                    printf("Not Found \n");
                                }

            }
            else if(choice ==4)
            {
                printf("Plate Number?:\n");
                scanf("%s",plate);
                node=search(repair,plate);
                if(node!=NULL)
                    {
                        tMileage=node->mileage;
                        if(tMileage<=100)
                            {
                                tTotal=40;
                            }
                            else
                                {
                                    tMileage=tMileage-100;
                                    tTotal=40+(.15*tMileage);
                                }
                                total=total+tTotal;
                                printf("$%.2lf \n",tTotal);
                                repair=removeCar(repair,plate,node->mileage,avail);
                                printf("\nTransfered car from the Repair list to the Available for rent list  \n");

                            }
                            else
                                {
                                    printf("Not Found \n");
                                }
                            }
                else if(choice ==5)
                {
                            if(avail!=NULL)
                              {
                            printf("Expected Return Date (yymmdd): \n");
                            scanf("%d",&rDate);
                            addToBack(avail->mileage,avail->plate,rDate,rented);
                            avail=killFront(avail);
                          }
                          else
                            {
                              printf("Sorry, List Empty\n");
                            }

                }
                else if(choice==6)
                {

                    printf("\nAvailable: \n\n");
                    printL(avail);
                    printf("\nRented: \n\n");
                    printL(rented);
                    printf("\nRepair: \n\n");
                    printL(repair);
                    printf("\n");
                }
            else if(choice==7)
            {
                writeFile(avail,rented,repair);
                total=countRented(rented);
            }
        else
            {
                printf("Not an option \n");
            }
        }

    printf("Total Rental Income: $%.2lf \n",total);

    return 0;
}
