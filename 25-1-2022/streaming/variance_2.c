#include <stdio.h>

//#define met1  //define this to find variance using Σ(x-x̄)^2/n here x̄ is mean upto that point
#define met2    //define this to find variance using (Σx^2)/n - (x̄)^2 here x̄ is mean upto that point
//pls dont define both at same time 

int main(int argv,char *argc[])   // use ./a.out <datafile>
{
    FILE *input = fopen(argc[1], "r");
    int temp;
    double n = 0;
    int sum = 0;
    int sqsum = 0;
    int sqsum_2 = 0;
    while (fscanf(input, "%d", &temp) != EOF)
    {
        sum += temp;
        n++;
#ifdef met1
        sqsum += (temp - (sum) / n) * (temp - (sum) / n);
        double variance = sqsum / n;
        printf("%lf\n", variance);
#endif

#ifdef met2
        sqsum_2 += temp * temp;
        double variance_2 = sqsum_2 / n;
        variance_2 -= (sum / n) * (sum / n);
        printf("%lf\n", variance_2);
#endif
        // fprintf(output,"%lf\n",variance);
    }
    // printf("final - %lf\n",variance);
    // fprintf(output,"final\t%lf",variance);
}