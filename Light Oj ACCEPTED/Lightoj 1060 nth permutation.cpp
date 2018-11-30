#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define ll long long


ll n,m,x;
ll range[26];
void init()
{
    range[0]=0;
    range[1]=6;
    for(ll i=2;i<=25;i++)range[i] = range[i-1] *(ll)6;
}
ll dp[30][200];
ll solve(int pos, int sum)
{
    if(pos==n)
    {
        if(sum>=x)return 1;
        return 0;
    }

    ll &ret = dp[pos][sum];
    if(ret==-1)
    {
        ret = 0;

        for(int i=1;i<=6;i++)
        {
            ret += solve(pos+1, sum+i);
        }
    }
    return ret;
}
int main()
{
    FastRead;
    int t,cs=1;
    cin>>t;
    init();
    while(t--)
    {
        cin>>n>>x;
        memset(dp,-1,sizeof(dp));

        ll inRange = solve(0,0);
        ll rng = range[n];

        ll g = gcd(inRange,rng);

      //  cout<<inRange<<" "<<rng<<endl;
        inRange /= g;
        rng /= g;

        cout<<"Case "<<cs++<<": ";
        if(x==0)cout<<1<<endl;
        else
        if(inRange==0||rng==0)cout<<0<<endl;
        else
        if(inRange==1 && rng==1)cout<<1<<endl;
        else cout<<inRange<<"/"<<rng<<endl;


    }
}
