#include <stdio.h>
#include <string.h>

int main()
{
    FILE *input1 = fopen("names1.txt", "r");
    FILE *input2 = fopen("names2.txt", "r");
    FILE *output = fopen("namesout.txt", "w");
    char name1[100], name2[100];
    int fileend1 = 1, fileend2 = 1;
    if (/*fscanf(input2, "%s", name2)==EOF*/ fgets(name2,200,input2)== NULL)
    {
        fileend2 = 0;
    }
    name2[strlen(name2)-2]='\0';
    if (/*fscanf(input1, "%s", name1)==EOF*/ fgets(name1,200,input1)== NULL)
    {
        fileend1 = 0;
    }
    name1[strlen(name1)-2]='\0';
    while (1)
    {
        if (fileend1 && fileend2)
        {
            if (strcmp(name1, name2) > 0)
            {
                fprintf(output, "%s\n", name2);
                if (/*fscanf(input2, "%s", name2)==EOF*/ fgets(name2,200,input2)== NULL)
                {
                    fileend2 = 0;
                }
                name2[strlen(name2)-2]='\0';
            }
            else
            {
                fprintf(output, "%s\n", name1);
                if (/*fscanf(input1, "%s", name1)==EOF*/ fgets(name1,200,input1)== NULL)
                {
                    fileend1 = 0;
                }
                name1[strlen(name1)-2]='\0';
            }
        }
        else if (fileend1 == 0 && fileend2)
        {
            fprintf(output, "%s\n", name2);
            if (/*fscanf(input2, "%s", name2)==EOF*/ fgets(name2,200,input2)== NULL)
            {
                fileend2 = 0;
            }
            name2[strlen(name2)-2]='\0';
        }
        else if (fileend2 == 0 && fileend1)
        {
            fprintf(output, "%s\n", name1);
            if (/*fscanf(input1, "%s", name1)==EOF*/ fgets(name1,200,input1)== NULL)
            {
                fileend1 = 0;
            }
            name1[strlen(name1)-2]='\0';
        }
        else
        {
            break;
        }
    }
}