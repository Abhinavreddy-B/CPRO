#include <stdio.h>

int main()
{
    int rows, cols;
    scanf("%d%d", &rows, &cols);
    long int matrix[rows][cols];
    long int vector[cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%ld", &matrix[i][j]);
        }
    }
    for (int i = 0; i < cols; i++)
    {
        scanf("%ld", &vector[i]);
    }
    for (int i = 0; i < rows; i++)
    {
        long long int temp = 0;
        for (int j = 0; j < cols; j++)
        {
            temp += matrix[i][j] * vector[j];
        }
        printf("%lld\n", temp);
    }
}