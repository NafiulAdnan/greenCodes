
#include<bits/stdc++.h>
using namespace std;
double sq(double a)
{
    return a*a;
}
int main()
{
    int t,cs=1;

    double a,b,c,d,h;

      scanf("%d",&t);
    while(t--)
    {
         scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

        h = sq(b) - sq((sq(b) -sq(d) + sq(a-c))/(2*(a-c)));

        h=sqrt(h);
        double area = h * (a+c)/2;

        printf("Case %d: %.10f\n",cs++,area);

    }
}
