#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double array[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &array[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&array[i][n]);
    }
    
    double variables[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (array[k][i] == 0)
            {
                continue;
            }
            double temp = (array[k][i] / array[i][i]);
            for (int j = i; j < n + 1; j++)
            {
                array[k][j] -= ((temp)*array[i][j]);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        /*if (array[i][i] == 0)
        {
            printf("The equations are same\n");
            return 0;
        }*/
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += array[i][j] * variables[j];
        }
        variables[i] = (array[i][n] - sum) / array[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%.16lf\n", variables[i]);
    }
}