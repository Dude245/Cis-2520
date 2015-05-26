//Nathan Reymer
//0797359

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Newtons method
//Use of doubles instead of int to be more precise
double rSqrt(int x, double e);
double rSqrtR(long x, double e, double a);
int main(int argc, char**argv) {

//Non-Recurive function
    double x;
    double e;
    double a;
    printf("Enter x: ");
    scanf("%lf",&x);
    printf("Enter e: ");
    scanf("%lf",&e);

    clock_t start = clock();
    rSqrt (x,e);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time(s): %lf \n",seconds);


    //Recursive Function
    printf("Enter x: ");
    scanf("%lf",&x);
    printf("Enter e: ");
    scanf("%lf",&e);
    printf("Enter a: ");
    scanf("%lf",&a);

    start = clock();
    rSqrtR(x,e,a);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time(s): %lf \n",seconds);


    return 0;
}

double rSqrt(int x, double e){
    double a=x/2;
    while(a*a-x>e)
        {
            a=((a+(x/a))/2);
            printf("a: %lf \n",a); //Display Progress
        }
        printf("Done \n"); //Display Completed

        return 0;
}
double rSqrtR(long x, double e, double a){

        if ((a * a - x) <= e) {
            printf("Done \n"); //Display Completed
            return a;
        } else {
            a = (a * a + x) / (2 * a);
            printf("a: %lf \n",a); //Display Progress
            return 1.0 *(rSqrtR(x, e, a));
        }
    }
