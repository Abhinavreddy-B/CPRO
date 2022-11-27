#include <stdio.h>

int main()
{
    int N;
    int triplets = 0;
    scanf("%d", &N);
    for (int i = 0;i<=200; i++)
    {
        for (int j = i + 1;j<=200; j++)
        {
            for (int k = j + 1; k <= 200; k++)
            {
                if (i * i + j * j == k * k)
                {
                    printf("%d %d %d\n", i, j, k);
                    triplets++;
                    if (triplets == N)
                    {
                        return 0;
                    }
                    break;
                }
            }
        }
    }
}