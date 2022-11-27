#include <stdio.h>

#define MOD 1000000007LL

typedef long long ll;

ll power(ll a,ll pow){
    ll ans=1;
    while(pow>0){
        if(pow%2==0){
            a = (a*a)%MOD;
            pow/=2;
        }else{
            ans=(ans*a)%MOD;
            pow--;
        }
    }
    return ans%MOD;
}

ll modulo_inv(ll a){
    return power(a,MOD-2);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ll array[n][m];
    ll answ[n][m];
    ll answ_inv[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &array[i][j]);
            array[i][j] = (array[i][j]+MOD)%MOD;
            if (i == 0 && j == 0)
            {
                answ[i][j] = array[i][j];
            }
            else if (i == 0)
            {
                answ[i][j] = (answ[i][j - 1] * (array[i][j] % MOD)) % MOD;
            }
            else if (j == 0)
            {
                answ[i][j] = (answ[i - 1][j] * (array[i][j] % MOD)) % MOD;
            }
            else
            {
                answ[i][j]=(answ[i][j-1])%MOD;
                ll temp= (answ[i-1][j] * (answ_inv[i-1][j-1]))%MOD;
                temp = (temp * array[i][j])%MOD;
                answ[i][j]= (answ[i][j] * temp)%MOD;
            }
            answ_inv[i][j]=modulo_inv(answ[i][j])%MOD;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int xs,ys,xe,ye;
        scanf("%d%d%d%d",&xs,&ys,&xe,&ye);
        if(xs==0&&ys==0){
            printf("%lld\n",answ[xe][ye]);
        }else if(ys==0){
            ll temp= answ[xe][ye];
            temp = (temp * answ_inv[xs-1][ye] )%MOD;
            printf("%lld\n",temp);
        }else if(xs==0){
            ll temp= answ[xe][ye];
            temp = (temp * answ_inv[xe][ys-1] )%MOD;
            printf("%lld\n",temp);
        }else{
            ll temp= answ[xe][ye];
            temp = (temp * answ_inv[xs-1][ye] )%MOD;
            temp = (temp * answ[xs-1][ys-1])%MOD;
            temp = (temp * answ_inv[xe][ys-1] )%MOD;
            printf("%lld\n",temp);
        }
    }
}