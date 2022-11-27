#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);
    for (int z = 3;; z++)
    {
        for (int y = 2; y < z; y++)
        {
            for (int x = 1; x < y; x++)
            {
                if (x * x + y * y == z * z)
                {
                    printf("%d %d %d\n", x, y, z);
                    N--;
                }
                if (N == 0)
                {
                    goto exit;
                }
            }
        }
    }
exit:
    return 0;
}