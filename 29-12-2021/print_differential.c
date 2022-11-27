#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int array[n];
    int front_leading = n-1;
    //int back_leading = 0;
    //int zeroes = 0, leading = n+1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        /*if (array[i] == 0)
        {
            zeroes++;
        }*/
        /*if (array[i] == 0 && back_leading == i - 1)
        {
            back_leading++;
        }*/
    }
    for (int i = 0; i < n-1 ; i++)
    {
        array[i]=(i+1)*array[i+1];
    }
    
    n--;
    if (n <= 0)
    {
        printf("0");
        return 0;
    }
    if (n == 1)
    {
        printf("%d", array[0]);
        return 0;
    }
    if (n == 2)
    {
        if (array[1] == 0 && array[0] == 0)
        {
            printf("0");
            return 0;
        }
        else if (array[1] == 0 && array[0] != 0)
        {
            printf("%d", array[0]);
            return 0;
        }
        else
        {
            if (array[1] == 1)
            {
                printf("x ");
            }
            else if (array[1] == -1)
            {
                printf("-x ");
            }
            else
            {
                printf("%dx ", array[1]);
            }
            if(array[0]!=0){
                if(array[0]>0){
                    printf("+ %d",array[0]);
                }else{
                    printf("- %d",-array[0]);
                }
            }
            return 0;
        }
    }
    //leading--;
    /*if (back_leading == n - 1)
    {
        printf("0\n");
        return 0;
    }*/
    if (array[n - 1] == 1)
    {
        printf("x^%d ", n - 1);
    }
    else if (array[n - 1] == -1)
    {
        printf("-x^%d ", n - 1);
    }
    else if (array[n - 1] != 0)
    {
        printf("%dx^%d ", array[n - 1], n - 1);
    }
    else if (array[n - 1] == 0)
    {
        front_leading--;
    }

    for (int i = n - 2; i > 1; i--)
    {
        if (front_leading != i + 1)
        {
            if (array[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else if (array[i] == -1)
            {
                printf("- x^%d ", i);
            }
            else if (array[i] > 0)
            {
                printf("+ %dx^%d ", array[i], i);
            }
            else if (array[i] < 0)
            {
                printf("- %dx^%d ", -array[i], i);
            }
        }
        else if (front_leading == i + 1 && array[i] == 0)
        {
            front_leading--;
        }
        else
        {
            if (array[i] == 1)
            {
                printf("x^%d ", i);
            }
            else if (array[i] == -1)
            {
                printf("-x^%d ", i);
            }
            else
            {
                printf("%dx^%d ", array[i], i);
            }
        }
    }
    if (front_leading != 2)
    {
        if (array[1] == 1)
        {
            printf("+ x ");
        }
        else if (array[1] == -1)
        {
            printf("- x ");
        }
        else if (array[1] > 0)
        {
            printf("+ %dx ", array[1]);
        }
        else if (array[1] < 0)
        {
            printf("- %dx ", -array[1]);
        }
    }
    else if (front_leading == 2 && array[1] == 0)
    {
        front_leading--;
    }
    else
    {
        if (array[1] == 1)
        {
            printf("x ");
        }
        else if (array[1] == -1)
        {
            printf("-x ");
        }
        else
        {
            printf("%dx ", array[1]);
        }
    }
    if (front_leading == 1)
    {
        if (array[0] == 0)
        {
            printf("0");
        }
        else if (array[0] == 1)
        {
            printf("1");
        }
        else if (array[0] == -1)
        {
            printf("-1");
        }
        else
        {
            printf("%d", array[0]);
        }
    }
    else if (array[0] == 1)
    {
        printf("+ 1");
    }
    else if (array[0] == -1)
    {
        printf("- 1");
    }
    else if (array[0] > 0)
    {
        printf("+ %d", array[0]);
    }
    else if (array[0] < 0)
    {
        printf("- %d", -array[0]);
    }
    printf("\n");
}