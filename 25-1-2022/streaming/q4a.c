#include <stdio.h>

int main(int argv, char *argc[])
{
    double temp;
    int n = 0;
    long double sum = 0;
    FILE *input = fopen(argc[1], "r");
    FILE *output = fopen(argc[2],"w");
    while (fscanf(input, "%lf", &temp) != EOF)
    {
        sum += temp;
        n++;
    }
    fprintf(output,"%lf", (double)sum / n);
}