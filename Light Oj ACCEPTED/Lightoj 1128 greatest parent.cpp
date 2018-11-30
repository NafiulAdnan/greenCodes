#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
ll From[mx];
ll Lca[mx][21];
ll cost[mx];
ll n,m;


void init(ll n)
{
    memset(Lca,-1,sizeof(Lca));
    for(int i=0; i<n; i++)
    {
        Lca[i][0]=From[i];
    }
    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(Lca[i][j-1]!=-1)
            {
                Lca[i][j]=Lca[Lca[i][j-1]][j-1];
            }
        }
    }

    return;
}


ll query(ll nd, ll c)
{
    ll lg = log2(n);
    for(int i=lg; i>=0; i--)
    {
        if(cost[Lca[nd][i]] >= c)
        {
            nd = Lca[nd][i];
        }
    }
    return nd;
}

int main()
{
    ll t,cs=1,a;
    ll b;
    scanf("%lld",&t);
    while(t--)
    {
         memset(cost,0,sizeof(cost));

        scanf("%lld%lld",&n,&m);
        From[0]=0;
        cost[0]=1;

        for(int i=1; i<n; i++)
        {
            scanf("%lld%lld",&a,&b);
            From[i]=a;
            cost[i]=b;
        }

        // dfs(0,0,0);
        init(n);
        printf("Case %lld:\n",cs++);

        for(int i=0; i<m; i++)
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",query(a,b));
        }
    }

}
/*

11 10
0 1
1 4
1 2
2 3
2 8
8 9
4 6
4 5
5 7
7 10

*/

