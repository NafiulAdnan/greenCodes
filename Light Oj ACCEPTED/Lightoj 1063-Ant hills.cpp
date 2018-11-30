/// AC ant hills LOJ

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mem(n) memset(n,0,sizeof(n))
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define for0(l,n) for(int l=0;l<n;l++)
#define for1(l,n) for(int l=1;l<=n;l++)
#define bug(n) cout<<">> "<<n<<" <<";
#define pb push_back
#define squerit(n) (ll)n*n
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define MX 10005

vector<int> v[MX];
int start[MX], st,n;
bool visited[MX];
int low[MX];
int root;
bool artPoint[MX];
int sub=0;
vector< pair<int,int> > Bridges;
vector<int>artPoints;
void artiBridgePoint(int nd,int par)
{
    visited[nd]=1;
    st++;
    start[nd] = low[nd] = st;
    for(int i=0; i< v[nd].size(); i++)
    {
        int u = v[nd][i];
        if(!visited[u])
        {
            artiBridgePoint(u,nd);
            if(nd==root)sub++;
            if(sub >= 2 )
            {
                if(!artPoint[root])artPoints.pb(root);
                artPoint[root]=1;
            }
            low[nd] = min(low[nd], low[u]);
            if(low[u] > start[nd])
            {
                Bridges.push_back(make_pair(min(nd,u),max(nd,u)));
            }
             if(low[u] >= start[nd] && nd!= root)
            {
                if(!artPoint[nd])artPoints.pb(nd);
                artPoint[nd]=1;
            }
        }
        else
        {
            low[nd] =min(low[nd], start[u]);
        }
    }
}
void allClear()
{
    for (int i=0; i<=MX; i++)
    {
        v[i].clear();
        visited[i]=0;
        start[i]=0;
        low[i]=0;
        artPoint[i]=0;
    }
    Bridges.clear();
    sub = 0, st = 0, root = 0;
}
int main()
{
    int n,cs=1,a,b,m,t,num;
    char ch;

    FastRead;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        allClear();
        for0(i,m)
        {
            cin>>a;
            {
                cin>>b;
                v[a].pb(b);
                v[b].pb(a);
            }
        }
        for1(i,n)
        {
            if(!visited[i])
            {
                sub=0;
                root = i;
                artiBridgePoint(i,-1);
            }
        }
        cout<<"Case "<<cs++<<": ";

        cout<<artPoints.size()<<endl;
        artPoints.clear();
        Bridges.clear();

    }
}

/*

5 5
1 2
2 3
3 4
2 4
3 5


*/





