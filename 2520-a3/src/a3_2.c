//Nathan Reymer
//0797359

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char**argv) {


FILE *fp;
fp = fopen("f.dat","r");
char buff[300];
char* token;
int count=0;
int i=0;
int line [10];
int array[20][10];
int key=0;
int value=0;


for(int l=0;l<20;l++)
  {

      (fgets (buff, 300, fp));
    token= strtok(buff, " ");
    for(int i=0;i<10;i++)
        {
    line[i]=atoi(token);
    token= strtok(NULL, " ");
    if(token==NULL)
        break;
}
for(int i=0;i<10;i++)
array[l][i]=line[i];

  }

    fclose(fp);
for(int i=0;i<20;i++)
    {
        printf("\nKEY: %d Data: ",array[i][0]+array[i][1]+array[i][2]);
        for(int j=0;j<10;j++)
   printf("%d ",array[i][j]);
    }
printf("\n");

//SWAP

        int tArray[10];
        for(int p=0;p<10;p++)
            {
        for(int i=0;i<19;i++)
            {
                int key1=0;
                int key2=0;

key1=array[i][0]+array[i][1]+array[i][2];
key2=array[i+1][0]+array[i+1][1]+array[i+1][2];

                        if(key1>key2)
                            {
                                for(int sw=0;sw<10;sw++)
                                    {

                                    }
                            for(int sw=0;sw<10;sw++)
                                {
                                    tArray[sw]=array[i][sw];
                                    array[i][sw]=array[i+1][sw];
                                array[i+1][sw]=tArray[sw];
}

                        }
                    }
                }
                for(int i=0;i<20;i++)
                    {
                    //    printf("\n");
                        printf("\nKEY: %d Data: ",array[i][0]+array[i][1]+array[i][2]);
                        for(int j=0;j<10;j++)
                   printf("%d ",array[i][j]);
                    }
                    printf("\n");
                }
