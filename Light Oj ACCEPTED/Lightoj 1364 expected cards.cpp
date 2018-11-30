#include<bits/stdc++.h>
using namespace std;
int nda,ndb,ndc,ndd;
//#define double long double
double dp[16][16][16][16][3][3][3][3];

double ans_me(int a,int b,int c,int d,int ea,int eb,int ec,int ed)
{
//    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<joker<<" "<<ea<<" "<<eb<<" "<<ec<<" "<<ed<<endl;
    if(a+ea>=nda && b+eb>=ndb && c+ec>=ndc && d+ed>=ndd)return 0.00;
    if(a+ea+b+eb+c+ec+d+ed == 54)return 100000.000;
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<joker<<" "<<ea<<" "<<eb<<" "<<ec<<" "<<ed<<endl;

//   if(a+b+c+d+joker == 54)return 0;
//    if(a+b+c+d==0)return 1;
    double total  = 54 -a-b-c-d-(ea+eb+ec+ed);

    double &ret = dp[a][b][c][d][ea][eb][ec][ed];
    if(ret!=-1)return ret;
    ret = 0.00;
    if(a<13)
    {
        double pa = 13-a;
        ret += (pa/total) *(1+ ans_me(a+1,b,c,d,ea,eb,ec,ed));
    }
    if(b<13)
    {
        double pa = 13-b;
        ret += (pa/total) * (1+ans_me(a,b+1,c,d,ea,eb,ec,ed));
    }
    if(c<13)
    {
        double pa = 13-c;
        ret += (pa/total) * (1+ans_me(a,b,c+1,d,ea,eb,ec,ed));
    }
    if(d<13)
    {
        double pa = 13-d;
        ret += (pa/total) * (1+ans_me(a,b,c,d+1,ea,eb,ec,ed));
    }
    if(ea+eb+ec+ed<2)
    {
        double mn = 100;
        double pa = 2-(ea+eb+ec+ed);
        if(a+ea<nda)
        {
            mn = min(mn,(pa/total) * (1+ans_me(a,b,c,d,ea+1,eb,ec,ed)));
        }
        if(b+eb<ndb)
        {
            mn = min(mn,(pa/total) * ( 1+ans_me(a,b,c,d,ea,eb+1,ec,ed)));
        }
        if(c+ec<ndc)
        {
            mn = min(mn,(pa/total) * (1+ans_me(a,b,c,d,ea,eb,ec+1,ed)));
        }
        if(d+ed<ndd)
        {
            mn =  min(mn,(pa/total) * ( 1+ ans_me(a,b,c,d,ea,eb,ec,ed+1)));
        }
        ret += mn;
        //ret += mn;
        // ret +=  (pa/total) * mn;
    }
    return ret;

}

/*
double ans_me_ulta(int a,int b,int c,int d, int joker)
{
    if(a==0 && b==0 && c==0 && d==0)return 0.00;
//   if(a+b+c+d+joker == 54)return 0;
//    if(a+b+c+d==0)return 1;
    double total  = nda - a + ndb - b + ndc - c + ndd -d + 2- joker;

    double ret = dp[a][b][c][d][joker];
    if(ret!=-1)return ret;
    ret = 0.00;
    if(a>13)
    {
        double pa = 13-a;
        ret += (pa/total) *(1+ ans_me(a+1,b,c,d,joker));
    }
    if(b<13)
    {
        double pa = 13-b;
        ret += (pa/total) * (1+ans_me(a,b+1,c,d,joker));
    }
    if(c<13)
    {
        double pa = 13-c;
        ret += (pa/total) * (1+ans_me(a,b,c+1,d,joker));
    }
    if(d<13)
    {
        double pa = 13-d;
        ret += (pa/total) * (1+ans_me(a,b,c,d+1,joker));
    }
    if(joker<2)
    {
        double mn = 100;
        double pa = 2-joker;
        if(a<nda)
        {
            mn = min(mn,(pa/total) * (1+ ans_me(a+1,b,c,d,joker+1)));
        }
        if(b<ndb)
        {
            mn = min(mn,(pa/total) * ( 1+ans_me(a,b+1,c,d,joker+1)));
        }
        if(c<ndc)
        {
            mn = min(mn,(pa/total) * (1+ans_me(a,b,c+1,d,joker+1)));
        }
        if(d<ndd)
        {
            mn =  min(mn,(pa/total) * ( 1+ ans_me(a,b,c,d+1,joker+1)));
        }
        ret += mn;
        //ret += mn;
       // ret +=  (pa/total) * mn;
    }
    return dp[a][b][c][d][joker] = ret;

}*/
#define F(i,n) for(int i=0;i<=n;i++)
void init()
{
    F(i,15)F(j,15)F(k,15)F(l,15)F(m,2)F(x,2)F(y,2)F(z,2) dp[i][j][k][l][m][x][y][z] = -1.00;
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        init();

        scanf("%d%d%d%d",&nda,&ndb,&ndc,&ndd);
        int ex = max(0,nda-13)+max(0,ndb-13)+max(0,ndc-13)+max(0,ndd-13);
        printf("Case %d: ",cs++);

        if(ex>2 || nda >15 || ndb > 15 || ndc > 15 || ndd>15 || (nda+ndb+ndc+ndd>54))printf("-1\n");
        else
        {
            double ans = ans_me(0,0,0,0,0,0,0,0);
            if(ans==0)printf("0\n");
            else cout<<setprecision(10)<<fixed<<ans<<endl;
        }
    }
}

