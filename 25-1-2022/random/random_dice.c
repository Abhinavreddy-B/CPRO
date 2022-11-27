#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define first

int main()
{
    srand(time(0));
    long int array[6] = {};
#ifdef first
    FILE *input = fopen("random_dice.txt", "w");
#endif
#ifndef first
    FILE *input = fopen("random_dice.txt", "a");
#endif
    for (long int i = 0; i < 1000000; i++)
    {
        array[rand() % 6]++;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", i + 1);
#ifdef first
        fprintf(input, "%d\t\t", i + 1);
#endif
    }
#ifdef first
    fprintf(input, "\n");
#endif
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%ld\t", array[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        fprintf(input, "%ld\t", array[i]);
    }
    fprintf(input, "\n");
}