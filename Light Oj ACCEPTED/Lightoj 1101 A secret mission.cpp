#include<bits/stdc++.h>
using namespace std;
#define mx 50005
#define ll long long
#define pb push_back
#define mp make_pair
int n,m;

int level[mx],From[mx];
int Lca[mx][17];
int maxRoad[mx][17];
vector<int>v[mx];
vector<int>cost[mx];
int dist[mx];
int parent[mx];

int added;

struct edge
{
    int u,v,cost;
};
bool comp(edge A,edge B)
{
    return A.cost<B.cost;
}

vector<edge>E;

int Find(int x)
{
    if(parent[x]==x)return x;
    return parent[x]=Find(parent[x]);
}


void makeparent(int n)
{
    added=0;
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
        v[i].clear();
        cost[i].clear();
    }
}
void Kruskal(int nodes)
{
    sort(E.begin(),E.end(),comp);
    int sz= E.size();

    int ans=0,cnt=0;
    added=0;
    for(int i=0; i<sz && added<nodes-1 ; i++)
    {
        int a= Find(E[i].u), b= Find(E[i].v);
         //cout<<" a,b, c "<<a<<" "<<b<<" "<<E[i].cost<<endl;
        if(a!=b)
        {

            parent[b]=a;
            v[a].pb(b);
            v[b].pb(a);
            cost[a].pb(E[i].cost);
            cost[b].pb(E[i].cost);
            added++;

        }
    }

}



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
    maxRoad[1][0]=0;

    for(int i=2; i<=n; i++)
    {
        Lca[i][0]=From[i];
        maxRoad[i][0]=dist[i];
    }
    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(Lca[i][j-1]!=-1)
            {
                Lca[i][j]=Lca[Lca[i][j-1]][j-1];
                maxRoad[i][j]= max(maxRoad[i][j-1],maxRoad[Lca[i][j-1]][j-1]);
            }
        }
    }

    return;
}


int query(int p,int q)
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
            p = Lca[p][i];
        }
    }
    if(p==q)
    {
        return maxi;
    }
/// After making level same, find the lca.
    for(int i=log; i>=0; i--)
    {
        if(Lca[p][i]!=-1 && Lca[p][i]!=Lca[q][i])
        {
            maxi= max(maxi, max(maxRoad[p][i], maxRoad[q][i]));
            p=Lca[p][i],q=Lca[q][i];
        }
    }
    maxi = max(maxi, max(dist[p],dist[q]));

    return maxi;
}


int main()
{
    int t,cs=1,a,b;
    int c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            edge in;
            scanf("%d%d%d",&in.u,&in.v,&in.cost);
            E.pb(in);
        }
        makeparent(n);
        Kruskal(n);


        memset(level,-1,sizeof(level));
        dist[1]=0;
        dfs(1,1,0);

        init(n);
        printf("Case %d:\n",cs++);

        int q;
        scanf("%d",&q);

        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&a,&b);
            int x = query(a,b);
            printf("%d\n",x);
        }
        E.clear();

    }

}

