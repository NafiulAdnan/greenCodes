#include<bits/stdc++.h>
using namespace std;
struct my
{
    double a,b;
} arr[200005];
int n,d;
double temp[200005];
bool can(double val)
{
    for(int i=0; i<n; i++)
    {
        temp[i] = (double)arr[i].a - val* arr[i].b;
    }
    sort(temp,temp+n, greater<double>());
    double sum = accumulate(temp,temp+n-d,0.0);
    return sum>=0.0;
}
double give_me()
{
    double l = 0.0,r = 100.0;

    while(r-l>=0.000000001)
    {
        double mid = (r+l)/2.0;
        if(can(mid/100.0))l=mid;
        else r=mid;
    }
    return (l+r)/2.0;
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&arr[i].a,&arr[i].b);
        }
        double ans = give_me();

        printf("Case %d: %.10lf\n",cs++,ans);
        //  cout<<asum<<" "<<bsum<<" "<<;
        //    cout<<setprecision(10)<<fixed<<100*(asum/bsum)<<endl;
    }
}
