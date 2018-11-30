#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll dp[65][65];
char s[65];
ll sol(int i, int j)
{
    ll &ret = dp[i][j];
    if(ret==-1)
    {
        if(i>j)return 0;
        if(i==j)return 1;
        ret = sol(i,j-1) + sol(i+1,j) - sol(i+1,j-1);
        if(s[i]==s[j])ret += sol(i+1,j-1)+1;

    }
    return ret;
}

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&s);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",cs++,sol(0, strlen(s))-1);
    }

}
