#include<bits/stdc++.h>
using namespace std;
#define MAX 50005
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

inline long double  triArea2(const point &a, const point &b, const point &c)
{
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline long double  sqDist(const point &a, const point &b)
{
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
inline long double  findAngleBetweenLine(point A,point B,point C)
{
    long double  a = sqrt((long double )sqDist(A,B));
    long double  b = sqrt((long double )sqDist(B,C));
    long double  c = sqrt((long double )sqDist(C,A));

    return (acos((b*b - c*c - a*a)/(-2*a*c))*180)/PI;

}

inline bool comp(const point &a, const point &b)
{
    long double  d = triArea2(P0, a, b);
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
function returns long double  of the area.
*/

inline long double  dArea(int nc)
{
    int area = 0;
    for(int i = 0; i < nc; i++)
    {
        //  area += C[i].xC[i+1].y - C[i].y*C[i+1].x;

     //   cout<<"using : "<<C[i].id<<"  ";

      //  cout<<C[i].x<<" "<<C[i].y<<endl;
        area += C[i].x*C[i+1].y - C[i].y*C[i+1].x;
    }
    return abs(area);
}
long double  findPerimeterOfConvexHull(int nc)
{
    //C[nc] = C[0];
    long double  periMeter = 0;
  //  cout<<C[0].id<<" ttt "<<C[nc-1].id<<endl;
    if(C[0].id != C[nc].id)C[nc++]=C[0];

    //    cout<<C[0].id<<" "<<C[nc].id<<endl;

    for(int i=0; i<nc-1; i++)
    {
        periMeter += sqrt(sqDist(C[i],C[i+1]));
    }
    return periMeter;
}
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)

int main()
{
    int t,cs=1;
    FastRead;
    // scanf("%d",&t);
    cin>>t;
    while(t--)
    {
        long double  r;
        int n,nc=0;
//        scanf("%d",&n);
//                scanf("%Lf",&r);
//    printf("%Lf",r);
        cin>>n>>r;

        for(int i=0; i<n; i++)
        {
            cin>>P[i].x>>P[i].y;
            //  scanf("%lld%lld",&P[i].x,&P[i].y);
            P[i].id=i+1;
        }
        cout<<"Case "<<cs++<<": ";
//        printf("Case %d: ",cs++);
        long double  periArea=0.0;
        if(n==1)
        {
            periArea = 2*PI*r;
        }
        else if(n==2)
        {
            periArea= 2*PI*r + sqrt(sqDist(P[0],P[1]))*2;
        }
        else
        {
            convexHull(n, nc);
         ///   compress(nc);
            // cout<<nc<<" ta point"<<endl;
            periArea = findPerimeterOfConvexHull(nc);
            periArea += 2.00*PI*r;
        }
        cout<<setprecision(10)<<fixed<<periArea<<endl;
//        printf("%Lf\n",periArea);


    }
}


