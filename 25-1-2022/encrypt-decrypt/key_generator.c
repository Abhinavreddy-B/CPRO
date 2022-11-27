#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    FILE *key=fopen("key.txt","w");
    for (int i = 0; i < 127; i++)
    {
        fprintf(key,"%d",rand()%2);
    }
}