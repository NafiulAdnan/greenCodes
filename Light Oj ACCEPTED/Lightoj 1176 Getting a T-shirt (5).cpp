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

#define MAX 500

vector<int>v[MAX];


ll n,m,q,a,b,c,sum=0,cnt=0;
ll arr[1000055];
map<string,int>mp;

string s;
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

    for1(i,m)
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

            mp["XL"]=1;
            mp["L"]=n+1;
            mp["XXL"]=2*n+1;
            mp["S"]=3*n+1;
            mp["XS"]=4*n+1;
            mp["M"]=5*n+1;



        string s,d;
        for1(i,m)
        {
            cin>>s>>d;

            for(int j=mp[s]; j<mp[s]+n; j++)
            {
                v[i].pb(j);
            }
            for(int j=mp[d]; j<mp[d]+n; j++)
            {
                v[i].pb(j);
            }
        }

        cout<<"Case "<<cs++<<": "<<(BPM(m)==m? "YES":"NO")<<endl;

        for1(i,m)
        {
            v[i].clear();
        }
    }


}

