#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
#define pb push_back
int n,m;

int level[mx],From[mx];
int Lca[mx][20];
int minRoad[mx][20];
int maxRoad[mx][20];
vector<int>v[mx];
vector<int>cost[mx];
int dist[mx];


void dfs(int now,int prev,int dep)
{
    level[now]=dep;
    From[now]=prev;
    int sz=v[now].size();
    for(int i=0; i<sz; i++)
    {
        int to=v[now][i];
        if(to==prev)continue;

        dist[to]=cost[now][i];

        dfs(to,now,dep+1);
    }
    return;
}

void init(int n)
{
    memset(Lca,-1,sizeof(Lca));

    Lca[1][0]=From[1];
    minRoad[1][0]=INT_MAX;
    maxRoad[1][0]=0;

    for(int i=2; i<=n; i++)
    {
        Lca[i][0]=From[i];
        minRoad[i][0]=dist[i];
        maxRoad[i][0]=dist[i];
    }
    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(Lca[i][j-1]!=-1)
            {
                Lca[i][j]=Lca[Lca[i][j-1]][j-1];
                minRoad[i][j]= min(minRoad[i][j-1],minRoad[Lca[i][j-1]][j-1]);
                maxRoad[i][j]= max(maxRoad[i][j-1],maxRoad[Lca[i][j-1]][j-1]);
            }
        }
    }

    return;
}



pair<int,int> query(int p,int q)
{

    if(level[p]<level[q])
    {
        swap(p,q);
    }
/// making the level same!
    int log = log2(level[p]);
    int maxi = 0,mini = INT_MAX;

    for(int i= log; i>=0; i--)
    {
        if(level[p]-(1<<i) >= level[q])
        {
            maxi = max(maxi, maxRoad[p][i]);
            mini = min(mini, minRoad[p][i]);
            p = Lca[p][i];
        }
    }

    if(p==q)
    {
                return make_pair(mini,maxi);
    }
/// After making level same, find the lca.

    for(int i=log; i>=0; i--)
    {
        if(Lca[p][i]!=-1 && Lca[p][i]!=Lca[q][i])
        {
            maxi= max(maxi, max(maxRoad[p][i], maxRoad[q][i]));
            mini= min(mini, min(minRoad[p][i], minRoad[q][i]));
            p=Lca[p][i],q=Lca[q][i];
        }
    }
    maxi = max(maxi, max(dist[p],dist[q]));
    mini = min(mini, min(dist[p],dist[q]));

    return make_pair(mini,maxi);
}


int main()
{
    int t,cs=1,a,b;
    int c;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);

        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            v[a].pb(b);
            v[b].pb(a);
            cost[a].pb(c);
            cost[b].pb(c);
        }
        dist[1]=0;
        dfs(1,1,0);

        init(n);
        printf("Case %d:\n",cs++);


        scanf("%d",&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            pair<int,int>x = query(a,b);
            printf("%d %d\n",x.first,x.second);
        }

        for(int i=0; i<=n; i++)
        {
            v[i].clear();
            cost[i].clear();
        }
    }

}
