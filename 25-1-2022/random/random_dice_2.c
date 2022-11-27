#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(0));
    long int array[11]={};
    for (long int i = 0; i < 1000000; i++)
    {
       array[rand()%6+rand()%6]++;
    }
    for (int i = 0; i < 11; i++)
    {
        printf("%d\t",i+2);
    }
    printf("\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%ld\t",array[i]);
    }
    printf("\n");
}