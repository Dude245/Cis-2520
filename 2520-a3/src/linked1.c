#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linked2.c"

char* inToPost(char a[], double var[])
{
  char x;
  char temp;
  double varDbl;
  int wX;
  char *s;
  char * string;
  int top;

  int i, n = strlen ( a );
  strcpy(string,"");
  s = malloc (sizeof(*s)*n);
  top = 0;
  for ( i = 0; i < n; i++ ) {
    if(a[i]=='x')
      {
      temp=a[i+1];
      append(string, 'x');
      append(string,temp);
      i+=2;
    }
    if ( a[i] == ')' )
      append(string,s[--top]);
    if ( a[i] == '+' || a[i] == '*' || a[i]=='-' || a[i]=='/')
      s[top++] = a[i];


    if ( isdigit (a[i]) )
      {
      append(string,a[i]);
      append(string,'.');
      append(string,a[i+2]);
      append(string,a[i+3]);
      i=i+3;
    }
  }
  return string;
}


void postFx(char * exP,double var[]) {
    char* buffer=calloc(100,sizeof(char));
    ListNode *list = malloc(sizeof(struct node));
    list=NULL;
    char* token;
    char x;
    char temp;
    double varDbl;
    int wX;
    double first;
    double sec;
    double value;
    strcpy(buffer,exP);

    char *dbl;

    int sLen=strlen(buffer);
    for(int c=0;c<sLen;c++)
        {
            x=buffer[c];
            if(isdigit(x))
                {
                    dbl[0]=x;
                    dbl[1]='.';
                    dbl[2]=buffer[c+2];
                    dbl[3]=buffer[c+3];
                    list=push(atof(dbl),list);
                    c=c+3;
                }
                else  if(x=='x')
          {
            temp=buffer[c+1];
            wX=atoi(&temp);
            varDbl=var[wX];

            list=push(varDbl,list);
            c+=1;

          }

                else
                    {
                        sec=getTop(list);
                        list=pop(list);
                        first=getTop(list);
                        list=pop(list);
                        value=calc(x,first,sec);
                        list=push(value,list);
                    }
        }
        value=getTop(list);
        list=pop(list);
}
void postCalc(char * exP,double var[]) {
    char* buffer=calloc(100,sizeof(char));
    ListNode *list = malloc(sizeof(struct node));
    list=NULL;
    char* token;
    char x;
    char temp;
    double varDbl;
    int wX;
    double first;
    double sec;
    double value;
    strcpy(buffer,exP);
    char *dbl;

    int sLen=strlen(buffer);
    for(int c=0;c<sLen;c++)
        {
            x=buffer[c];
            if(isdigit(x))
                {
                    dbl[0]=x;
                    dbl[1]='.';
                    dbl[2]=buffer[c+2];
                    dbl[3]=buffer[c+3];
                    list=push(atof(dbl),list);
                    c=c+3;
                }
                else  if(x=='x')
          {
            temp=buffer[c+1];
            wX=atoi(&temp);
            varDbl=var[wX-1];
            list=push(varDbl,list);
            c+=1;

          }
                else
                    {
                        sec=getTop(list);
                        list=pop(list);
                        first=getTop(list);
                        list=pop(list);
                        value=calc(x,first,sec);
                        list=push(value,list);
                    }
        }
        value=getTop(list);
        list=pop(list);
        printf("Calculated: %.2lf \n",value);
}
