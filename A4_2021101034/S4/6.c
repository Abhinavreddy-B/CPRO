#include <stdio.h>

int main(int argv, char *argc[])
{
    long long int array[62] = {};
    for (int i = 2; i <= argv - 1; i++)
    {
        FILE *input = fopen(argc[i], "r");
        char temp;
        while (fscanf(input, "%c", &temp) != EOF)
        {
            if (temp >= '0' && temp <= '9')
            {
                array[temp - '0']++;
            }
            else if (temp >= 'A' && temp <= 'Z')
            {
                array[temp - 'A' + 10]++;
            }
            else if (temp >= 'a' && temp <= 'z')
            {
                array[temp - 'a' + 36]++;
            }
        }
        fclose(input);
    }
    FILE *out = fopen(argc[1],"w");
    for (int i = 0; i < 62; i++)
    {
        if (i >= 0 && i <= 9)
        {
            fprintf(out,"%c:%lld\n",i+'0',array[i]);
        }
        else if (i >= 10 && i <= 35)
        {
            fprintf(out,"%c:%lld\n",i+'A'-10,array[i]);
        }
        else if (i >= 36 && i <= 61)
        {
            fprintf(out,"%c:%lld\n",i+'a'-36,array[i]);
        }
    }
}