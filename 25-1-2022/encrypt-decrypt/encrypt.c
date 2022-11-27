#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argv,char *argc[])
{
    srand(time(0));
    int array[127];
    FILE *inp = fopen(argc[1], "r");
    FILE *key = fopen(/*"key.txt"*/argc[2], "w");
    FILE *out = fopen(/*"encrypt.txt"*/argc[3], "w");
    int pos = 126;
    for (int i = 0; i < 127; i++)
    {
        array[i]=rand()%2;
        fprintf(key, "%d", array[i]);
        //printf("%d",array[i]);
    }

    unsigned char character;
    while (fscanf(inp, "%c", &character) != EOF/*0!=(character=fgetc(inp))*/)
    {
        //printf("\n%c\n", character);
        //printf("%d\n", character);
        int value=character;
        int ch[8];
        for (int i = 7; i >= 0; i--)
        {
            ch[i] = value % 2;
            value /= 2;
        }
        for (int i = 0; i < 8; i++)
        {
            //printf("%d",ch[i]);
            if (pos == 126)
            {
                array[0] = (array[0] + array[126]) % 2;
                pos = 0;
                //printf("%d",array[pos]);
                ch[i]=ch[i]^array[0];
            }
            else
            {
                array[pos + 1] = (array[pos] + array[pos + 1]) % 2;
                ch[i]=ch[i]^array[pos+1];
                pos++;
                //printf("%d",array[pos]);
            }
            //printf("%d",ch[i]);
            fprintf(out,"%d",ch[i]);
        }
        //printf(" ");
        //fprintf(out," ");
    }
    printf("\nSuccessfully encrypted\n");
    printf("\n");
}