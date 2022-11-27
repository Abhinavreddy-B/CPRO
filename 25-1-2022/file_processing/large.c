#include <stdio.h>
#include <string.h>
#define PER_ITER 10

void mix(FILE *input1,FILE *input2,FILE *output)
{
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

void bubblesort(char array[PER_ITER][100],int numnames){
    for (int i = 1; i < numnames; i++)
    {
        if(strcmp(array[i],array[i-1])<0){
            char temp[100];
            strcpy(temp,array[i]);
            strcpy(array[i],array[i-1]);
            strcpy(array[i-1],temp);
        }
    }
    bubblesort(array,numnames-1);
}
int main(int argv,char *argc[]){
    if(argv!=3){
        printf("invalid format :)\n");
        return 0;
    }
    char array[PER_ITER][100];
    FILE *input = fopen(argc[1],"r");
    FILE *tempout[2]= {tmpfile(),tmpfile()};
    int file=0;
    int exit=0;
    while (exit!=1)
    {
        int count=0;
        FILE *temp = tmpfile();
        for (int i = 0; i < PER_ITER; i++)
        {
            if(fscanf(input,"%s",array[i])==EOF){
                exit=1;
                break;
            }
            count++;
        }
        bubblesort(array,count);
        for (int i = 0; i < count; i++)
        {
            fprintf(temp,"%s\n",array[i]);
        }
        mix(tempout[file],temp,tempout[(file+1)%2]);
        file=(file+1)%2;
    }
    fclose(input);
    FILE *out = fopen(argc[2],"w");
    char word[100];
    while(fscanf(tempout[file],"%s",word)!=EOF){
        fprintf(out,"%s\n",word);
    }
}