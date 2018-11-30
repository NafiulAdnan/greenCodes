///
#include<bits/stdc++.h>
using namespace std;
#define MX 10005
priority_queue<pair<int,int> >q;
vector<pair<int,int> > v[MX],revV[MX];
int dis[MX],secDis[MX];
int n,m,high,s,t;

void Dijkstra(int x)
{
    for(int i=1; i<=n; i++)dis[i]=1e9;
    dis[x]=0;
    q.push({0,x});
    while(!q.empty())
    {
        int a=q.top().second;
        q.pop();
        int len= v[a].size();
        for(int i=0; i<len; i++)
        {
            if(dis[a] + v[a][i].second < dis[v[a][i].first])
            {
                dis[v[a][i].first] = dis[a] + v[a][i].second;
                q.push({-dis[v[a][i].first], v[a][i].first } );
            }
        }
    }
}

void SecDijkstra(int x)
{
    for(int i=1; i<=n; i++)secDis[i]=1e9;
    secDis[x]=0;
    q.push({0,x});
    while(!q.empty())
    {
        int a=q.top().second;
        q.pop();
        int len= revV[a].size();
        for(int i=0; i<len; i++)
        {
            if(secDis[a] + revV[a][i].second < secDis[revV[a][i].first])
            {
                secDis[revV[a][i].first] = secDis[a] + revV[a][i].second;
                q.push({-secDis[revV[a][i].first], revV[a][i].first } );
            }
        }
    }
}
int main()
{
    int a,b,cst,tc,cs=1;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&high);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&cst);
            v[a].push_back(make_pair(b,cst));
            revV[b].push_back(make_pair(a,cst));
        }
        Dijkstra(s);
        SecDijkstra(t);

       int mx = -1;
       for(int i=1;i<=n;i++)
       {
           for(auto a:v[i])
           {
               cst = a.second+ dis[i]+secDis[a.first];
               if(cst<=high)mx=max(mx,a.second);
           }
       }
       printf("Case %d: %d\n",cs++,mx);

        for(int i=1; i<=n; i++)v[i].clear(),revV[i].clear();


    }
}

/*

5 6
2 3 2
3 4 6
2 1 5
1 5 1
5 4 2
1 4 9
*/


