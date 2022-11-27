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
    }
    int maxmennum = 1, maxmen = men[0], maxfemalenum = 1, maxfemale = female[0];
    for (int i = 0; i < n; i++)
    {
        if (maxmen < men[i])
        {
            maxmen = men[i];
            maxmennum = i + 1;
        }
        if (maxfemale < female[i])
        {
            maxfemale = female[i];
            maxfemalenum = i + 1;
        }
    }
    if (maxmen == 0){
        printf("-1 ");
    }else{
        printf("%d ", maxmennum);
    }
    if (maxfemale == 0){
        printf("-1");
    }else{
        printf("%d", maxfemalenum);
    }
}