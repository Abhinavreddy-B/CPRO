#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argv,char *argc[])
{
    int array[127];
    FILE *inp = fopen(/*"encrypt.txt"*/argc[2], "r");
    FILE *key = fopen(/*"key.txt"*/argc[1], "r");
    FILE *out = fopen(/*"decrypt.txt"*/argc[3], "w");
    int pos = 126;
    for (int i = 0; i < 127; i++)
    {
        fscanf(key, "%1d", &array[i]);
        //printf("%d",array[i]);
    }
    printf("\n");
    int value;
    unsigned int character=0;
    int count=0;
    while (fscanf(inp, "%1d", &value) != EOF)
    {
        if (pos == 126)
        {
            array[0] = (array[0] + array[126]) % 2;
            pos = 0;
            //printf("%d",array[pos]);
            character*=2;
            character+=value^array[0];
            count++;
        }
        else
        {
            array[pos + 1] = (array[pos] + array[pos + 1]) % 2;
            character*=2;
            character+=value^array[pos+1];
            pos++;
            //printf("%d",array[pos]);
            count++;
        }
        if(count==8){
            //printf("%c",character);
            fprintf(out,"%c",character);
            count=0;
        }
    }
    printf("\n\n");
}