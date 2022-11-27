#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int temp;
    int men[n], female[n];
    for (int i = 0; i < n; i++)
    {
        men[i] = 0;
        female[i] = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            if (temp == 0)
            {
                men[i]++;
            }
            else if (temp == 1)
            {
                female[i]++;
            }
        }
        printf("%.5lf %.5lf\n",(((double)men[i]) / (m)) * 100, (((double)female[i]) / (m)) * 100);
    }
}