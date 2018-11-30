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

void artiPoint(int nd)
{
    visited[nd]=1;
    st++;
    start[nd] = low[nd] = st;

    for(int i=0; i< v[nd].size(); i++)
    {
        int u = v[nd][i];
        if(!visited[u])
        {
            artiPoint(u);
            if(nd==root)sub++;
            if(sub >= 2 )
            {
                artPoint[root]=1;
            }
            low[nd] = min(low[nd], low[u]);

            if(low[u] >= start[nd] && nd!= root)
            {
                artPoint[nd]=1;
            }
        }
        else
        {
            low[nd] =min(low[nd], start[u]);
        }
    }
}

void artiBridge(int nd,int par)
{
    visited[nd]=1;
    st++;
    start[nd] = low[nd] = st;
    for(int i=0; i< v[nd].size(); i++)
    {
        int u = v[nd][i];
        if(u==par)continue;
        if(!visited[u])
        {
            artiBridge(u,nd);
            low[nd] = min(low[nd], low[u]);
            if(low[u] > start[nd])
            {
                Bridges.push_back(make_pair(min(nd,u),max(nd,u)));
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
        cin>>n;
        allClear();
        for0(i,n)
        {
            cin>>a;
            cin>>ch>>num>>ch;
            for0(j,num)
            {
                cin>>b;
                v[a].pb(b);
            }
        }
        for0(i,n)
        {
            if(!visited[i])
            {
                artiBridge(i,-1);
            }
        }
       // for1(i,n)cout<<i<<" "<<start[i]<<" "<<low[i]<<" "<<artPoint[i]<<endl;

        cout<<"Case "<<cs++<<":"<<endl;
        cout<<Bridges.size()<<" critical links"<<endl;

        sort(Bridges.begin(),Bridges.end());

        for0(i,Bridges.size())
        {
            cout<<Bridges[i].first<<" - "<<Bridges[i].second<<endl;
        }
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



