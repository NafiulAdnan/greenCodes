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

vector<int> v[10005];
int start[10005], st,n;
bool visited[10005];
int low[10005];
int root;
bool artPoint[10005];
int sub=0;

void articulation(int nd)
{
    visited[nd]=1;
    st++;
    start[nd] = low[nd] = st;

    for(int i=0; i< v[nd].size(); i++)
    {
        int u = v[nd][i];
        if(!visited[u])
        {
            articulation(u);
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
void allClear()
{
   for (int i=1;i<=10005;i++)
    {
        v[i].clear();
        visited[i]=0;
        start[i]=0;
        low[i]=0;
        artPoint[i]=0;
    }
    sub = 0, st = 0, root = 1;
}

int main()
{
    int n,cs=1,a,b,m,t;
    FastRead;
    cin>>t;
    while(t--)
    {
         cin>>n>>m;
        allClear();



        for0(i,m)
        {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
       // cout<<artPoint[1]<<" "<<visited[1]<<" "<<low[1]<<" "<<start[1]<<endl;
     //   artPoint[1]=0,visited[1]=0,low[1]=0,start[1]=0;
        articulation(1);

        int ans = 0;
        for1(i,n)
        {
            if(artPoint[i])
            {
          //     cout<<i<<" ";

                ans++;
            }
        }
      //  cout<<endl;

        cout<<"Case "<<cs++<<": "<<ans<<endl;


    }
}
