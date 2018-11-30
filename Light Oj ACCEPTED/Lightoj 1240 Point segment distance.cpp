#include<bits/stdc++.h>
using namespace std;
#define eps .000000001
struct Point
{
    double x,y,z;
}S;
struct Line
{
    Point a,b;
} F;

double sqdist(Point p1,Point p2=S)
{
    return ((p1.x-p2.x)*(p1.x-p2.x) + (p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
}
double getDist_time(double time)
{
    Point p1;

    p1.x = F.a.x + (F.b.x-F.a.x)*time;
    p1.y = F.a.y + (F.b.y-F.a.y)*time;
    p1.z = F.a.z + (F.b.z-F.a.z)*time;

    return sqdist(p1);
}

double ternery()
{
    double l = 0.0, h = 1.0;
    double ans = 1E18;
    while(h-l>eps)
    {
        double tf = l + (h-l)/3.0;
        double ts = l+ 2*((h-l)/3.0);
        double get1 = getDist_time(tf);
        double get2 = getDist_time(ts);
        if(get1 < get2)
        {
            h = ts;
        }
        else l = tf;
        ans = min(ans, min(get1,get2));
    }
    return sqrt(ans);

}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&F.a.x,&F.a.y,&F.a.z);
        scanf("%lf%lf%lf",&F.b.x,&F.b.y,&F.b.z);
        scanf("%lf%lf%lf",&S.x,&S.y,&S.z);


        double ans = ternery();
        printf("Case %d: %.8lf\n",cs++,ans);

    }
}

