#include <stdio.h>
typedef long long ll;

int solver(int n, ll arr[], int pos, int m, int minht, ll ans[][n + 1])
{
    if (pos == -1)
    {
        return 0;
    }
    else if (ans[pos][minht] != -1)
    {
        return ans[pos][minht];
    }
    else if (pos == m)
    {
        int way1 = 1 + solver(n, arr, pos - 1, m, m, ans);
        if (arr[m] < arr[minht])
        {
            ans[pos][minht] = way1;
            return way1;
        }
        else
        {
            int way2 = solver(n, arr, pos - 1, m, minht, ans);
            ans[pos][minht] = way1 > way2 ? way1 : way2;
            return ans[pos][minht];
        }
    }
    else
    {
        int way1 = solver(n, arr, pos - 1, m, minht, ans);
        if (arr[pos] <= arr[minht])
        {
            ans[pos][minht] = way1;
            return way1;
        }
        else
        {
            int way2 = 1 + solver(n, arr, pos - 1, m, pos, ans);
            ans[pos][minht] = way1 > way2 ? way1 : way2;
            return ans[pos][minht];
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ll array[n + 1];
    array[n] = 0;
    ll ans[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &array[i]);
        for (int j = 0; j < n + 1; j++)
        {
            ans[i][j] = -1;
        }
    }
    array[n] = 0;
    printf("%d", solver(n, array, n - 1, m - 1, n, ans));
}