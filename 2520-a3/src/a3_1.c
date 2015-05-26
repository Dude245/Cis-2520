//Nathan Reymer
//0797359


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "linked1.c"

int main(int argc, char**argv) {
//argv[1]="(((x1+5.12)*(x2−7.68))/x3)";
char* buffer=calloc(300,sizeof(char));
strcpy(buffer,argv[1]);
printf("%s\n",buffer);
int choice=1;
double tempX;
double uVal;
int uChoice;
char * post;
char x;
char y;
char z;
int xCnt=0;
double xX[10];

int sLen=strlen(buffer);
for(int c=0;c<sLen;c++)
    {
        x=buffer[c];
        if(x=='x')
                    {
                        x=buffer[c+1];
                        tempX=x-'0';
                        xX[x]=0.00;
                        xCnt++;
                        c++;

                    }
                }
    while(choice!=7)
        {
            printf("\nEnter a number: \n");
            printf("1. Display \n");
            printf("2. Preorder \n");
            printf("3. Inorder \n");
            printf("4. Postorder \n");
            printf("5. Update \n");
            printf("6. Calculate \n");
            printf("7. Quit. \n");
            scanf("%d",&choice);
switch(choice)
    {
case 1:
xCnt=0;
for(int c=0;c<sLen;c++)
    {
        x=buffer[c];
            if(isdigit(x))
                {
                    y=buffer[c+2];
                    z=buffer[c+3];
                        {
                            printf("%d.%d%d\n",x-'0',y-'0',z-'0');
                        }
                        c=c+3;
                }
            if(x=='+')    {
                printf("+ UP \n");

                    }
            if(x=='-')
                        {
                        printf("- UP \n");

                        }
            if(x=='*')
                        {
                            printf("* UP \n");

                        }
            if(x=='/')
                        {
                            printf("/ UP \n");

                        }
            if(x=='x')
                        {
                            x=buffer[c+1];
                            printf("x%d VARIABLE \n",x-'0');
                            tempX=x-'0';
                            xX[x]=0.00;
                            xCnt++;
                            c++;

                        }
            if(x=='.')
                        {
                            printf(". NEXT \n");


                        }
            if(x=='(')
                        {
                            printf("( DOWN \n");

                        }
            if(x==')')
                        {
                            printf(") UP\n");
                        }


    }
break;
case 2:
printf("Preorder \n");

break;
case 3:
printf("Inorder \n");
printf("%s",argv[1]);
break;
case 4:
printf("\n%s\n",inToPost(argv[1],xX));
break;
case 5:
printf("Update variable (num): \n");
for(int i=0;i<xCnt;i++)
    {
        printf("x(%d) = %.2lf\n",i+1,xX[i]);
    }
    printf("x(num): ");
    scanf("%d",&uChoice);
    printf("Value: ");
    scanf("%lf",&uVal);
    xX[uChoice-1]=uVal;
    for(int i=0;i<xCnt;i++)
        {
            printf("x%d = %.2lf\n",i+1,xX[i]);
        }
break;
case 6:
post=inToPost(argv[1],xX);
postCalc(post,xX);
break;
case 7:
printf("Exit \n");
break;
default:
printf("Not an option \n");
}

}
}
