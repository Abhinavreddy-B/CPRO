#include <stdio.h>
#include <math.h>
typedef long long ll;
int main()
{
    ll n, k;
    ll minutes = 0;
    ll buff = 0;
    scanf("%lld%lld", &n, &k);
    if(k==0){
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        ll temp;
        scanf("%lld", &temp);
        buff += temp;
        if (buff <= 8)
        {
            k -= buff;
            buff = 0;
        }
        else
        {
            k -= 8;
            buff -= 8;
        }
        minutes++;
        if (k <= 0)
        {
            printf("%lld\n", minutes);
            return 0;
        }
    }
        printf("-1\n");
}
    /*if (k <= 0)
    {
        printf("%lld\n", minutes);
        return 0;
    }*/
    /*if (buff >= k)
    {
        minutes += k / 8;
        if (k % 8 != 0)
        {
            minutes++;
        }
        printf("%lld\n", minutes);
        return 0;
        while (k > 0)
        {
            k -= 8;
            minutes++;
        }
        printf("%lld\n", minutes);
    }
    else
    {*/
   // }

/*if(buff>k){
                minutes+=k/8;
                if(k%8!=0){
                    minutes++;
                }
                printf("%lld\n",minutes);
                return 0;
            }else{
                k-=8*(buff/8);
                minutes+=buff/8;
                buff=buff%8;
            }*/