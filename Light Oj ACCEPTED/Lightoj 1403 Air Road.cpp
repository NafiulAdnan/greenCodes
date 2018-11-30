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

#define MAX 1005

vector<int>v[MAX];


ll n,m,q,a,b,c,sum=0,cnt=0;

int match[MAX];
bool col[MAX];
bool  dfs(int nd)
{
    int sz = v[nd].size();
    for0(i,sz)
    {
        int u = v[nd][i];
        if(!col[u])
        {
            col[u]=1;
            if(match[u]==-1 || dfs(match[u]))
            {
                match[u]=nd;
                return true;
            }

        }
    }
    return false;
}
int BPM(int nd)
{
    memset(match,-1,sizeof(match));
    int cnt = 0;

    for1(i,n)
    {
        mem(col);
        if(dfs(i))cnt++;
    }
    return cnt;
}
int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for0(i,m)
        {
            cin>>a>>b;
            v[a].pb(b);

        }
        cout<<"Case "<<cs++<<": "<<n-BPM(n)<<endl;

        for1(i,n)
        {
            v[i].clear();
        }
    }


}

