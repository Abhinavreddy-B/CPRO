#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        double det = b * b - 4 * a * c;
        if (det < 0)
        {
            if(b==0){
                b=-0.0;
            }
            printf("%.8lf %.8lf\n%.8lf %.8lf\n", (-b) / (2*a), sqrt(-det/4)/a, (-b) /(2*a), -sqrt(-det/4)/a);
        }
        else if (det == 0)
        {
            printf("%.8lf %.8lf\n%.8lf %.8lf\n",-b/(2*a),+0.0, -b/(2*a),+0.0);
        }
        else
        {
            printf("%.8lf %.8lf\n%.8lf %.8lf\n",((-b/2)+sqrt(det/4))/a,+0.0,((-b/2)-sqrt(det/4))/a,+0.0);
        }
    }
}