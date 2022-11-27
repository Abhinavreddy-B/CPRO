#include <stdio.h>

int main(int argv, char *argc[])
{
    int temp;
    int n = 0;
    int sqsum = 0;
    double mean;
    FILE *mean_file = fopen(argc[2], "r");
    fscanf(mean_file, "%lf", &mean);
    fclose(mean_file);
    FILE *input = fopen(argc[1], "r");
    double variance;
    while (fscanf(input, "%d", &temp) != EOF)
    {
        sqsum += temp * temp;
        n++;
    }
    variance = (double)sqsum / n;
    variance -= mean * mean;
    FILE *out = fopen(argc[3], "w");
    fprintf(out, "%lf", variance);
}