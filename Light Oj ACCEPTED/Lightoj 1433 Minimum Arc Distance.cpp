#include<bits/stdc++.h>

using namespace std;
#include<math.h>
double sq(double a)
{
    return a*a;
}

double dist(int ax,int ay, int bx,int by)
{
    return sqrt((double)(sq(ax-bx) + sq(ay-by)));
}
int main()
{
    int t,cs=1;

    scanf("%d",&t);

    while(t--)
    {
        int ax,ay,bx,by,ox,oy;

        scanf("%d %d %d %d %d %d",&ox,&oy, &ax, &ay, &bx, &by);

        double r = dist(ox,oy,ax,ay);
        double c = dist(ax,ay,bx,by);


        /// alpha= acos ( b*b + c*c - a*a )/(2*b*c)


        double alpha = acos(( sq(r) + sq(r) - sq(c))/(2.00*r*r));


        double ans = alpha * r;
        printf("Case %d: %.9f\n",cs++,ans);


    }
}
