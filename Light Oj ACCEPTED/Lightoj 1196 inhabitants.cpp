#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define PI 3.14159265358979323846
struct point
{
    long long x,y;
    int id;
};

/*
ConvexHull : Graham's Scan O(n lg n), integer implementation
P[]: holds all the points, C[]: holds points on the hull
np: number of points in P[], nc: number of points in C[]
to handle duplicate, call makeUnique() before calling convexHull()
call convexHull() if you have np >= 3
to remove co-linear points on hull, call compress() after convexHull()
*/

point P[MAX], C[MAX], P0;

inline double triArea2(const point &a, const point &b, const point &c)
{
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline double sqDist(const point &a, const point &b)
{
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
inline double findAngleBetweenLine(point A,point B,point C)
{
    double a = sqrt((double)sqDist(A,B));
    double b = sqrt((double)sqDist(B,C));
    double c = sqrt((double)sqDist(C,A));

    return (acos((b*b - c*c - a*a)/(-2*a*c))*180)/PI;

}

inline bool comp(const point &a, const point &b)
{
    double d = triArea2(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}

inline bool normal(const point &a, const point &b)
{
    return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b)
{
    return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np)
{
    sort(&P[0], &P[np], normal);
    np = unique(&P[0], &P[np], issame) - P;
}

void convexHull(int &np, int &nc)
{
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    for(i = 0; i < 3; i++) C[i] = P[i];
    for(i = j = 3; i < np; i++)
    {
        while(triArea2(C[j-2], C[j-1], P[i]) < 0) j--;
        C[j++] = P[i];
    }
    nc = j;
}

void compress(int &nc)
{
    int i, j, d;
    C[nc] = C[0];
    for(i=j=1; i < nc; i++)
    {
        d = triArea2(C[j-1], C[i], C[i+1]);
        if(d || (!d && issame(C[j-1], C[i+1]))) C[j++] = C[i];
    }
    nc = j;
}


/*
C[] array of points of convex polygon in ccw order,
nc number of points in C, p target points.
returns true if p is inside C (including edge) or false otherwise.
complexity O(lg n)
*/

inline bool inConvexPoly(point *C, int nc, const point &p)
{
    int st = 1, en = nc - 1, mid;
    while(en - st > 1)
    {
        mid = (st + en) >> 1;
        if(triArea2(C[0], C[mid], p) < 0) en = mid;
        else st = mid;
    }
    if(triArea2(C[0], C[st], p) < 0) return false;
    if(triArea2(C[st], C[en], p) < 0) return false;
    if(triArea2(C[en], C[0], p) < 0) return false;
    return true;
}
/*
C[] holds the points, must be either in cw or ccw
function returns double of the area.
*/

inline double dArea(int nc)
{
    int area = 0;
    for(int i = 0; i < nc; i++)
    {
        //  area += C[i].xC[i+1].y - C[i].y*C[i+1].x;

        cout<<"using : "<<C[i].id<<"  ";

        cout<<C[i].x<<" "<<C[i].y<<endl;
        area += C[i].x*C[i+1].y - C[i].y*C[i+1].x;
    }
    return abs(area);
}

double findMinAngle(int nc)
{
    double mn = 20000.00;
    for(int i=1; i<nc-1; i++)
    {
        mn = min(mn, findAngleBetweenLine(C[i], C[i-1],C[i+1]));
    }
    mn = min(mn, findAngleBetweenLine(C[0],C[nc-1],C[1]));
    mn = min(mn, findAngleBetweenLine(C[nc-1],C[0],C[nc-2]));
    return mn;
}




int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,nc=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld%lld",&P[i].x,&P[i].y);
            P[i].id=i+1;
        }
        //   makeUnique(n);
        printf("Case %d:\n",cs++);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            point qry;
            scanf("%lld%lld",&qry.x,&qry.y);
            if(inConvexPoly(P,n,qry))printf("y\n");
            else printf("n\n");
        }
//        convexHull(n, nc);
//        compress(nc);
        // cout<<nc<<" ta point"<<endl;
        //  printf("%.10lf\n",findMinAngle(nc));
        //   cout<<setprecision(10)<<fixed<<findMinAngle(nc)<<endl;
        // int Area = dArea(nc);
        // cout<<Area<<endl;


    }
}



