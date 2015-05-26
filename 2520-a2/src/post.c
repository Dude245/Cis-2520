//Nathan Reymer
//0797359

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked2.c"
#include <ctype.h>

int main(int argc, char**argv) {

    char* buffer=calloc(100,sizeof(char));
    ListNode *list = malloc(sizeof(struct node));
    list=NULL;
    char* token;
    char x;
    double first;
    double sec;
    double value;
    strcpy(buffer,argv[1]);
    int sLen=strlen(buffer);
    for(int c=0;c<sLen;c++)
        {
            x=buffer[c];
            if(isdigit(x))
                {
                    list=push(atoi(&x),list);
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
        printf("\n\nValue=%.2lf \n\n",value);
        return 0;
}
