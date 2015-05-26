//Nathan Reymer
//0797359

#include <stdio.h>
#include <stdlib.h>

int aMan(int m, int n);

int main(int argc, char**argv) {

int m, n,m2,n2;
printf("Enter the first number: \n");
scanf("%d",&m2);
printf("Enter the second number:\n");
scanf("%d",&n2);
        for (m = 0; m <= m2; m++)
                for (n = 0; n < n2 - m; n++)
                 printf("A(%d, %d) = %d\n", m, n, aMan(m, n));
}

int aMan(int m, int n)
{
        if(m==0)
            {
                return n+1;
            }
            else if (n == 0) {

                return aMan(m-1, 1);
            }
            else {
                return aMan(m-1, aMan(m,n-1));
            }


        }
