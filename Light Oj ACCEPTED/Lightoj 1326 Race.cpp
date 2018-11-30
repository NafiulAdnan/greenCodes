#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll nc[1002][1002];
ll dp[1005];
ll mod =10056;

ll ncr(int n, int k)
{
    if(k>n)return 0;
    if(k==1)return n;
    if(k==n)return 1;
    ll &ret = nc[n][k];

    if(ret==-1)
    {
        ret = ncr(n-1,k)%mod+ ncr(n-1,k-1)%mod;
        ret %= mod;
    }
    return ret%mod;

}

int main()
{
    memset(nc,-1,sizeof(nc));
    int t,cs=1,n;
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;

    for(int i = 3; i<=1000; i++)
    {
        dp[i]=0;
        for(int j=i; j>=1; j--)
        {
            dp[i] += ncr(i,j) * dp[i-j];
            dp[i]%=mod;
        }
    }

    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",cs++,dp[n]%mod);

    }
}
