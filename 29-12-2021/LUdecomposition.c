#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double array[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &array[i][j]);
        }
    }
    if (n == 0)
    {
        printf("No LU decomposition\n");
        return 0;
    }
    double L[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            L[i][j] = 0;
        }
    }
    L[n - 1][n - 1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        L[i][i] = 1;
        for (int k = i + 1; k < n; k++)
        {
            double temp = (array[k][i] / array[i][i]);
            L[k][i] = temp;
            for (int j = i; j < n + 1; j++)
            {
                array[k][j] -= ((temp)*array[i][j]);
            }
            array[k][i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i][i] == 0)
        {
            printf("No LU decomposition\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (L[i][j] == 0)
            {
                L[i][j] = 0;
            }
            printf("%.5lf ", L[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] == 0)
            {
                array[i][j] = 0;
            }
            printf("%.5lf ", array[i][j]);
        }
        printf("\n");
    }
}