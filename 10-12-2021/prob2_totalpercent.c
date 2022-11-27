#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int temp;
    int summen = 0, sumfemale = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            if (temp == 0)
            {
                summen++;
            }
            else if (temp == 1)
            {
                sumfemale++;
            }
        }
    }
    printf("%.5lf %.5lf", (((double)summen) / (m * n)) * 100, (((double)sumfemale) / (m * n)) * 100);
}