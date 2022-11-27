#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITAL_EST 500
#define INCREMT 500
#define MAXLEN 100

typedef struct
{
    char *name;
    int frequency;
} word;

word *database;

void sort( int nonames)
{
    if(nonames==1){
        return;
    }
    for (int i = 1; i < nonames; i++)
    {
        if (strcmp((database + i)->name, (database + i - 1)->name) < 0)
        {
            word temp = *(database + i);
            *(database + i) = *(database + i - 1);
            *(database + i - 1) = temp;
        }
    }
    sort( nonames-1);
    return;
}

int main(int argv, char *argc[])
{
    int count = 0;
    char tempstr[MAXLEN];
    int maxlen = INITAL_EST;
    database = (word *)malloc(INITAL_EST * sizeof(word));
    for (int j = 2; j < argv; j++)
    {
        FILE *input = fopen(argc[j], "r");
        while (fscanf(input, "%s", tempstr) != EOF)
        {
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (strcmp(database[i].name, tempstr) == 0)
                {
                    database[i].frequency++;
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                if (count >= maxlen)
                {
                    maxlen += INCREMT;
                    database = (word *)realloc(database, maxlen * sizeof(word));
                }
                database[count].name = malloc((strlen(tempstr) + 1) * sizeof(char));
                strcpy(database[count].name, tempstr);
                database[count].frequency = 1;
                count++;
            }
        }
        fclose(input);
    }
    FILE *out = fopen(argc[1],"w");
    sort(count);
    for (int i = 0; i < count; i++)
    {
        fprintf(out,"%s:%d\n", database[i].name, database[i].frequency);
    }
}