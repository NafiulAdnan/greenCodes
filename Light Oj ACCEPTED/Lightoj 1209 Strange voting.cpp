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
int p1,p2;
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
int BPM()
{
    memset(match,-1,sizeof(match));
    int cnt = 0;

    for0(i,p1)
    {
        mem(col);
        if(dfs(i))cnt++;
    }
    return cnt;
}
struct my
{
    int yes,no;
} male[505],fem[505];

int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    int all;
    while(t--)
    {
        mem(male);
        mem(fem);
        cin>>n>>m>>all;
        p1 = 0, p2 =0;
        char ch;
        for0(i,all)
        {
            cin>>ch>>a>>ch>>b;

            if(ch=='F')male[p1].yes=a,male[p1++].no=b;
            else fem[p2].yes=a,fem[p2++].no=b;

        }

        for0(i,p1)
        {
            for0(j,p2)
            {
                if(male[i].no==fem[j].yes || male[i].yes==fem[j].no)
                {
                    v[i].pb(j);
                }
            }
        }



        cout<<"Case "<<cs++<<": "<<all-BPM()<<endl;

        for0(i,p1)
        {
            v[i].clear();
        }
    }


}

