#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define first                   ////define this if its the first observation / you want to overwrite the file

//
//Run the file as ./a.out <output file name>
//

int main(int argv,char * argc[])
{
    if(argv!=2){
        printf("Please follow the format given in the file\n");
        return 0;
    }
    srand(time(0));
    long int array[10] = {};
#ifdef first
    FILE *input = fopen(argc[1], "w");
#endif
#ifndef first
    FILE *input = fopen(argc[1], "a+");
#endif
    for (long int i = 0; i < 1000000; i++)
    {
        array[rand() % 6 + rand() % 6 ]++;
    }
    printf("\nvalue:\t\t");
    for (int i = 0; i < 11; i++)
    {
        printf("%d\t", i+2);
#ifdef first
        fprintf(input, "%d\t\t", i+2);
#endif
    }
#ifdef first
    fprintf(input, "\n");
#endif
    printf("\n");
    printf("frequency:\t");
    for (int i = 0; i < 11; i++)
    {
        printf("%ld\t", array[i]);
    }
    for (int i = 0; i < 11; i++)
    {
        fprintf(input, "%ld\t", array[i]);
    }
    fprintf(input, "\n");
    printf("\n\n");
}