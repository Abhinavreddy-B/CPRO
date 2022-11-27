#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int coeff[n];
    int diff[n - 1];
    int countele = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coeff[i]);
        if (coeff[i] == 0 && i >= 1)
        {
            countele++;
        }
    }

    if (countele == n - 1)
    {
        printf("0\n");
        return 0;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        diff[i] = coeff[i + 1] * (i + 1);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (i == n - 2 && diff[n - 2] < 0)
        {
            printf("-");
        }

        if ((diff[i] > 1 || diff[i] < -1) && i >= (2))
        {
            printf("%dx^%d", abs(diff[i]), i);
        }
        if ((abs(diff[i]) == 1) && i >= (2))
        {
            printf("x^%d", i);
        }
        if ((diff[i] > 1 || diff[i] < -1) && i == (1))
        {
            printf("%dx", abs(diff[i]));
        }
        if ((abs(diff[i]) == 1) && i == (1))
        {
            printf("x");
        }

        if (i == (0) && diff[i] != 0)
        {
            printf("%d", abs(diff[i]));
        }

        int count = 0;
        if (diff[i] != 0)
        {
            for (int h = i - 1; h >= 0; h--)
            {
                if (diff[h] == 0)
                {

                    count++;
                    continue;
                }
                else if (diff[h] < 0)
                {
                    printf(" - ");
                    break;
                }
                else if (diff[h] > 0)
                {
                    printf(" + ");
                    break;
                }
            }
        }

        if (count == i)
        {
            break;
        }
    }
    printf("\n");
    return 0;
}