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
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0)
#define MAX 1005

vector<int>v[MAX];


ll n,m,q,a,b,c,sum=0,cnt=0;
map<ll,bool>mp;
string s;
int match[MAX];
bool col[MAX];
int flag[MAX];
vector<int>newv[1005];
bool  dfs(int nd)
{
    int sz = newv[nd].size();
    for0(i,sz)
    {
        int u = newv[nd][i];
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
int BPM()
{
    memset(match,-1,sizeof(match));
    int cnt = 0;
    for1(i,n)
    {
        mem(col);
        if(flag[i]==1&& (dfs(i)))cnt++;
    }
    return cnt;
}
void store(int nd)
{
    int sz = v[nd].size();

    for(int i=0; i<sz; i++)
    {
        int x = v[nd][i];
        if(flag[x]!=-1)continue;
        if(flag[nd])flag[x]=0;
        else flag[x]=1;
        store(x);
    }
    return;
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
            v[b].pb(a);
        }
        memset(flag,-1,sizeof flag);
//        cout<<"asdf"<<endl;

        for1(i,n)
        {
            if(flag[i]==-1)
            {
                flag[i]=1;
                store(i);
            }
        }

        for1(i,n)
        {
            if(flag[i]==1)
            {
                for(int j=0; j<v[i].size(); j++)
                {
//                    cout<<v[i][j]<<" ";
                    newv[i].pb(v[i][j]);
                }
//                cout<<endl;
            }
        }


        cout<<"Case "<<cs++<<": "<<n-BPM()<<endl;

        for1(i,n)
        {
            newv[i].clear();
            v[i].clear();
        }
        mem(flag);
    }


}

